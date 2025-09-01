#include <iostream>

int main(){
    std::string s = "abc";
    int revDeg = 0;
    for(int i = 0; i<s.length(); i++){
        revDeg = revDeg + ((123-(int)s[i])*(i+1));
    }
    std::cout << revDeg;
    return 0;
}