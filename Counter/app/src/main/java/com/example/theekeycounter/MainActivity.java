package com.example.theekeycounter;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;

public class MainActivity extends AppCompatActivity {

    private TextView counterText;
    private int counter = 0;
    private File csvFile;
    private List<String> lines = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        counterText = findViewById(R.id.counterText);
        Button incrementBtn = findViewById(R.id.incrementBtn);
        Button decrementBtn = findViewById(R.id.decrementBtn);

        // CSV file in Downloads folder for easy access
        File dir = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS);
        csvFile = new File(dir, "counter_data.csv");

        loadData();

        incrementBtn.setOnClickListener(v -> {
            counter++;
            counterText.setText(String.valueOf(counter));
            addEntry();
        });

        decrementBtn.setOnClickListener(v -> {
            if (counter > 0) {
                counter--;
                counterText.setText(String.valueOf(counter));
                removeLastEntry();
            }
        });
    }

    private void loadData() {
        try {
            if (!csvFile.exists()) {
                csvFile.createNewFile();
                writeHeader();
            }
            BufferedReader reader = new BufferedReader(new FileReader(csvFile));
            String line;
            lines.clear();
            while ((line = reader.readLine()) != null) {
                lines.add(line);
            }
            reader.close();
            if (lines.size() > 1) {
                counter = lines.size() - 1; // minus header
                counterText.setText(String.valueOf(counter));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void writeHeader() throws IOException {
        FileWriter writer = new FileWriter(csvFile, true);
        writer.append("Count,Date,Time\n");
        writer.flush();
        writer.close();
    }

    private void addEntry() {
        try {
            String date = new SimpleDateFormat("yyyy-MM-dd", Locale.getDefault()).format(new Date());
            String time = new SimpleDateFormat("HH:mm:ss", Locale.getDefault()).format(new Date());
            FileWriter writer = new FileWriter(csvFile, true);
            writer.append(counter + "," + date + "," + time + "\n");
            writer.flush();
            writer.close();
            lines.add(counter + "," + date + "," + time);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void removeLastEntry() {
        try {
            if (lines.size() > 1) { // keep header
                lines.remove(lines.size() - 1);
                FileWriter writer = new FileWriter(csvFile, false);
                for (String l : lines) {
                    writer.write(l + "\n");
                }
                writer.flush();
                writer.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
