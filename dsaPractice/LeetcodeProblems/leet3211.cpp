#include <iostream>
#include <vector>

std::string reverseString(std::string rawString){
    std::string reversedString;
    for(int i = 0; i<rawString.length(); i++){
        reversedString += rawString[rawString.length()-1-i];
    }
    return reversedString;
}
std::string dec2bin(int x, int reqLen){
    std::string binaryString;
    while (x>0){
        if(x%2 == 0){
            binaryString += '0';
        }
        else{
            binaryString += '1';
        }
        x /= 2;
    }
    if(binaryString.length() != reqLen){
        int addTimes = reqLen - binaryString.length();
        for (int i = 0; i<addTimes; i++){
            binaryString += '0';
        }
    }
    return reverseString(binaryString);
}

int maxNum(int x){
    int number = 1;
    for(int i = 0; i<x; i++){
        number *= 2;
    }
    return number;
}

bool toPush(int x, int reqLen){
    std::string binNum = dec2bin(x, reqLen);
    for(int i = 0; i<binNum.length()-1; i++){
        if (binNum[i] == '0' && binNum[i+1] == '0'){
            return false;
        }
    }
    return true;
}

int main(){
    int n = 5;
    std::vector<std::string> returnString;
    int max = maxNum(n);
    for (int i = 0; i<max; i++){
        if(toPush(i, n) == 1){
            returnString.push_back(dec2bin(i, n));
        }
    }
    for (int i = 0; i<returnString.size(); i++){
        std::cout << returnString[i] << " "; 
    }

    return 0;
}