#include <iostream>
#include<unordered_set>

int main(){
    std::string stones = "aAAbbbb";
    std::string jewels = "aA";
    int counter = 0;
    std::unordered_set<char> jewelSet;
    for(int i = 0; i<jewels.length(); i++){
        jewelSet.insert(jewels[i]);
    }
    for(int i = 0; i<stones.length(); i++){
        auto search = jewelSet.find(stones[i]);
        if(search != jewelSet.end()){
            counter++;
        }
    }
    std::cout << counter;
    return 0;   
}