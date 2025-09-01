#include <iostream>

int absDiff(int x, int y){
    if(x>=y){
        return x-y;
    }
    else{
        return y-x;
    }
}

int main(){
    std::string s = "abc";
    std::string t = "bac";

    int permDiff = 0;
    for(int i = 0; i<s.length(); i++){
        permDiff = permDiff + absDiff(i,t.find(s[i]));
    }
    std::cout << permDiff;
    return 0;
}