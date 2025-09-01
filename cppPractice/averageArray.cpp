#include <iostream>

int main(){
    float sum = 0;
    int numArray[] = {12,4,34,3,45,46,4,54,35,4,5,34,5,45,3,42,34,2342};
    int numbOfElements = sizeof(numArray)/4;
    float average;
    for (int i = 0; i<numbOfElements; i++){
        sum = sum + numArray[i];
    }
    average = sum/numbOfElements;
    std::cout<< "The average of the array is: " << average;
}