#include <iostream>

int main(){
    int array1[] = {12,31,23,24,23,4,35,34,6,457,6786,7,5,35,4,344,64,66,76,8};
    int array2[] = {12,3,12,23,4,5,5,65,68,79,78,56,5,8,76,4,4535,567};
    for (int i=0; i<sizeof(array1)/4; i++){
        for (int j=0; j<sizeof(array2)/4; j++){
            if (array1[i] == array2[j]){
                std::cout<< array1[i] << " ";
            }
        }
    }
    return 0;
}