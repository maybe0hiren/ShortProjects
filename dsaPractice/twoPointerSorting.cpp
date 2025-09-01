#include <iostream>

int main(){
    int numberArray[] = {12,64,24,57,34,345,11,354,786};
    int *pBack = &numberArray[0], *pFront = &numberArray[1];

    for(pBack; pBack<&numberArray[sizeof(numberArray)/4-1];pBack++){
        
    }
}