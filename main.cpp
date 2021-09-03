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

    std::string type;
    std::string number;


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
    std::cout << number << std::endl;
    Number test(type, number);
    test.printOtherTypes();


    return 0;
}
