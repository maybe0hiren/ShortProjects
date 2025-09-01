#include <iostream>
#include <list>

class hashTable{
    private:
        static const int size = 10;
        std::list<int> table[size];

        int hashfunction(int key){
            return key%size;
        }
    public:
        void insert(int key){
            int index = hashfunction(key);
            table[index].push_back(key);
        }

        int search(int key){
            int index = hashfunction(key);
            for (auto &entry : table[index]){
                if (entry == key){
                    return key;
                }
            }
            return -1;
        }
};

int main(){
    hashTable ht;
    int userInput;
    int userInputArray[5];
    int counter = 0;
    for(int i = 0; i<10; i++){
        std::cout << "Enter element " << i+1 << ": ";
        std::cin >> userInput;

        ht.insert(userInput);
    }

    for(int i = 0; i<5; i++){
        std::cout << "Enter element " << i+1 << " for second array: ";
        std::cin >> userInput;
        userInputArray[i] = userInput;
    }

    for (int i = 0; i<5; i++){
        if(ht.search(userInputArray[i]) == -1){
            std::cout << "Not a Subarray....";
            break;
        }
        else{
            counter++;
        }
    }

    if(counter == 5){
        std::cout << "Subarray confirmed....";
    }

}
