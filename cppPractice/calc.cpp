#include <iostream>

int main(){
    double num1, num2, answer;
    char operation;
    std::cout<< "Enter the first number: ";
    std::cin>> num1;
    std::cout<< "Enter the operation (+, -, *, /): ";
    std::cin>> operation;
    std::cout<< "Enter the second number: ";
    std::cin>> num2;

    std::cout<< "Performing operation: " << num1 << " " << operation << " " << num2 << "\n";
    if (operation == '+'){
        answer = num1 + num2;
    }
    else if (operation == '-'){
        answer = num1 - num2;
    }
    else if (operation == '*'){
        answer = num1*num2;
    }
    else if (operation == '/'){
        answer = num1/num2;
    }
    else{
        std::cout<< "Error";
    }
    std::cout<< "Answer: " << answer;
    return 0;
}