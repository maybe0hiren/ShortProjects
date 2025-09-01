#include <iostream>
int str2dec(std::string stringNumber){
    int number = 0;
    for (int i = 0; i<stringNumber.length(); i++){
        number  = number*10 + (int)stringNumber[i]-48;
    }
    return number;
}
std::string dec2bin(std::string stringNumber){
    int decNumber = str2dec(stringNumber);
    std::string rawBinNumber;
    while (decNumber>=1){
        if(decNumber%2 == 0){
            rawBinNumber = rawBinNumber + '0';
        }
        else{
            rawBinNumber = rawBinNumber + '1';
        }
        decNumber = decNumber/2;
    }
    std::string binNumber;
    int digits = rawBinNumber.length();
    while (digits != 0){
        binNumber = binNumber + rawBinNumber[digits-1];
        digits--;
    }
    return binNumber;
}

int main(){
    std::string date = "2080-02-29";
    std::string year,month,day;
        std::string binaryDate;
        for (int i = 0; i<10; i++){
            if (i<4){
                year = year + date[i];
            }
            else if(i>4 && i<7){
                month = month + date[i];
            }
            else if(i>7){
                day = day + date[i];
            }
        }
        binaryDate = dec2bin(year) + "-" + dec2bin(month) + "-" + dec2bin(day);
        std::cout << binaryDate;
    return 0;
}