#include <iostream>
#include <list>

class hashTable{
    private:
        static const int size = 10; //Setting the size of Hash Table
        std::list<std::pair<int, int>> table[size]; // Defining table: array of list

        int hashFunction(int key){
            int index = key%10; //simple modulo hash function: key = last digit
            return index;
        }
    public:
        void insert(int key, int value){
            int index = hashFunction(key); //using the index from the hash function we just made
            table[index].push_back(std::make_pair(key, value)); //instering key-value pair in the list
            std::cout << "Inserted " << key << " , " << value << " at index: " << index << std::endl; // confirmation
        }
        int search(int key){
            int index = hashFunction(key); //index of the required key is computed
            for (auto &pair : table[index]){ //all the pairs inside the index are traversed
                if (pair.first == key){ //if the key matched
                    return pair.second; //the value is returned
                }
            }
            return -1; //if key not found, value is returned
        }
        void remove(int key){
            int index = hashFunction(key);
            std::list<std::pair<int, int>> &chain = table[index]; //assigning a name to the index we need to delete the key-value pair from
            for (auto i = chain.begin(); i != chain.end(); ++i){ //++i is more efficient than i++
                if((*i).first == key){ //if the key matches in the chain
                    chain.erase(i); //it gets removed
                    std::cout << "Deleted " << key << std::endl; //confirmation
                    return;
                } 
            }
            std::cout << key << " not found \n";
        }
        void display() {
            for (int i = 0; i < size; ++i) {
                if (!table[i].empty()) {
                    std::cout << "index: " << i << ": ";
                    for (auto& pair : table[i]) {
                        std::cout << "(" << pair.first << ", " << pair.second << ") ";
                    }
                    std::cout << std::endl;
                }
            }
        }
};

int main(){
    hashTable ht;

    //inserting (key, value)
    ht.insert(13,600);
    ht.insert(15,654);
    ht.insert(22,200);
    ht.insert(89,122);
    ht.insert(53,45);
    ht.insert(42,622);
    ht.insert(72,890);
    ht.insert(83,499);

    //display hash table
    ht.display();

    //searching (key)
    int searchKey = 89;
    int value = ht.search(searchKey);
    if (value == -1){
        std::cout << "Key not found";
    }
    else{
        std::cout << "Key found with value: " << value << std::endl;  
    }

    //delete
    int removeKey = 13;
    ht.remove(removeKey);
    std::cout << "Key: " << removeKey<< " removed.\n New hash table: \n";
    ht.display();

    return 0;
}