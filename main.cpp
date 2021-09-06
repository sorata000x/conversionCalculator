#include <iostream>
#include <string>
#include <cmath>
#include "Number.h"
#include<algorithm>

void removeSpace(std::string &input)
{
    std::string hold;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] != ' ')
        {
            hold += input[i];
        }
    }

    input = hold;
}

void check(std::string &input)
{
    std::string hold;

    int remainder = input.size()%4;
    int add = 4-remainder;

    if (remainder != 0)
    {
        for (int i = 0; i < add; i++)
        {
            hold += "0";
        }
    }
    hold += input;

    input = hold;
}


int main() {

    bool run = true;

    while(run)
    {
        std::string type;
        std::string number;
        char key;

        std::cout << "Type Ex: Hex Decimal Binary Octal" << std::endl;
        std::cout << "Enter number type: ";
        std::cin >>  type;
        std::cout << "Now enter the number: ";
        std::cin >> number;
        removeSpace(number);
        if (Number::BINARY == Number::stringToBase(type))
        {
            check(number);
        }
        Number test(type, number);
        test.printOtherTypes();

        std::cout << "Do you want to try again(ex: y / n): ";
        std::cin >> key;

        if (key == 'n')
        {
            run = false;
        }
    }



    return 0;
}
