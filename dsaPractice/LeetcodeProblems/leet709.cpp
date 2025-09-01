#include <iostream>

int main(){
    std::string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i<s.length(); i++){
        if((int)s[i] >= 65 && (int)s[i] <= 90){
            s[i] = (char)((int)s[i] + 32);
        }
    }
    std::cout << s;
    return 0;
}