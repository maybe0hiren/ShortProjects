#include <iostream>

std::string reverse;
std::string reverseString(std::string word){
    int length = word.length();
    if(length == 0){
        return "";
    }
    reverse = reverseString(word.substr(1,length)) + word[0];
    return reverse;
}

int main(){
    std::string word;
    std::cout<< "Enter the word: ";
    std::cin>> word;
    reverse = reverseString(word);
    std::cout<< reverse;
}