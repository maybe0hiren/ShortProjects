#include <iostream>

int number;

int main(){
    std::cout << "Enter the number: ";
    std::cin >> number;

    if (number%2 == 0){
        std::cout << number << " is an even number";
    }
    else{
        std::cout << number << " is an odd number";
    }
    return 0;
}