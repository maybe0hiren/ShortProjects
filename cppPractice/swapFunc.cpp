#include <iostream>

void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

int main(){
    int a = 5;
    int b = 5;
    swap(a,b);
    std::cout<< a << " " << b;
    return 0;
}