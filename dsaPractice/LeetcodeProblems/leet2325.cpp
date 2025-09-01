#include <iostream>

bool isPresent(char x, std::string s){
    for(char i : s){
        if(i == x){
            return true;
        }
    }
    return false;
}
std::string keyFilter(std::string rawString){
    std::string filteredString;
    for (char x : rawString){
        if(x != ' ' && isPresent(x, filteredString) == 0){
            filteredString.push_back(x);
        }
    }
    return filteredString;
}

int main(){
    std::string key = "the quick brown fox jumps over the lazy dog";
    std::string message = "vkbs bs t suepuv";
    std::string alphabets = "abcdefghijklmnopqrstuvwxyz";
    std::string returnString;
    key = keyFilter(key);
    for(char x : message){
        if(x != ' '){
            returnString.push_back(alphabets[key.find(x)]);
        }
        else{
            returnString.push_back(' ');
        }
    }
    std::cout << returnString;

    return 0;
}