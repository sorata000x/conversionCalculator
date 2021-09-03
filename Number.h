
#ifndef _NUMBER_H
#define _NUMBER_H
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <math.h>
#include <algorithm>


class Number {
public:
    enum base {
        BINARY=0, HEX, OCTAL, DECIMAL, NA
    };
    static base enumOfIndex(int i);
    Number(base type);
    Number(std::string type, std::string data);
    void assign(std::string data);
    void print() const;
    void printOtherTypes();
    base getBase() const;
    static std::string enumToString(int value);
    std::string getData() const;

    // used to get other data types to binary
    static std::string byteToHex(const std::string& input);
    static std::string hexToByte(char input);
    static std::string hexToBin(std::string input);

    // used to get binary to other data types
    static std::string binToOct(std::string input);
    static std::string binToHex(std::string input);
    static std::string binToDec(std::string input);
    static base stringToBase(std::string input);
private:

    base type;
    std::string data;
};


#endif //LAB1_5_CS66_NUMBER_H
