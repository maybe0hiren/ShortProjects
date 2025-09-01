#include <iostream>

int numb, fact;

int factorial(int number){
    if (number <= 1){
        fact = 1;
    }
    else{
        fact = number * factorial(number - 1);
    }
    return fact;
}
int main(){
    std::cout<< "Enter the number: ";
    std::cin>> numb;
    fact = factorial(numb);
    std::cout<< "Factorial of " << numb << " " << "is " << fact;
}