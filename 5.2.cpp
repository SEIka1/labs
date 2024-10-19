#include <iostream>
#include <cstring>

char nonUniqueString[100];
char uniqueString[100];
int length = 0;

char* getUniqueString(char* unqieString, const char* nonUniqueString)
{   
    int k = 0;
    int unik = 0;
    int t = 0;
    int errcounter = 0;
    
    for (int i = 0; i < strlen(nonUniqueString); i++)
    {
        t = 0;
        for (int j = 0; j < strlen(nonUniqueString); j++)
            if (nonUniqueString[i] == nonUniqueString[j]) {
                t++;
                errcounter++;
            }
        if (t == 1) {
            uniqueString[k] = nonUniqueString[i];
            k++;
        }
    }
    if (k == 0)
    {
        std::cerr << "No unique symbols";
    }
    return uniqueString;
}
int main() {
    int errcounter = 0;
    
    std::cin >> nonUniqueString;
    for (int i = 0; i < strlen(nonUniqueString); i++) {
        for (int j = 0; j < strlen(nonUniqueString); j++)
            if (nonUniqueString[i] == nonUniqueString[j])
                errcounter++;
    }
    if ((errcounter / strlen(nonUniqueString) == strlen(nonUniqueString)) && strlen(nonUniqueString) > 1)
        std::cerr << "No unique symbols";
    else {
        try {
            std::cout << getUniqueString(uniqueString, nonUniqueString);
        }
        catch (std::invalid_argument)
        {
            throw "Invalid value: ";
        }
        return 0;
    }
}
