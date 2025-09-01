#include <iostream>

int main(){
    std::string string1 = "Hello World";
    std::string string2 = "Bye World";

    if(string1 == string2){
        std::cout<< "Strings are equal";
    }
    else{
        std::cout<< "Strings are not equal"; 
    }
    return 0;
}