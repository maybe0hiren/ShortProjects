#include <iostream>

int powerFunction(int base, int exponent) {
    int number = 1;
    for (int i = 0; i < exponent; ++i) {
        number *= base;
    }
    return number;
}



int main(){
    std::string binaryEntry;
    int decimalNumber = 0;
    std::cout<< "Enter a binary number: ";
    std::cin>> binaryEntry;
    for (int i = binaryEntry.length()-1; i>=0; i--){
        if(binaryEntry[i] == '1'){
            decimalNumber = decimalNumber + powerFunction(2,binaryEntry.length()-1-i);
        }
        else if(binaryEntry[i] == '0'){
            decimalNumber = decimalNumber;
        }
        else{
            std::cout << "Error!";
        }
    }
    std::cout<< "The Decimal form of the number is: " << decimalNumber;
    return 0;
}