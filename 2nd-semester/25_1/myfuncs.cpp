#include <algorithm>
#include <cassert>
#include <clocale>
#include <cmath>
#include "constants.h"
#include <iostream>
#include <sstream> // for std::stringstream
#include <string>

unsigned long long convertArgumentToUll(char* argument)
{
    unsigned long long ullArgument{};
    std::stringstream convert{ argument };
    assert(convert >> ullArgument && "Не удалось сконвертировать аргумент коммандой строки");
    return ullArgument;
}

void solve(int argc, char* argv[])
{
    std::setlocale(LC_ALL, "RUS");

    if (argc != constants::numberOfArguments)
    {
        std::cerr << "Количество аргументов коммандой строки должно быть равно 3.\n";
        return;
    }

    unsigned long long numberOfBytes{ convertArgumentToUll(argv[constants::numberOfBytesIndex]) };
    unsigned long long numberOfBits{ numberOfBytes * constants::bitsInByte };
    unsigned long long number{ convertArgumentToUll(argv[constants::numberIndex]) };

    if (number >= std::pow(2, numberOfBits))
    {
        std::cerr << "Указанное число превышает отведённое число байт.\n";
        return;
    }

    std::cout << "Количество отведённых байт: " << numberOfBytes << '\n';
    std::cout << "Указанное число: " << number << '\n';

    std::string bitSequence{ argv[constants::bitSequenceIndex] };

    auto allZerosAndOnes{ std::all_of(bitSequence.begin(), bitSequence.end(),
                                    [](const char bit) {
                                        return (bit == '0' || bit == '1');
                                     }) };

    if (!allZerosAndOnes)
    {
        std::cerr << "Битовая последовательность должна состоять только из 0 и 1.\n";
        return;
    }

    std::string binaryNumber{};
    unsigned long long numberCopy{ number };

    while (numberCopy > 0)
    {
        // numberCopy % 2 evaluates to either 1 or 0
        // since the right operand should be a char, the compiler will implicitly convert it to a char
        // we can add '0' which has an ASCII number of 48 to convert it to either 0 (48 in ASCII) or 1 (49 in ASCII)
        binaryNumber += numberCopy % 2 + '0';
        numberCopy /= 2;
    }
    std::reverse(binaryNumber.begin(), binaryNumber.end());

    unsigned long long zerosToAdd{ numberOfBits - binaryNumber.size() };
    binaryNumber.insert(0, zerosToAdd, '0');

    std::cout << "Указанное число в двоичной записи: " << binaryNumber << '\n';
    std::cout << "Заданная битовая последовательность: " << bitSequence << '\n';

    if (bitSequence.size() > binaryNumber.size())
    {
        std::cerr << "Длина битовой последовательности превышает длину указанного числа.\n";
        return;
    }

    std::reverse(bitSequence.begin(), bitSequence.end());
    unsigned long long mask{};
    unsigned long long ullBitSequence{};

    for (int i{ 0 }; i < bitSequence.size(); ++i)
    {
        // getting a ull of bitSequence by setting 1 or 0 using bitwise AND and shifting it to the right by i
        ullBitSequence |= (bitSequence[i] & 1ull) << i;
        // mask is full of 1's
        mask |= 1ull << i;
    }

    int shift{ 0 };
    auto sizeDifference{ numberOfBits - bitSequence.size() };

    for (int i{ static_cast<int>(sizeDifference) }; i >= 0; --i)
    {
        // if a xor b == 0, then the numbers are equal
        if (!((number & (mask << shift)) ^ (ullBitSequence << shift)))
        {
            std::cout << "\nПоследнее вхождение битовой последовательности - с " << i << " по "
                << i + bitSequence.size() - 1 << " индексы включительно.\n";
            return;
        }
        ++shift;
    }

    std::cout << "\nБитовая последовательность не найдена.\n";
}