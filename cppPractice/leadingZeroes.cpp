#include <iostream>

int main(){
    std::string rawString = "000234023020434";
    std::string filteredString;
    int leadingZeroEnd = 0;
    for(int i = 0; i<rawString.length(); i++){
        if(rawString[i] == '0'){
            leadingZeroEnd++;
        }
        else{
            break;
        }
    }
    for(leadingZeroEnd; leadingZeroEnd<rawString.length(); leadingZeroEnd++){
        filteredString = filteredString + rawString[leadingZeroEnd];
    }
    std::cout << filteredString;
    return 0;
}