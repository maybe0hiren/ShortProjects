#include <iostream>

int main(){
    std::string s = "Hello how are you Contestant";
    int k = 4;
    std::string returnString;
    for(char x : s){
        if(x == ' '){
            k--;
        }
        if(k == 0){
            returnString.pop_back();
            break;
        }
    }
    std::cout << returnString;
    return 0;
}


// int main(){
//     std::string s = "Hello how are you Contestant";
//     int k = 2;
//     int i = 0;
//     for(char x : s){
//         if(x == ' '){
//             k--;
//         }
//         if(k == 0){
//             s = s.substr(0,i);
//         }
//         i++;
//     }
//     std::cout << s;
//     return 0;
// }