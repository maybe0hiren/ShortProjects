#include <iostream>
#include <vector>

int main(){
    std::vector<std::string> operation = {"--X","X++","X++"};
    int X = 0;
    for(int i = 0; i<operation.size(); i++){
        if(operation[i] == "--X" || operation[i] == "X--"){
            X--;
        }
        if(operation[i] == "++X" || operation[i] == "X++"){
            X++;
        }
    }
    std::cout << X;
}