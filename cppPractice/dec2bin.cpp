#include <iostream>

void reverseString(std::string &stringInput){
    for(int i = 0; i<=stringInput.length()/2; i++){
        std::swap(stringInput[i], stringInput[stringInput.length()-i-1]);
    }
}

int main(){
    int decimalInput;
    std::string binaryOutput;
    std::cout << "Enter a number: ";
    std::cin >> decimalInput;
    while (decimalInput>0){
        if (decimalInput%2 == 0){
            binaryOutput = binaryOutput + '0';
            decimalInput = decimalInput/2;
        }
        else{
            binaryOutput = binaryOutput + '1';
            decimalInput = decimalInput/2;
        }
    }
    reverseString(binaryOutput);
    std::cout << binaryOutput;
    return 0;
}


