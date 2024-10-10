#include <iostream>


void isName(char *name);


char const letters_and_numbers[62]
{
    'a' , 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
};

int counter = 0;
int anticounter = 0;
int length = 0;
int counter_ = 0;
int count_errors = 0;

char name[100];
int main()
{
    std::cin >> name;
    isName(name);
}

void isName(char *name)
{

    if (name[0] == '1' || name[0] == '2' || name[0] == '3' || name[0] == '4' || name[0] == '5' ||
        name[0] == '6' || name[0] == '7' || name[0] == '8' || name[0] == '9' || name[0] == '0') 
        std::cout << "false";
    else {
        int i = 0;
        while (name[i] != '\0') {
            for (int j = 0; j < 62; j++) {
                if (name[i] == letters_and_numbers[j]) 
                    counter++;
                
                
            }
            if (name[i] == '_') {
                counter_++;
                counter++;
            }
            if (counter == 0)
                count_errors++;
            length++;
            i++;
        }
        if (counter_ == length || counter == 0 || count_errors > 0 || counter < length)
           std::cout << "false";
        else std::cout << "true";

    }
}
