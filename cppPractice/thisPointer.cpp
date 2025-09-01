#include <iostream>

class integerValues{
    private:
        int x,y,z;

    public:
        integerValues(int x, int y, int z){
            // x = x is invalid because x are considered as the x in parameter and the x declared earlier is ignored
            this -> x = x; 
            this -> y = y;
            this -> z = z;
        }
        
        void printValues(){
            std::cout << "x is: " << x << std::endl;
            std::cout << "y is: " << y << std::endl;
            std::cout << "z is: " << z << std::endl;
        }
};

int main(){
    int x,y,z;
    std::cout<< "Enter the value of x: ";
    std::cin>> x;
    std::cout<< "Enter the value of y: ";
    std::cin>> y;
    std::cout<< "Enter the value of z: ";
    std::cin>> z;

    integerValues setA(x,y,z);
    setA.printValues();
    return 0;   
}