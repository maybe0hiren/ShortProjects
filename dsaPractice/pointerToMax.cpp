#include <iostream>

int main(){
    int a = 10, b = 35, c = 22;
    int *pGreatest = NULL;

    if (a<=b){
        if (b<=c){
            pGreatest = &c;
        }
        else{
            pGreatest = &b;
        }
    }
    else{
        if (a<=c){
            pGreatest = &c;
        }
        else{
            pGreatest = &a;
        }
    }

    std::cout << pGreatest << " " << *pGreatest;
    return 0;
}