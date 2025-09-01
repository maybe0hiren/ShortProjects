#include <iostream>

int main(){
    int numbArr[] = {12,46,785,23,345,66,57,88,74,13,24,5,67,9,785,645};
    for (int i = 0; i<sizeof(numbArr)/4; i++){
        std::cout << *(numbArr + i) << " ";
    }
    return 0;
}