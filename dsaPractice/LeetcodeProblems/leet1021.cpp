#include <iostream>

int main(){
    std::string s = "(()())((()))";
    std::string  returnString; 
    int balance = 0; 
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {

            if (balance > 0) {
                returnString += s[i]; 
            }
            balance++;
        } else {
            balance--;
            if (balance > 0) {
                returnString += s[i];
            }
        }
    }
    std::cout << returnString;
    return 0;
}