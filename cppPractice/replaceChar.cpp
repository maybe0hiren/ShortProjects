#include <iostream>

int main(){
    std::string givenString = "Hi my name is Om Prakash Makkhija!";
    char toReplace, replaceWith;

    std::cout<< "Enter the character to be replaced: ";
    std::cin>> toReplace;
    std::cout<< "Enter the character to replace it with: ";
    std::cin>> replaceWith;

    for (int i = 0; i<givenString.length(); i++){
        if (givenString[i] == toReplace){
            givenString[i] = replaceWith;
        }
    }
    std::cout << givenString;
    return 0;
}