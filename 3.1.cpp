#include <iostream>
int main() {
    
    int number = 1;
    int sum = 0;
    size_t positives = 0;
    size_t i = 0;
    size_t j =0;
    int ifpositive = 0;
    size_t sumpositive = 0;
    int maximum = -9999999;
    int minimumpositive = 99999999 ;
    while (number)
    {  
        std::cin >> number;
        if (number == 0) break;
        sum += number;
        i++;
        if (number > 0) {
            j++;
            sumpositive += number;
            if (number < minimumpositive) minimumpositive = number;
        }
        if (number > maximum) maximum = number;
    }
    if (sum == 0) std::cout << "ERROR: Empty sequence";
    else {
        std::cout << "Arithmetic mean of all numbers = " << (double)sum / i << '\n';
        std::cout << "Maximum value = " << maximum << '\n';
        if (j == 0 && sum != 0) std::cout << "ERROR: Not positive numbers in the sequence";
        else {


            std::cout << "Arithmetic mean of positive numbers = " << (double)sumpositive / j << '\n';
            std::cout << "Minimum positive number = " << minimumpositive << '\n';


        }
    } 
    
     


}