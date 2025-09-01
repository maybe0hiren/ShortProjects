#include <iostream>

int main(){
    std::string n = "32";
    char max = 0;
    char digit;
    for(int i = 0; i<n.length(); i++){
        digit = n[i];
        if(max<digit){
            max = digit;
        }
    }
    std::cout << max;
    return 0;
}