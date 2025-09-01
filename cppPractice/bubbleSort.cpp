#include <iostream>

void printArray(int array[], int size){
    for (int i = 0; i<size; i++){
        std::cout<< array[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int temp;
    int numberArray[] = {34,8,32,31,79,89,7565,32,56,788,9878,675645,31};
    for (int i = 0; i<sizeof(numberArray)/4; i++){
        for (int j = 0; j<sizeof(numberArray)/4 - i; j++){
            if(numberArray[j]>numberArray[j+1]){
                temp = numberArray[j];
                numberArray[j] = numberArray[j+1];
                numberArray[j+1] = temp;
            }
        }
    }
    printArray(numberArray, sizeof(numberArray)/4);
    return 0;
}