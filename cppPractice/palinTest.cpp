#include <iostream>

int palinTest(std::string word, int midValue, int length){
    int count = 0;
    for (int i = 0; i<=midValue-1; i++){
        if (word[i] == word[length-1-i]){
            count++;
        }
    }
    return count;
}

int main(){
    std::string word;
    int count, length, midValue;
    std::cout<< "Enter the word: ";
    std::cin>> word;
    length = word.length();

    if (length%2 == 0){
        midValue = length/2;
        count = palinTest(word, midValue, length);
    }
    else{
        midValue = (length+1)/2;
        count = palinTest(word, midValue, length);
    }
    if (count == midValue){
        std::cout<< word << " is a palindrome";
    }
    else{
        std::cout<< word << " is not a palindrome";
    }
    return 0;
}