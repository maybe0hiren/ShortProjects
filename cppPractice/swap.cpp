#include <iostream>

int main(){
    int first, second;
    std::cout << "Enter the first number: ";
    std::cin >> first;
    std::cout << "Enter the second number: ";
    std::cin >> second;

    first = first + second;
    second = first - second;
    first = first - second;

    std::cout << first << " and " << second;
    return 0;    
}