#include <iostream>

int main(){
    int a,b;
    int count = 1;
    int matrix[7][7];
    for (int i = 0; i<7; i++){
        for (int j = 0; j<7; j++){
            matrix[i][j] = count;
            count++;
        }
    }
    std::cout<< "Original matrix:\n";
    for (int i = 0; i<7; i++){
        for (int j = 0; j<7; j++){
            std::cout<< matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    int transpose[7][7];
    for (int i = 0; i<7; i++){
        for (int j = 0; j<7; j++){
            transpose[i][j] = matrix[j][i];
        }
    }
    std::cout<< "Transpose matrix:\n";
    for (int i = 0; i<7; i++){
        for (int j = 0; j<7; j++){
            std::cout<< transpose[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}