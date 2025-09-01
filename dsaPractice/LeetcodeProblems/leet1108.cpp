#include <iostream>

int main(){
    std::string address = "255.100.50.0";
    std::string defangAddress;
    int j = 0;
    for (int i = 0; i<address.length(); i++){
        if(address[i] != '.'){
            defangAddress = defangAddress + address[i];
            j++;
        }
        else{
            defangAddress = defangAddress + "[.]";
            j = j+2;
        }
    }
    std::cout << defangAddress; 
    return 0;
}