#include <iostream>
#include <vector>

int trueCounter(std::string r){
    int counter = 0;
    for (int i = 0; i<r.size(); i++){
        if(r[i] == '1'){
            counter++;
        }
    }
    return counter;
}

int main(){
    int beam = 0;
    int ptr1 = 0, ptr2 = 1;
    std::vector<std::string> bank = {"011001","010100","000000","001000"};
    int ptr1True, ptr2True;
    while(ptr1 < bank.size()-1){
        ptr1True = trueCounter(bank[ptr1]);
        ptr2True = trueCounter(bank[ptr2]);
        if(ptr2True != 0){
            ptr1 = ptr2;
            beam += ptr1True*ptr2True;
        }
        ptr2++;
    }
    std::cout << beam;
    
    return 0;
}