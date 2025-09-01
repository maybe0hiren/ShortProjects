#include <iostream>

int main(){
    std::string command = "G()(al)";
    std::string returnString;
    for (int i = 0; i<command.length(); i++){
        std::cout << command[i] << " ";
        if(command[i] == 'G'){
            returnString = returnString + 'G';
        }
        else if(command[i] == '('){
            if(command[i+1] == ')'){
                returnString = returnString + 'o';
            }
            else if(command[i+1] == 'a'){
                returnString = returnString + "al";
            }
        }
    }
    std::cout << returnString;
    return 0;
}