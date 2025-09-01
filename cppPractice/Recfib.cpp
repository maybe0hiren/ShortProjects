#include <iostream>

int fibo(int limit){
    if (limit<=1){
        return limit;
    }
    else{
        return fibo(limit-1)+fibo(limit-2);
    }
}

int main(){
    int limit;
    std::cout<< "Enter the number of terms: ";
    std::cin>> limit;
    for (int i=0; i<=limit-1; i++){
        std::cout<< fibo(i) << " ";
    }
    return 0;
}