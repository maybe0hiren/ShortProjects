#include <iostream>
#include <list>

class hashTable{
    private:
        static const int size = 10;
        std::list<int> table[size];

        int hashFunction(int key){
            return key%size;
        }
    
        public:
            void insert(int key){
                int index = hashFunction(key);
                table[index].push_back(key);
            }
            
            int search(int key){
                int index = hashFunction(key);
                for (auto &entry: table[index]){
                    if (entry == key){
                        return entry;
                    }
                }
                return -1;
            }
            void display() {
                for (int i = 0; i < size; ++i) {
                    if (!table[i].empty()) {
                        std::cout << "index: " << i << ": ";
                        for (auto &entry : table[i]) {
                            std::cout << entry << " ";
                        }
                        std::cout << std::endl;
                    }
                }
            }
};

int main(){
    hashTable ht;
    int target, inputArray[10];
    for (int i = 0; i<10; i++){
        std::cout << "Enter element " << i+1 << ": ";
        std::cin >> inputArray[i];
        ht.insert(inputArray[i]);

    }
    ht.display();
    std::cout << "Enter the target: ";
    std::cin >> target;
    for (int i = 0; i<10; ++i){
        int secondNumber = target - inputArray[i];
        int value = ht.search(secondNumber);
        if (value != -1){
            std::cout << "Pair found: " << "(" << inputArray[i] << " , " << secondNumber << ")";
            break;
        }
        else{
            std::cout << "Pair not found";
        }
    }
}