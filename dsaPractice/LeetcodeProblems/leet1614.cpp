#include <iostream>

int main(){
    std::string s = "(1+(2*3)+((8)/4))+1";
    int max = 0;
    int count = 0;
    for (int i = 0; i<s.size(); i++){
        if(s[i] == '('){
            count++;
            if(count>max){
                max = count;
            }
        }
        else if (s[i] == ')'){
            count--;
        }
    }
    std::cout << max;
    return 0;
}