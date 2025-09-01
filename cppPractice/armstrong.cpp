#include <iostream>

int powerFunct(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int main(){
    int inputNum,m,n,power;
    std::cout<< "Enter a number: ";
    std::cin >> inputNum;
    m = inputNum;
    if(inputNum > 0){
        for(int i = 0; m>=1; i++){
            m = m/10;
            power = i+1;
        }
    }
    else{
        power = 1;
    }
    n = inputNum;
    int x = 0;
    for (int i = 0; n>=1; i++){
        x = x + powerFunct(n%10,power);
        n = n/10;
    }
    if (x == inputNum){
        std::cout << "The number is an amstrong number.";
    }
    else{
        std::cout << "The number is not an amstring number.";
    }
    return 0;
}