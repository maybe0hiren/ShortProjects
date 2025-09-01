#include <iostream>
std::string alphabets = "abcdefghijklmnopqrstuvwxyz";
std::string checking(char x){
    for (int i = 0; i<alphabets.length(); i++){
        if (x == alphabets[i]){
            alphabets[i] = '.';
        }
    }
    return alphabets;
}

int main(){
    std::string checkString;
    std::string sentence = "the quick brown fox jumps over the lazy dog";
    for (int i = 0; i<sentence.length()+1; i++){
        checkString = checking(sentence[i]);
    }
    if (checkString == ".........................."){
        std::cout << "The sentence is a Pangram";
    }
    else{
        std::cout << "The sentence is not a Pangram";
    }
    return 0;
}