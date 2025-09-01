#include <iostream>

int main(){
    int count = 1;
    int min, max;
    int numArray[] = {12,54,75,234,764,11};
    for (int i = 0; i<sizeof(numArray)/4; i++){
        for (int j = 0; j<sizeof(numArray)/4; j++){
            if(numArray[i] < numArray[j]){
                count++;
            }
        }
        if (count == 0){
            max = numArray[i];
        }
        count = 0;
    }
    std::cout<< "Max: " << max << "\n";
    for (int i = 0; i<sizeof(numArray)/4; i++){
        for (int j = 0; j<sizeof(numArray)/4; j++){
            if(numArray[i] > numArray[j]){
                count++;
            }
        }
        if (count == 0){
            min = numArray[i];
        }
        count = 0;
    }
    std::cout<< "Min: " << min << "\n";
}