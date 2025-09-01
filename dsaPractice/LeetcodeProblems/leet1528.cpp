#include <iostream>
#include <vector>
int main(){
    std::string s = "codeleet";
    std::vector<int> indices = {4,5,6,7,0,2,1,3};
    std::string returnString;
    for (int i = 0; i<s.length(); i++){
        returnString.append(".");
    }
    for(int i = 0; i<s.length(); i++){
        returnString[indices[i]] = s[i];
    }    
    std::cout << returnString;
    return 0;
}