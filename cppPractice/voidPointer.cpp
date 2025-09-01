#include <iostream>

int main(){
    int variable = 100;
    void *pVariable = &variable;
    std::cout<< pVariable << "\n";
}