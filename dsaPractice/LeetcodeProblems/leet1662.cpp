#include <iostream>
#include <vector>

int main(){
    std::vector<std::string> word1 = {"ab", "c"};
    std::vector<std::string> word2 = {"a", "bc"};
    std::string str1, str2;
    for(int i = 0; i<word1.size(); i++){
        str1 = str1 + word1[i];
    }
    for(int i = 0; i<word2.size(); i++){
        str2 = str2 + word2[i];
    }
    if(str1 == str2){
        std::cout << true;
    }
    else{
        std::cout << false;
    }
    return 0;
}