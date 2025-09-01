#include <iostream>
#include <unordered_set>
#include <vector>

int main(){
    std::string allowed = "ab";
    std::vector<std::string> words = {"ad","bd","aaab","baa","badab"};
    std::unordered_set<char> allowedAlphabets;
    std::string wordElement;
    int consistentStrings = 0;

    for(int i = 0; i<allowed.length(); i++){
        allowedAlphabets.insert(allowed[i]);
    }
    for(int i = 0; i<words.size(); i++){
        wordElement = words[i];
        int j = 0;
        while (j<wordElement.length()){
            auto search = allowedAlphabets.find(wordElement[j]);
            if(search != allowedAlphabets.end()){
                j++;
            }
            else{
                break;
            }
        }
        if (j == wordElement.length()){
            consistentStrings++;
        }
    }
    std::cout << consistentStrings;
}