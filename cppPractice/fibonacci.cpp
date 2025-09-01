#include <iostream>
int number, element=1;
int main(){
    std::cout<< "Enter the number of terms: ";
    std::cin>> number;
    if (number == 0){
        std::cout<< " ";
    }
    else if (number == 1){
        std::cout<< "1";
    }
    else{
        int temp1 = 0;
        int temp2 = 1;
        for (int i = 1; i<=number; i++){
            std::cout<< element << " ";
            element = temp1 + temp2;
            temp1 = temp2;
            temp2 = element;
        }   
    }
    return 0;
}