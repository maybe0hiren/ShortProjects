#include <iostream>
//Some random error at the return value of line 7, code works in leetcode;
int main(){
    std::string word = "abacdefd";
    char ch = 'd';
    char temp;
    int endIndex = word.find(ch);
    if (endIndex == -1){
        std::cout << word;
    }
    for(int i = 0; i<=endIndex/2; i++){
        temp = word[i];
        word[i] = word[endIndex-i];
        word[endIndex-i] = temp;
    }
    std::cout << word;
    return 0;
}