//#include "gtest/gtest.h"
//tried making this work but I'm too stupid to figure it out

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

//testing file
#include "Number.h"
#include "Number.cpp"

using namespace std;



void TEST(std::string testName, bool test = false)
{
  std::cout << "TEST: " << testName << std::endl;

  if (test == true)
  {
    std::cout << "PASSED." << std::endl << std::endl;
  }

}

struct RandomInput
{
  string randomInputBinary[24] = 
  {
  "00001111", "001111101001", "001111101000", "011111100100", 
  "0001001110001000", "000010101010111001100111", "1011", "11110110", 
  "1101", "11110010", "11110101", "11110100", 
  "11110001", "11101000", "01000000", "00111111",
  "00011111", "00100000", "00011001", "1111000001100000", 
  "00110111", "01111010", "000010001111", "00100111"
  };
  string randomInputDec[24] = 
  {
  "15", "1001", "1000", "2020", 
  "5000", "700007", "-5", "-10", 
  "-3", "-14", "-11", "-12", 
  "-15", "-24", "64", "63",
  "31", "32", "25", "-4000", 
  "55", "122", "143", "39"
  };
  string randomInputHex[24] = 
  {
  "F", "3E9", "3E8", "7E4",  
  "1388", "AAE67", "B", "F6", 
  "D", "F2", "F5", "F4", 
  "F1", "E8", "40", "3F",
  "1F", "20", "19", "F060", 
  "37", "7A", "8F", "27"
  };
  string randomInputOctal[24] = 
  {
  "17", "1751", "1750", "3744", 
  "11610", "2527147", "13", "366", 
  "15", "362", "365", "364", 
  "361", "350", "100", "77",
  "37", "40", "31", "170140", 
  "67", "172", "217", "47"
  };

  int randomIndex()
  {
    return (rand() % 23);
  }
 
};



bool test_binary_to_Hex (bool debug = false)
{

  RandomInput r;
  int index = r.randomIndex();
  string type = "Binary";
  string input =  r.randomInputBinary[index];
  string expectedHex = r.randomInputHex[index];

  Number num(type, input);

  if(num.binToHex(input) !=  expectedHex)
  {
    cout << "FAILED: Expected the result to be " << expectedHex
         << ", but returned " << num.binToHex(input) << " instead." << endl;
    return false;
  }

  return true;
}

bool test_binary_to_dec (bool debug = false)
{
  RandomInput r;
  int index = r.randomIndex();
  string type = "Binary";
  string input =  r.randomInputBinary[index];
  string expectedDec = r.randomInputDec[index];

  Number num(type, input);

  if(num.binToDec(input) !=  expectedDec)
  {
    cout << "FAILED: Expected the result to be " << expectedDec 
         << ", but returned " << num.binToDec(input) << " instead." << endl;
    return false;
  }

  return true;
}

bool test_binary_to_oct (bool debug = false)
{
  RandomInput r;
  int index = r.randomIndex();
  string type = "Binary";
  string input =  r.randomInputBinary[index];
  string expectedOct = r.randomInputOctal[index];

  Number num(type, input);

  if(num.binToOct(input) !=  expectedOct)
  {
    cout << "FAILED: Expected the result to be " << expectedOct 
         << ", but returned " << num.binToOct(input) << " instead." << endl;
    return false;
  }

  return true;
}

bool test_oct_to_binary (bool debug = false)
{
  RandomInput r;
  int index = r.randomIndex();
  string type = "Binary";
  string input =  r.randomInputOctal[index];
  string expectedBin = r.randomInputBinary[index];

  Number num(type, input);

  if(num.octalToBin(input) !=  expectedBin)
  {
    cout << "FAILED: Expected the result to be " << expectedBin 
         << ", but returned " << num.octalToBin(input) << " instead." << endl;
    return false;
  }

  return true;
}

bool test_decimal_to_binary (bool debug = false)
{
  string type = "Decimal";
  string decNum = "55";
  string binNum = "00110111";

  Number num(type, decNum);

  if(num.decToBin(decNum) !=  binNum)
  {
    cout << "FAILED: Expected the result to be " << binNum 
         << ", but returned " << num.decToBin(decNum) << " instead." << endl;
    return false;
  }

  return true;
}

bool test_hex_to_binary (bool debug = false)
{
  RandomInput r;
  int index = r.randomIndex();
  string type = "Binary";
  string input =  r.randomInputHex[index];
  string expectedBin = r.randomInputBinary[index];

  Number num(type, input);

  if(num.hexToBin(input) !=  expectedBin)
  {
    cout << "FAILED: Expected the result to be " << expectedBin 
         << ", but returned " << num.hexToBin(input) << " instead." << endl;
    return false;
  }

  return true;
}

int main() 
{
  srand(time(NULL));
  TEST("BINARY TO HEX", test_binary_to_Hex);
  TEST("BINARY TO DECIMAL", test_binary_to_dec);
  TEST("BINARY TO OCTAL", test_binary_to_oct);
  TEST("HEX TO BINARY", test_hex_to_binary);
  TEST("DECIMAL TO BINARY", test_decimal_to_binary);
  TEST("OCTAL TO BINARY", test_oct_to_binary);


  std::cout << "FINISHED." << std::endl;
}

