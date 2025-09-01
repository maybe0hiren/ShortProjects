#include <iostream>
#include <vector>

int main(){
    std::vector<std::string> sentences = {"alice and bob love leetcode","i think so too","this is great thanks very much"};
    std::string vecElement;
    int words;
    int maxWords = 0;
    for (int i = 0; i<sentences.size(); i++){
        vecElement = sentences[i];
        words = 1;
        for (int j = 0; j<vecElement.length(); j++){
            if (vecElement[j] == ' '){
                words++;
            }
        }
        if(words>maxWords){
            maxWords = words;
        }
    }
    std::cout << maxWords;
    return 0;
}