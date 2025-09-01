#include <iostream>

void printHelloWorld(int x){
    for (int i = 0; i<x; i++){
        std::cout << "Hello World -- " << i+1 << std::endl;
    }
}

int main(){
    typedef void (*functPointer)(int);
    functPointer hlwWrld = printHelloWorld;


    hlwWrld(100);
    return 0;
}