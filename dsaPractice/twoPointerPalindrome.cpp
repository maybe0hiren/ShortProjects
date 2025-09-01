#include <iostream>

int count(int number){
    int counter = 0;
    while (number >= 1){
        number = number/10;
        counter++;
    }
    return counter;
}

void reverseArray(int arr[],int size){
    for(int i = 0; i<size/2; i++){
        std::swap(arr[i], arr[size-i-1]);
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i<size; i++){
        std::cout << arr[i] << " ";
    }
}

int main(){
    int number = 11211;
    int digits = count(number);
    int numArray[digits];
    int count = 0;

    for (int i = 0; i<digits; i++){
        numArray[i] = number%10;
        number = number/10;
    }

    reverseArray(numArray, digits);
    int *pStart = &numArray[0];
    int *pEnd = &numArray[digits-1];

    for (pEnd,pStart; pEnd>=pStart; pStart++, pEnd--){
        if(*pEnd != *pStart){
            count++;
        }
    }
    if (count>0){
        std::cout << "Not a Palindrome";
    }
    else{
        std::cout << "Palindrome";
    }
    return 0;
}