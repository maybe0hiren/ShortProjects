#include <iostream>
#include <vector>

void printVector(std::vector<int> &vec){
    for (int i = 0; i<vec.size(); i++){
        std::cout << vec[i];
    }
}
int main(){
    std::vector<std::string> words = {"abc","bcd","aaaa","cbc"};
    std::vector<int> indices;
    char x = 'a';
    int counter;
    for(int i = 0; i<words.size(); i++){
        counter = 0;
        std::string word = words[i];
        for(int j = 0; j<word.length(); j++){
            if (word[j] == x){
                counter++;
            }
        }
        if (counter>0){
            indices.push_back(i);
        }
    }
    printVector(indices);
    return 0;
}