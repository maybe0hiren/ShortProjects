#include <iostream>

int main(){
    int arrayStraight[] = {12,31,23,24,23,4,35,34,6,457,6786,7,5,35,4,344,64,66,76,8};
    int arrayReverse[sizeof(arrayStraight)/4];
    for (int i=0; i<sizeof(arrayStraight)/4;i++){
        arrayReverse[i] = arrayStraight[sizeof(arrayReverse)/4-1-i];
    }
    for (int i = 0; i<sizeof(arrayReverse)/4;i++){
        std::cout<< arrayReverse[i] << " ";
    }
    return 0;
}   