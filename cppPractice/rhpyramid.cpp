#include <iostream>

int i = 0;
std::string rightHalfPyramid(int rows){
    if (i>=rows){
        return "";
    }
    else{
        std::string stars = rightHalfPyramid(rows-1) + "*";
        std::cout<< stars << "\n";
        i++;
        return stars;
    }
}


int main(){
    int rows;
    std::cout<< "Enter the number of rows: ";
    std::cin>> rows;
    rightHalfPyramid(rows);
    return 0;
}