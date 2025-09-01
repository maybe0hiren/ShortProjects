//My code
// #include <iostream>
// #include <vector>
// bool valid(std::string word, std::string pref){
//     for(int i = 0; i<pref.length(); i++){
//         if(word[i] != pref[i]){
//             return false;
//         }
//     }
//     return true;
// }
// int main(){
//     std::vector<std::string> words = {"pay","attention","practice","attend"};
//     std::string pref = "at";
//     int count = 0;

//     for(int i = 0; i<words.size(); i++){
//         if(valid(words[i], pref) == 1){
//             count++;
//         }
//     }
//     std::cout << count;
//     return 0;
// }


#include <iostream>
#include <vector>

int main(){
    std::vector<std::string> words = {"pay","attention","practice","attend"};
    std::string pref = "at";
    int count = 0 ;
        for (int i = 0; i < words.size(); i++){
        if (words[i].size() >= pref.size()){
            std::string wordPrefix = words[i].substr(0, pref.size());
            if (wordPrefix == pref){
                count++;
            }
        }
    }
    std::cout << count;
    return 0;
}