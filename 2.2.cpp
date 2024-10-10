#include <iostream>

int fabs(int x) {
    if (x < 0) {
        return -x;
    }

    return x;
}
int main() {
    int a, b, c{};
    std::cin >> a >> b >> c;
    int q = (fabs(a) % 2) + (fabs(b) % 2) + (fabs(c) % 2);
    
    q > 0 && q < 3 ? std::cout << "YES\n" : std::cout << "NO\n";
}