#include <iostream>
#include <vector>

int main(){
    std::vector<std::vector<std::string>> items = {{"phone","blue","pixel"},{"computer","silver","phone"},{"phone","gold","iphone"}};
    std::string ruleKey = "type";
    std::string ruleValue = "phone";
    int valuePosition;
        int count = 0;
        if (ruleKey == "type"){
            valuePosition = 0;
        }
        else if (ruleKey == "color"){
            valuePosition = 1;
        }
        else{
            valuePosition = 2;
        }
        for(int i = 0; i<items.size(); i++){
            if (items[i][valuePosition] == ruleValue){
                count++;
            }
        }
    std::cout << count;
    return 0;
}