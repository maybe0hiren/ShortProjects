#include <iostream>

int checker(int number){
    if(number>100){
        return (number-100);
    }
    else{
        return (100-number);
    }
}

int main(){
    int num1, num2;
    std::cout << "Enter number 1: ";
    std::cin>> num1;
    std::cout << "Enter number 2: ";
    std::cin>> num2;

    if (checker(num1) > checker(num2)){
        std::cout << num2 << " is closer to 100.";
    }
    else{
        std::cout << num1 << " is closer to 100";
    }
    return 0;
}   