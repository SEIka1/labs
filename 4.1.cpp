#include <iostream>
int main()
{
    int b = 0;
    int number = 0;
    std::cin >> number;

    if (number > 0)
    {

        for (int i = 1; i < number; i++)
        {
            if (number % i == 0)
                b += i;
        }
        if (number == b)
        {
            std::cout << "TRUE";
        }
        else
        {
            std::cout << "FALSE";
        }
    }
    else std::cerr << "ERROR:not a natural number";
    return 0;
    
}