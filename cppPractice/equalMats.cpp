#include <iostream>

int main(){
    int matrix1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int matrix2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int count = 0;
    for (int i = 0; i<3;i++){
        for (int j = 0; j<3; j++){
            if (matrix1[i][j] != matrix2[i][j]){
                count++;
                std::cout << "a" << i << j << " not equal to " << "b" << i << j << "\n";
            }
        }
    }
    if(count>0){
        std::cout << "No, the matrices are not equal";
    }
    else{
        std::cout << "Yes the matrices are equal";
    }
    return 0;
}