#include <iostream>

int main(){
    std::string s = "RLRRRLLRLL";
    int counterR = 0;
    int counterL = 0;
    int returnCounter = 0;

    for(int i = 0; i<s.length(); i++){
        if(s[i] == 'L'){
            counterL++;
        }
        else if(s[i] == 'R'){
            counterR++;
        }
        if(counterL == counterR){
            returnCounter++;
        }
    }
    std::cout << returnCounter << " ";
    return 0;
}