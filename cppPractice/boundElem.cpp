#include <iostream>

int main(){
    int count = 1;
    int matrix[7][7];
    for (int i = 0; i<7; i++){
        for (int j = 0; j<7; j++){
            matrix[i][j] = count;
            count++;
        }
    }
    for (int i = 0; i<7; i++){
        for (int j = 0; j<7; j++){
            if ((i == 0) || (i == 6) || (j == 0) || (j == 6)){
                std::cout<< matrix[i][j] << " ";
            }
        }
    }
    return 0;
}