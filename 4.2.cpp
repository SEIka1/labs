#include <iostream>
void nums(size_t);


int result = 0;
int main()
{
    size_t number = 0;
    std::cin >> number;
    nums(number);
    std::cout << result;
}

void nums(size_t a)
{
    while (a)
    {
        if (a % 2 != 0)
        {
            result++;

        }
        a /= 2;
    }
}