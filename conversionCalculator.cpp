#include "conversionCalculator.h"
#include <iostream>

void arrayAInput(int arrays[])
{
    int arr[20] = {};
    int size = 20;

    

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
    }

    std::cout << std::endl;

}


int main()
{
    arrayAInput();
}