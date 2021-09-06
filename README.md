# conversionCalculator
## Description
Converting one of Decimal, Binary, Hex, Octal number input by the user to other three types of number.
<br>
Probably need also for the negative numbers (2's compliment)

> Base  Converter:
Write a program in C++ that takes a number in any base (Decimal, Binary, Hex, Octal) and converts it to all the other bases.

> Decimal should be converted to binary based on the algorithm we discussed in class and binary should be converted to hex and octal (and vice versa) by grouping the bits.

<br>

## Implimentation
- Decimal to Binary
  - remainder method: devide decimal number by 2 until the quotient become 1, and store the remainder from end to the begining.
- Decimal to Hex
  - remainder method: devide decimal number by 16 until the quotient become 1, and store the remainder from end to the begining.
- Decimal to Octal
  - remainder method: devide decimal number by 8 until the quotient become 1, and store the remainder from end to the begining.
- Binary to Decimal
  - Multiply the bit at position n by 2^n, and add all the values together (e.g. 1101 -> 1\*2^3 + 1\*2^2 + 0\*2^1 + 1*2^0)
- Hex to Decimal
  - Multiply the digit at position n by 16^n, and add all the values together (e.g. 3A5 -> 3\*16^2 + 10\*16^1 + 5*16^0)
- Octal to Decimal
  - Multiply the digit at position n by 8^n, and add all the values together (e.g. 243 -> 2\*8^2 + 4\*8^1 + 3*8^0)
- Binary to Hex
  - Approach#1
    - convert each 4 bits to 1 digitc of Hex
  - Approach#2
    - 'binary to decimal' then 'decimal to hex'
- Binary to Octal
  - Approach#1
    - convert each 3 bits to 1 digitc of Octal
  - Approach#2
    - 'binary to decimal' then 'decimal to Octal' 
- Hex to Binary
  - convert each digit of hex to 4 bits of binary through 'decimal to binary'
- Hex to Octal
  - convert from 'hex to binary' then 'binary to octal'
- Octal to Binary
  - convert each digit of octal to 3 bits of binary through 'decimal to binary'
- Octal to Hex
  - convert from 'octal to binary' then 'binary to hex'

(hint: some function are reusable)

## Output

