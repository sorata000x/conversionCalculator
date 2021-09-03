#include "Number.h"
#include <utility>

Number::Number(Number::base type) : type(type) {}
Number::Number(std::string type, std::string input) : type(stringToBase(std::move(type))), data(std::move(input)) {}

Number::base Number::stringToBase(std::string input)
{
    std::string hold = std::move(input);

    std::for_each(hold.begin(), hold.end(), [](char & c) {
        c = ::toupper(c);
    });

    for (int i = 0; i < 4; i++)
    {
        if (enumToString(i) == hold)
        {
           return enumOfIndex(i);
        }
    }

    return Number::NA;

}

Number::base Number::enumOfIndex(int i) {return static_cast<base>(i);}

std::string Number::enumToString(int value)
{
    switch(value)
    {
        case BINARY: return "BINARY";
        case HEX: return "HEX";
        case OCTAL: return "OCTAL";
        case DECIMAL: return "DECIMAL";
        default:
            return "NA";
    }

}

void Number::assign(std::string input){
    this->data = std::move(input);
}

void Number::print() const {
    std::cout << data << std::endl;
}

std::string addBinary(std::string a, std::string b)
{
    std::string result = ""; // Initialize result
    int s = 0;          // Initialize digit sum

    // Traverse both strings starting from last
    // characters
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        // Comput sum of last digits and carry
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);

        // If current digit sum is 1 or 3, add 1 to result
        result = char(s % 2 + '0') + result;

        // Compute carry
        s /= 2;

        // Move to next digits
        i--; j--;
    }
    return result;
}


Number::base Number::getBase() const
{
    return type;
}

std::string Number::getData() const {return data;}

void Number::printOtherTypes()
{
    std::string hold;

    switch(type)
    {
        case NA : std::cout << "no data type" << std::endl;
            break;
        case BINARY:
            hold = data;
            break;
        default:
            hold = hexToBin(data);
            break;
    }

    std::cout << "Binary: " << hold << std::endl;
    std::cout << "Decimal: " <<  binToDec(hold) << std::endl;
    std::cout << "Hex: " << binToHex(hold) << std::endl;
    std::cout << "Octal: " << binToOct(hold) << std::endl;
}

std::string Number::byteToHex(const std::string& input)
{
    // input ex: 0001
    int byte = std::stoi(input);
    switch(byte)
    {
        case 0: return "0";
        case 1: return "1";
        case 10: return"2";
        case 11: return "3";
        case 100: return "4";
        case 101: return "5";
        case 110: return "6";
        case 111: return "7";
        case 1000: return "8";
        case 1001: return "9";
        case 1010: return "A";
        case 1011: return "B";
        case 1100: return "C";
        case 1101: return "D";
        case 1110: return "E";
        case 1111: return "F";
    }
    return NULL;
}

std::string Number::hexToByte(char input)
{
    switch(input)
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }

    return NULL;
}

std::string Number::binToOct(std::string input) {
    // data input ex: 100 010 101 Note: no spaces
    // this byte is only three binary numbers ex:: 000 111 101 100
    std::string hold;
    int remainder = input.size()%3;
    int add = 3-remainder;

    if (remainder != 0 )
    {
        for (int i = 0; i < add; i++)
        {
            hold += "0";
        }
    }
    hold += input;
    int bytes = hold.size()/3;
    std::string byte = "";
    std::string oct = "";

    for (int i = 0; i < bytes; i++)
    {
        for (int j = i*3; j < (i*3)+3; j++)
        {
            byte += hold[j];
        }
        oct += byteToHex(byte);
        byte = "";
    }

    if (oct[0] == '0')
    {
        oct.erase(0, 1);
    }
    return oct;
}

std::string Number::binToHex(std::string input)
{
// data input ex: 10001010
    // bad input ex: 0000 1010
    // make sure no 0000 gets added and no spaces

    int bytes = input.size()/4;
    std::string byte;
    std::string hex = "";

    for (int i = 0; i < bytes; i++)
    {
        for (int j = i*4; j < (i*4)+4; j++)
        {
            byte += input[j];
        }

        hex += byteToHex(byte);
        byte = "";
    }

    return hex;
}

std::string Number::binToDec(std::string input) {
    int total = 0;
    bool negative = false;
    std::string hold = "00000000";

    if (input.size() == 8 && input[0] == '1')
    {
        // then this number is a negative number;
        // we flip the binary numbers then add one;
        negative = true;
        for(int i = input.size()-1; i >=0; i--)
        {
            if (input[(input.size()-1)-i] == '1')
            {
                // then swap 1 to 0;
                hold[(input.size()-1)-i] = '0';
            }
            else
            {
                hold[(input.size()-1)-i] = '1';
            }
        }

        // add one to the numbers and turn into a decimal
        input = addBinary(hold, "00000001");
    }

    for (int i = input.size()-1; i >= 0; i--)
    {
        if (input[(input.size()-1)-i] == '1')
        {
            total += int(pow(2, i));
        }
        // else do nothing because its a zero
    }

    if (negative)
    {
        total = -(total);
    }

    return std::to_string(total);
}

std::string Number::hexToBin(std::string input) {

    std::string bin;

    for (int i = 0; i < input.size(); i++)
    {
        bin += hexToByte(input[i]);
    }

    return bin;
}