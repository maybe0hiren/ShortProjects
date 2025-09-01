#include <iostream>
#include <math.h>

int main(){
    double principal, n, rate, years, CI, powerValue, base, power;
    std::cout<< "Enter the Principal amount: ";
    std::cin>> principal;
    std::cout<< "Enter the Interest Rate: ";
    std::cin>> rate;
    std::cout<< "Enter the number of times the rate is compounded annually: ";
    std::cin>> n;
    std::cout<< "Enter the number of years: ";
    std::cin>> years;

    base = 1+(rate/n);
    power = n*years;
    powerValue = pow(base, power);
    CI = principal*powerValue - principal;

    std::cout<< "The compound interest is: " << 1+(rate/n);
    return 0;
}