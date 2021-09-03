#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

//testing file
#include "../../includes/Number/Number.h"

using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_decimal_to_binary (bool debug = false)
{
  string type = "Decimal";
  string decNum = "55";
  string binNum = "110111";

  Number num(type, decNum);

  if(num.decToBin(decNum) !=  binNum)
  {
    cout << "FAILED: Expected the result to be " << binNum 
         << ", but returned " << num.decToBin(decNum) << " instead." << endl;
    return false;
  }

  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_CONVERT, TestDecToBin) {
  EXPECT_EQ(1, test_decimal_to_binary(true));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

