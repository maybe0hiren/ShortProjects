#include <iostream>
#include <vector>

class Stack{
        std::vector <int> vec;

    public:
        void push(int element){
            vec.push_back(element);
        }

        void pop(){
            vec.pop_back();
        }

        int top(){
            return vec[vec.size()-1];
        }

        bool empty(){
            return vec.size() == 0;
        }
};

int main(){
    Stack s;

    std::cout << s.empty() << std::endl;

    s.push(100);
    s.push(80);
    s.push(123);
    s.push(765534);
    s.push(40);
    std::cout << s.empty() << std::endl;
    std::cout << s.top() << std::endl;

    s.pop();
    std::cout << s.empty() << std::endl;
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.empty() << std::endl;
    std::cout << s.top() << std::endl;


}