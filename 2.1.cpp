#include <iostream>

int main()
{
	int x = 0;
	int max = -1000;
	int i = 0;
	std::cout << "Enter three numbers: \n";
	for (; i < 3; i++) {
		std::cin >> x;
		max = (max > x ? max : x);
	}
	std::cout << max << '\n';
}	