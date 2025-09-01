#include <iostream>

int powerFunction(int base, int exponent) {
    int number = 1;
    for (int i = 0; i < exponent; ++i) {
        number *= base;
    }
    return number;
}


int main(){
    std::string hexEntry;
    std::cout << "Enter the hexadecimal number: ";
    std::cin >> hexEntry;
    int decimal = 0;
    for (int i = hexEntry.length()-1; i>=0; i--){
        if (hexEntry[i] == '0'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*0;
        }
        else if(hexEntry[i] == '1'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*1;
        }
        else if(hexEntry[i] == '2'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*2;
        }
        else if(hexEntry[i] == '3'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*3;
        }
        else if(hexEntry[i] == '4'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*4;
        }
        else if(hexEntry[i] == '5'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*5;
        }
        else if(hexEntry[i] == '6'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*6;
        }
        else if(hexEntry[i] == '7'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*7;
        }
        else if(hexEntry[i] == '8'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*8;
        }
        else if(hexEntry[i] == '9'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*9;
        }
        else if(hexEntry[i] == 'A'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*10;
        }
        else if(hexEntry[i] == 'B'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*11;
        }
        else if(hexEntry[i] == 'C'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*12;
        }
        else if(hexEntry[i] == 'D'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*13;
        }
        else if(hexEntry[i] == 'E'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*14;
        }
        else if(hexEntry[i] == 'F'){
            decimal = decimal + powerFunction(16,hexEntry.length()-1-i)*15;
        }
        else{
            std::cout << "ERROR!";
        }
    }
    std::cout << decimal;
    return 0;
}