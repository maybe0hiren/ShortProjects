#include <iostream>

bool isPresent(char x, std::string str){
    for (char i : str){
        if (i == x){
            return true;
        }
    }
    return false;
}

int main(){
    std::string s = "successes";
    std::string unity;
    int vowCount = 0,consCount = 0, maxVow = 0, maxCons = 0;
    std::string vowels = "aeiou";
    for(char x : s){
        if (isPresent(x,unity) == 0){
            unity = unity + x;
        }
    }
    for(char x : unity){
        vowCount = 0;
        consCount = 0;
        for(char y : s){
            if(x == y){
                if(isPresent(x, vowels) == 1){
                    vowCount++;
                }
                else{
                    consCount++;
                }
            }
        }
        if(vowCount>maxVow){
            maxVow = vowCount;
        }
        if(consCount>maxCons){
            maxCons = consCount;
        }
    }
    std::cout << maxCons << " " << maxVow;
    return 0;
}