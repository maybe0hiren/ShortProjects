#include <iostream>

int main(){
    int numArray[] = {23,23,42,123,432,3435,576,56,42,75,6756,452,3435,225,56,8,1};
    int newArray[sizeof(numArray)/4];
    int number;
    std::cout<< "Enter the number: ";
    std::cin>> number;
    for (int i = 0; i<sizeof(numArray)/4; i++){
        if (numArray[i] != number){
            newArray[i] = numArray[i];
        }
        else{
            newArray[i] = 0;
        }
    }
    for (int i = 0; i<sizeof(newArray)/4;i++){
        std::cout<< newArray[i] << " ";
    }

}