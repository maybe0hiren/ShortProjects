#include <iostream>
#include <unordered_set>

int main(){
    int subStringSize = 0;
    int j = 0;
    std::string s = "aabaab!bb";
    std::unordered_set<char> alphabets;
    for(int i = 0; i<s.length(); i++){
        auto search = alphabets.find(s[i]);
        if (search != alphabets.end()){
            while (s[j] != s[i]){
                alphabets.erase(s[j]);
                j++;
            }
            alphabets.erase(s[j]);
            j++;
        }
        alphabets.insert(s[i]);
        if (subStringSize<alphabets.size()){
            subStringSize = alphabets.size();
        }
    }
    std::cout << subStringSize;
    return 0;
}