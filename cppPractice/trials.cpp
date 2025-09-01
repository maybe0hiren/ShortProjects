#include <iostream>

// int function(int x, int y){
//     if (x==0){
//         return y;
//     }   
//     else{
//         return function(x-1, x+y);
//     }
// }

// int abcd(int a, int b){
//     std::cout << a - 48 << " " << b-48;
// }

void reverseString(std::string &stringInput){
    for(int i = 0; i<=stringInput.length()/2; i++){
        std::swap(stringInput[i], stringInput[stringInput.length()-i-1]);
    }
    std::cout << stringInput;
}

int main(){
//     std::string word = "HIREN";

//     std::cout<< word.size();
//     std::cout<< word.length();
//     int series[5];
//     series[0,1,2,3,4] = 2,3,56,34,765;
//     // series[1] = 3;
//     for (int i = 0; i<=1; i++){
//         std::cout<< series[i];
//     }
//     return 0;
    // for (int i=0; i<=8; i++){
    //     std::cout<< printArray(i);
    // }

    // char a = '1';
    // int a  = (int)a - 48;
    // std::cout<< a;

    // abcd('1','0');

    // std::string all = "asdfghjkl";
    // all.erase(2);

    // // std::cout << all;
    // std::string name = "Hiren";
    // reverseString(name);
    // std::cout << name;
    double number1 = 1231.3123123;
    for (int i = 0; i<10; i++){
        std::cout << number1 << "\n";
        number1 *= 10;
    }
    
    return 0;
}