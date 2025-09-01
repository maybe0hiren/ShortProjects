#include <iostream>

int num1, num2, num3;

int main(){
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the secind number: ";
    std::cin >> num2;
    std::cout << "Enter the third number: ";
    std::cin >> num3;
    if (num1 >= num2){
        if (num1 >= num3){
            std::cout << num1 << " is the largest number";
        }
        else{
            std::cout << num3 << " is the largest number";
        }
    }
    else{
        if (num2 >= num3){
            std::cout << num2 << " is the largest number";
        }
        else{
            std::cout << num3 << " is the largest number";
        }
    }
    return 0;
}