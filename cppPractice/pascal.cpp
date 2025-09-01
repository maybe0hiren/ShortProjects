#include <iostream>

int factorial(int number){
    if (number == 0){
        return 1;
    }
    else{
        return number*factorial(number-1);
    }
}

int main(){
    int rows;
    std::cout<< "Enter the number of rows: ";
    std::cin>> rows;
    rows--;
    for (int currentRow = 0; currentRow<=rows; currentRow++){
        for (int position = 0; position<=currentRow; position++){
            int element = (factorial(currentRow))/(factorial(position)*factorial(currentRow-position));
            std::cout<< element << " ";
        }
        std::cout<< "\n";
    }
    return 0;
}