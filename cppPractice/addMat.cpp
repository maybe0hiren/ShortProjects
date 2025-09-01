#include <iostream>

int main(){
    int matrix1[3][3] = {{43,565,2},{123,534,67},{876,7234,65}};
    int matrix2[3][3] = {{64,234,876},{23,876,1},{5,675,123}};
    int addMatrix[3][3];
    for (int column = 0; column<3; column++){
        for (int row = 0; row<3; row++){
            addMatrix[row][column] = matrix1[row][column] + matrix2[row][column];
        }
    }
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            std::cout<< addMatrix[i][j] << " ";
        }
        std::cout<<"\n";
    }
    return 0;
}