#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_NAME_LENGTH 100
#define TASKS_FILE "tasks.dat"

/* Task Type Enumeration */
typedef enum {
    COLLEGE = 1,
    UPSKILL,
    LEISURE,
    PERSONAL,
    WORK
} TaskType;

/* Task Structure */
typedef struct Task {
    int id;
    char name[MAX_NAME_LENGTH];
    int deadline;
    TaskType type;
    int dependency_id;
    float priority_score;
    int completed;
    struct Task* next;
} Task;

/* Global Variables */
Task* task_list = NULL;
int task_count = 0;
int next_id = 1;

/* GTK Widgets */
GtkWidget *window;
GtkWidget *task_view;
GtkListStore *task_store;
GtkWidget *name_entry;
GtkWidget *deadline_entry;
GtkWidget *type_combo;
GtkWidget *dependency_combo;
GtkWidget *status_label;

/* Function Prototypes */
void init_task_view(GtkWidget *scrolled_window);
void refresh_task_display();
void refresh_dependency_combo();
void on_add_task_clicked(GtkWidget *widget, gpointer data);
void on_complete_task_clicked(GtkWidget *widget, gpointer data);
void on_delete_task_clicked(GtkWidget *widget, gpointer data);
float calculatePriority(Task* task);
Task* findTaskById(int id);
void saveTasks();
void loadTasks();
const char* getTypeName(TaskType type);
int getTypeWeight(TaskType type);
void get_priority_color(float priority, GdkRGBA *color);

/* Main Function */
int main(int argc, char *argv[]) {
    GtkWidget *main_box;
    GtkWidget *top_box;
    GtkWidget *form_box;
    GtkWidget *button_box;
    GtkWidget *scrolled_window;
    GtkWidget *label;
    GtkWidget *add_button;
    GtkWidget *complete_button;
    GtkWidget *delete_button;
    
    gtk_init(&argc, &argv);
    
    /* Load existing tasks */
    loadTasks();
    
    /* Create main window */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "PrioQ");
    gtk_window_set_default_size(GTK_WINDOW(window), 900, 600);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    /* Main vertical box */
    main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), main_box);
    
    /* Title label */
    label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(label), 
        "<span font='16' weight='bold'>PrioQ - Automatic Priority Sorting</span>");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 5);
    
    /* Task list view */
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                    GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(main_box), scrolled_window, TRUE, TRUE, 0);
    
    init_task_view(scrolled_window);
    
    /* Form section */
    form_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_pack_start(GTK_BOX(main_box), form_box, FALSE, FALSE, 5);
    
    /* Task name entry */
    label = gtk_label_new("Task Name:");
    gtk_box_pack_start(GTK_BOX(form_box), label, FALSE, FALSE, 0);
    
    name_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(name_entry), "Enter task name...");
    gtk_box_pack_start(GTK_BOX(form_box), name_entry, TRUE, TRUE, 0);
    
    /* Deadline entry */
    label = gtk_label_new("Deadline (days):");
    gtk_box_pack_start(GTK_BOX(form_box), label, FALSE, FALSE, 0);
    
    deadline_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(deadline_entry), "Days");
    gtk_entry_set_width_chars(GTK_ENTRY(deadline_entry), 5);
    gtk_box_pack_start(GTK_BOX(form_box), deadline_entry, FALSE, FALSE, 0);
    
    /* Type combo box */
    label = gtk_label_new("Type:");
    gtk_box_pack_start(GTK_BOX(form_box), label, FALSE, FALSE, 0);
    
    type_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(type_combo), "College");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(type_combo), "Upskill");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(type_combo), "Leisure");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(type_combo), "Personal");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(type_combo), "Work");
    gtk_combo_box_set_active(GTK_COMBO_BOX(type_combo), 0);
    gtk_box_pack_start(GTK_BOX(form_box), type_combo, FALSE, FALSE, 0);
    
    /* Dependency combo box */
    label = gtk_label_new("Depends on:");
    gtk_box_pack_start(GTK_BOX(form_box), label, FALSE, FALSE, 0);
    
    dependency_combo = gtk_combo_box_text_new();
    refresh_dependency_combo();
    gtk_box_pack_start(GTK_BOX(form_box), dependency_combo, FALSE, FALSE, 0);
    
    /* Button box */
    button_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_pack_start(GTK_BOX(main_box), button_box, FALSE, FALSE, 5);
    
    /* Add button */
    add_button = gtk_button_new_with_label("Add Task");
    g_signal_connect(add_button, "clicked", G_CALLBACK(on_add_task_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(button_box), add_button, TRUE, TRUE, 0);
    
    /* Complete button */
    complete_button = gtk_button_new_with_label("Mark Selected Complete");
    g_signal_connect(complete_button, "clicked", G_CALLBACK(on_complete_task_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(button_box), complete_button, TRUE, TRUE, 0);
    
    /* Delete button */
    delete_button = gtk_button_new_with_label("Delete Selected");
    g_signal_connect(delete_button, "clicked", G_CALLBACK(on_delete_task_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(button_box), delete_button, TRUE, TRUE, 0);
    
    /* Status label */
    status_label = gtk_label_new("Ready. Add your first task!");
    gtk_box_pack_start(GTK_BOX(main_box), status_label, FALSE, FALSE, 0);
    
    /* Display all widgets */
    gtk_widget_show_all(window);
    
    /* Refresh task display */
    refresh_task_display();
    
    /* Start GTK main loop */
    gtk_main();
    
    return 0;
}

/* Initialize Task TreeView */
void init_task_view(GtkWidget *scrolled_window) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    
    /* Create list store */
    task_store = gtk_list_store_new(8, 
        G_TYPE_INT,     /* ID */
        G_TYPE_STRING,  /* Name */
        G_TYPE_FLOAT,   /* Priority */
        G_TYPE_INT,     /* Deadline */
        G_TYPE_STRING,  /* Type */
        G_TYPE_STRING,  /* Status */
        G_TYPE_STRING,  /* Color */
        G_TYPE_INT);    /* Rank */
    
    /* Create tree view */
    task_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(task_store));
    gtk_container_add(GTK_CONTAINER(scrolled_window), task_view);
    
    /* Rank column */
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Rank", renderer,
        "text", 7, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(task_view), column);
    
    /* Priority column with color */
    renderer = gtk_cell_renderer_text_new();
    g_object_set(renderer, "weight", 700, NULL); /* Bold */
    column = gtk_tree_view_column_new_with_attributes("Priority", renderer,
        "text", 2, "foreground", 6, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(task_view), column);
    
    /* Deadline column */
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Deadline", renderer,
        "text", 3, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(task_view), column);
    
    /* Type column */
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Type", renderer,
        "text", 4, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(task_view), column);
    
    /* Task Name column */
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Task Name", renderer,
        "text", 1, NULL);
    gtk_tree_view_column_set_expand(column, TRUE);
    gtk_tree_view_append_column(GTK_TREE_VIEW(task_view), column);
    
    /* Status column */
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Status", renderer,
        "text", 5, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(task_view), column);
}

/* Refresh Task Display */
void refresh_task_display() {
    GtkTreeIter iter;
    Task* tasks[MAX_TASKS];
    int count = 0;
    char priority_str[20];
    char deadline_str[20];
    char color[20];
    
    /* Clear existing data */
    gtk_list_store_clear(task_store);
    
    if (task_list == NULL) {
        return;
    }
    
    /* Collect all tasks */
    Task* temp = task_list;
    while (temp != NULL) {
        temp->priority_score = calculatePriority(temp);
        tasks[count++] = temp;
        temp = temp->next;
    }
    
    /* Sort by priority (bubble sort) */
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (tasks[j]->priority_score < tasks[j + 1]->priority_score) {
                Task* swap = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = swap;
            }
        }
    }
    
    /* Add to display */
    for (int i = 0; i < count; i++) {
        sprintf(priority_str, "%.1f", tasks[i]->priority_score);
        sprintf(deadline_str, "%d days", tasks[i]->deadline);
        
        /* Color based on priority */
        if (tasks[i]->priority_score >= 150) {
            strcpy(color, "#E74C3C"); /* Red */
        } else if (tasks[i]->priority_score >= 80) {
            strcpy(color, "#F39C12"); /* Orange */
        } else {
            strcpy(color, "#27AE60"); /* Green */
        }
        
        gtk_list_store_append(task_store, &iter);
        gtk_list_store_set(task_store, &iter,
            0, tasks[i]->id,
            1, tasks[i]->name,
            2, tasks[i]->priority_score,
            3, tasks[i]->deadline,
            4, getTypeName(tasks[i]->type),
            5, tasks[i]->completed ? "✓ Done" : "Pending",
            6, color,
            7, i + 1,
            -1);
    }
    
    /* Update dependency combo */
    refresh_dependency_combo();
}

/* Refresh Dependency Combo Box */
void refresh_dependency_combo() {
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(dependency_combo));
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dependency_combo), "None");
    
    Task* temp = task_list;
    char item[150];
    while (temp != NULL) {
        sprintf(item, "Task %d: %s", temp->id, temp->name);
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dependency_combo), item);
        temp = temp->next;
    }
    
    gtk_combo_box_set_active(GTK_COMBO_BOX(dependency_combo), 0);
}

/* Add Task Button Clicked */
void on_add_task_clicked(GtkWidget *widget, gpointer data) {
    const char *name = gtk_entry_get_text(GTK_ENTRY(name_entry));
    const char *deadline_text = gtk_entry_get_text(GTK_ENTRY(deadline_entry));
    int type_index = gtk_combo_box_get_active(GTK_COMBO_BOX(type_combo));
    int dep_index = gtk_combo_box_get_active(GTK_COMBO_BOX(dependency_combo));
    
    /* Validate input */
    if (strlen(name) == 0) {
        gtk_label_set_text(GTK_LABEL(status_label), "❌ Error: Please enter a task name!");
        return;
    }
    
    if (strlen(deadline_text) == 0) {
        gtk_label_set_text(GTK_LABEL(status_label), "❌ Error: Please enter a deadline!");
        return;
    }
    
    /* Create new task */
    Task* new_task = (Task*)malloc(sizeof(Task));
    new_task->id = next_id++;
    strncpy(new_task->name, name, MAX_NAME_LENGTH);
    new_task->deadline = atoi(deadline_text);
    new_task->type = (TaskType)(type_index + 1);
    new_task->dependency_id = (dep_index == 0) ? -1 : dep_index;
    new_task->completed = 0;
    new_task->next = NULL;
    
    /* Calculate priority */
    new_task->priority_score = calculatePriority(new_task);
    
    /* Add to list */
    if (task_list == NULL) {
        task_list = new_task;
    } else {
        Task* temp = task_list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_task;
    }
    
    task_count++;
    
    /* Save and refresh */
    saveTasks();
    refresh_task_display();
    
    /* Clear form */
    gtk_entry_set_text(GTK_ENTRY(name_entry), "");
    gtk_entry_set_text(GTK_ENTRY(deadline_entry), "");
    gtk_combo_box_set_active(GTK_COMBO_BOX(type_combo), 0);
    
    /* Update status */
    char status[200];
    sprintf(status, "✓ Task added! Priority: %.1f", new_task->priority_score);
    gtk_label_set_text(GTK_LABEL(status_label), status);
}

/* Mark Task Complete */
void on_complete_task_clicked(GtkWidget *widget, gpointer data) {
    GtkTreeSelection *selection;
    GtkTreeIter iter;
    GtkTreeModel *model;
    int task_id;
    
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(task_view));
    
    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
        gtk_tree_model_get(model, &iter, 0, &task_id, -1);
        
        Task* task = findTaskById(task_id);
        if (task != NULL) {
            task->completed = 1;
            saveTasks();
            refresh_task_display();
            
            char status[200];
            sprintf(status, "✓ Task '%s' marked as complete!", task->name);
            gtk_label_set_text(GTK_LABEL(status_label), status);
        }
    } else {
        gtk_label_set_text(GTK_LABEL(status_label), "❌ Please select a task first!");
    }
}

/* Delete Task */
void on_delete_task_clicked(GtkWidget *widget, gpointer data) {
    GtkTreeSelection *selection;
    GtkTreeIter iter;
    GtkTreeModel *model;
    int task_id;
    
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(task_view));
    
    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
        gtk_tree_model_get(model, &iter, 0, &task_id, -1);
        
        Task* temp = task_list;
        Task* prev = NULL;
        
        while (temp != NULL && temp->id != task_id) {
            prev = temp;
            temp = temp->next;
        }
        
        if (temp != NULL) {
            char name_backup[MAX_NAME_LENGTH];
            strcpy(name_backup, temp->name);
            
            if (prev == NULL) {
                task_list = temp->next;
            } else {
                prev->next = temp->next;
            }
            
            free(temp);
            task_count--;
            
            saveTasks();
            refresh_task_display();
            
            char status[200];
            sprintf(status, "✓ Task '%s' deleted!", name_backup);
            gtk_label_set_text(GTK_LABEL(status_label), status);
        }
    } else {
        gtk_label_set_text(GTK_LABEL(status_label), "❌ Please select a task first!");
    }
}

/* Calculate Priority (Same algorithm as before) */
float calculatePriority(Task* task) {
    float priority = 0.0;
    
    /* Deadline Weight */
    if (task->deadline <= 1) priority += 100;
    else if (task->deadline <= 3) priority += 80;
    else if (task->deadline <= 7) priority += 60;
    else if (task->deadline <= 14) priority += 40;
    else if (task->deadline <= 30) priority += 20;
    else priority += 10;
    
    /* Type Weight */
    priority += getTypeWeight(task->type);
    
    /* Dependency Weight */
    if (task->dependency_id != -1) priority -= 20;
    
    Task* temp = task_list;
    while (temp != NULL) {
        if (temp->dependency_id == task->id) {
            priority += 30;
            break;
        }
        temp = temp->next;
    }
    
    return priority;
}

/* Get Type Weight */
int getTypeWeight(TaskType type) {
    switch(type) {
        case COLLEGE: return 50;
        case WORK: return 45;
        case UPSKILL: return 35;
        case PERSONAL: return 25;
        case LEISURE: return 10;
        default: return 10;
    }
}

/* Get Type Name */
const char* getTypeName(TaskType type) {
    switch(type) {
        case COLLEGE: return "College";
        case WORK: return "Work";
        case UPSKILL: return "Upskill";
        case PERSONAL: return "Personal";
        case LEISURE: return "Leisure";
        default: return "Unknown";
    }
}

/* Find Task by ID */
Task* findTaskById(int id) {
    Task* temp = task_list;
    while (temp != NULL) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return NULL;
}

/* Save Tasks to File */
void saveTasks() {
    FILE* file = fopen(TASKS_FILE, "wb");
    if (file == NULL) return;
    
    fwrite(&task_count, sizeof(int), 1, file);
    fwrite(&next_id, sizeof(int), 1, file);
    
    Task* temp = task_list;
    while (temp != NULL) {
        fwrite(&(temp->id), sizeof(int), 1, file);
        fwrite(temp->name, sizeof(char), MAX_NAME_LENGTH, file);
        fwrite(&(temp->deadline), sizeof(int), 1, file);
        fwrite(&(temp->type), sizeof(TaskType), 1, file);
        fwrite(&(temp->dependency_id), sizeof(int), 1, file);
        fwrite(&(temp->priority_score), sizeof(float), 1, file);
        fwrite(&(temp->completed), sizeof(int), 1, file);
        temp = temp->next;
    }
    
    fclose(file);
}

/* Load Tasks from File */
void loadTasks() {
    FILE* file = fopen(TASKS_FILE, "rb");
    if (file == NULL) return;
    
    fread(&task_count, sizeof(int), 1, file);
    fread(&next_id, sizeof(int), 1, file);
    
    Task* prev = NULL;
    for (int i = 0; i < task_count; i++) {
        Task* new_task = (Task*)malloc(sizeof(Task));
        
        fread(&(new_task->id), sizeof(int), 1, file);
        fread(new_task->name, sizeof(char), MAX_NAME_LENGTH, file);
        fread(&(new_task->deadline), sizeof(int), 1, file);
        fread(&(new_task->type), sizeof(TaskType), 1, file);
        fread(&(new_task->dependency_id), sizeof(int), 1, file);
        fread(&(new_task->priority_score), sizeof(float), 1, file);
        fread(&(new_task->completed), sizeof(int), 1, file);
        
        new_task->next = NULL;
        
        if (task_list == NULL) {
            task_list = new_task;
            prev = new_task;
        } else {
            prev->next = new_task;
            prev = new_task;
        }
    }
    
    fclose(file);
}
