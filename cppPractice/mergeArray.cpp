#include <iostream>

int main(){
    int array1[] = {12,31,23,24,23,4,35,34,6,457,6786,7,5,35,4,344,64,66,76,8};
    int array2[] = {12,3,12,23,4,5,5,65,68,79,78,56,5,8,76,4,4535,567};

    int newArray[(sizeof(array1) + sizeof(array2))/4];

    for (int i=0; i<sizeof(array1)/4; i++){
        newArray[i] = array1[i];
    }
    for (int i=0; i<sizeof(array2)/4; i++){
        newArray[(sizeof(array1)/4)+i] = array2[i];
    }
    for (int i=0; i<sizeof(newArray)/4; i++){
        std::cout << newArray[i] << " ";
    }
    return 0;
}