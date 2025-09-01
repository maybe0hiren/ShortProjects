#include <iostream>
int carry = 0;
char quickAddition(int a, int b){
    a = a - 48;
    b = b - 48;
    if (a + b + carry == 2){
        carry = 1;
        return '0';
    }
    if (a + b + carry == 1){
        carry = 0;
        return '1';
    }
    if (a + b + carry  == 0){
        carry = 0;
        return '0';
    }
    if (a + b + carry == 3){
        carry = 1;
        return '1';
    }
}

std::string reverseString(std::string inputString){
    std::string reversedString;
    for (int i = inputString.length()-1; i>=0; i--){
        reversedString = reversedString + inputString[i];
    }
    return reversedString;
}

int main(){
    std::string binary1 = "01011";
    std::string binary2 = "001";
    std::string reversedOutput, reversedBinary1, reversedBinary2;
    std::string output;
    std::string greaterString;
    int smallerStringLength, greaterStringLength;
    reversedBinary1 = reverseString(binary1);
    reversedBinary2 = reverseString(binary2);
    if(binary1.length() > binary2.length()){
        greaterString = reversedBinary1;
        smallerStringLength = binary2.length();
        greaterStringLength = binary1.length();
    }
    else{
        greaterString = reversedBinary2;
        smallerStringLength = binary1.length();
        greaterStringLength = binary2.length();
    }
    
    int count  = 0;
    for (int i = 0; i<=smallerStringLength-1; i++){
        reversedOutput = reversedOutput + quickAddition(reversedBinary1[i],reversedBinary2[i]);
        count++;
    }

    for(count; count<greaterStringLength; count++){
        reversedOutput = reversedOutput + quickAddition(greaterString[count],'0');
    }
    output = reverseString(reversedOutput);
    std::cout<< output;
    return 0;
}