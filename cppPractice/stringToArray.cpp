// #include <iostream>

// int main(){
//     int size = 0;
//     std::string numString;
//     std::cout<< "Enter the numbers (separate them with commas): ";
//     std::cin>> numString;
//     for (int i = 0; i<=numString.length();i++){
//         if (numString[i] == ','){
//             size++;
//         }
//     }
//     if (size == 0){
//         std::cout<< "Enter more than one values.";
//     }
//     else{
//         int numArray[size];
//         int tempNum = 0;
//         int count = 0;
//         for (int j = 0; j<=size; j++){
//             for (int i = 0; numString[i] != ','; i++){
//                 tempNum = tempNum*10 + ((int)numString[i]-48);
//             }
//             numArray[j] = tempNum;
//             tempNum = 0;
//         }
//         for (int i = 0; i<=size; i++){
//             std::cout<< numArray[i] << " ";
//         }
//     }

//     return 0;
// }