#include <iostream>

int main(){
    int arrayRaw[] = {23,23,42,123,432,3435,576,56,42,75,6756,452,3435,225, 56,8,1};
    int arrayFiltered[sizeof(arrayRaw)/4];
    int count = 0;

    for (int i=0; i<sizeof(arrayRaw)/4; i++){
        count = 0;
        for (int j = i+1; j<sizeof(arrayRaw)/4;j++){
            if (arrayRaw[i] == arrayRaw[j]){
                count++;
            }
        }
        if (count==0){
            arrayFiltered[i] = arrayRaw[i];
        }
        else{
            arrayFiltered[i] = 0;
        }
    }
    for (int i = 0; i<sizeof(arrayFiltered)/4;i++){
        std::cout<< arrayFiltered[i] << " ";
    }
    return 0;
}