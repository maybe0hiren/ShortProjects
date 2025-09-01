#include <iostream>

int absoluteDiff(int a, int b){
    if (a>b){
        return a-b;
    }
    else{
        return b-a;
    }
}

int main(){
    std::string s = "zaz";
    int score = 0;
    int asciiArray[s.length()];

    for (int i = 0; i<s.length(); i++){
        asciiArray[i] = (int)s[i];
    }

    for (int i = 0; i<s.length()-1; i++){
        score = score + absoluteDiff(asciiArray[i], asciiArray[i+1]);
    }

    std::cout << score;
    return 0;
}