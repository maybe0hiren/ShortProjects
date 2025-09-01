#include <iostream>

int main(){
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int count = 0;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            if(i = j){
                count = count + matrix[i][j];
            }
            else{
                count = count;
            }
        }
    }
    std::cout<< count;
    return 0;
}