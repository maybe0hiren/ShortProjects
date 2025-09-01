#include <iostream>

void printPointer(int *pointer){
    std::cout << pointer << " \n";
}


int main(){
    int variable1 = 500;
    int variable2 = 501;

    int *pReferencePointer = &variable1;
    int *&pPointer = pReferencePointer; //pPointer is not a copy of pReferencePointer, it acts as a second name for it.

    printPointer(pPointer);

    pReferencePointer = &variable2;

    printPointer(pPointer);
    return 0;
}