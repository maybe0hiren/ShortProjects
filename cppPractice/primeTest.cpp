#include <iostream>

int main(){
    int number, count;
    std::cout<< "Enter the number: ";
    std::cin>> number;
    count = 0;
    if (number > 0){
        for (int i = 1; i<=number; i++){
            if (number%i == 0){
                count++;
            }
            else{
                count = count;
            }
        }
        if (count <= 2){
            std::cout<< number << " is a prime number.";
        }
        else{
            std::cout<< number << " is not a prime number.";
        }
    }
    else{
        std::cout<< "Invalid.";
    }
        return 0;
}