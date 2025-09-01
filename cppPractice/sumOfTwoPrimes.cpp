#include <iostream>

bool checkPrime(int number){
    int count = 0;
    for (int i=1; i<=number; i++){
        if (number%i == 0){
            count++;
        }
    }
    return (count==2);
}


int main(){
    int sum;
    int count = 0;
    std::cout<< "Enter the number: ";
    std::cin>> sum;
    int primeArray[sum];
    for (int i=1; i<=sum; i++){
        for (int j = i-1; j<=sum-1; j++){
            if (checkPrime(i) == true){
                primeArray[j] = i;
            }
            else{
                primeArray[j] = 0;
            }
        }
    }
    for (int i = 0; i<=sum-1; i++){
        for (int j = 0; j<=sum-1; j++){
            if (primeArray[i]+primeArray[j] == sum && primeArray[i] != 0 && primeArray[j] != 0){
                std::cout<< "Yes, " << sum << " can be represented at a sum of " << primeArray[i] << " and " << primeArray[j] << "." << "\n";
            }
            else{
                count++;
            }
        }
    }
    if (count == sum*sum){
        std::cout<< "No, " << sum << " cannot be represented as a sum of 2 prime numbers.";
    }
    return 0;
}