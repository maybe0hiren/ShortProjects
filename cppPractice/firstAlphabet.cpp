#include <iostream>

int main(){
    std::string sentence = "Hello World my name is Hiren.";
    std::cout << sentence[0] << " ";
    for (int i = 0; i<sentence.length(); i++){
        if (sentence[i] == ' '){
            std::cout << sentence[i+1] << " ";
        }
    }
    return 0;
}