#include <iostream>

int result;
int sum(int number){
    if (number == 0){
        return result;
    }
    else{
        result  = number + sum(number-1);
        return result;
    }
}

int main(){
    int number, result;
    std::cout<< "Enter the number: ";
    std::cin>> number;
    result = sum(number);
    std::cout<< "The sum of first "<< number<< " natural numbers is: "<< result;
    return 0;
}