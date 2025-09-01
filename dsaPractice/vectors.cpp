#include <iostream>
#include <vector>

void output(std::vector <int> &vec){
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
}

int main(){
    std::vector <int> vec;
    output(vec);
    vec.push_back(10);
    output(vec);
    vec.push_back(23);
    output(vec);
    vec.push_back(100);
    output(vec);
    vec.push_back(50);
    output(vec);
    vec.push_back(99);
    output(vec);
    std::cout << vec[0];
    return 0;
}