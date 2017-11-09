#include <iostream>
#include <cmath> // abs
#include "limits.h"

void Exercise6()
{
    // Игра "Угадай число!"

    const int iTargetNum = 777;

    int iLowerBound = 0;
    int iUpperBound = 1000;

    int iMiddleNum = 0;
    int iSteps     = 0;

    while (iLowerBound != iTargetNum && iUpperBound != iTargetNum)
    {
        ++iSteps;

        iMiddleNum = iLowerBound + (iUpperBound - iLowerBound)/2;

        if (iTargetNum >= iMiddleNum)
            iLowerBound = iMiddleNum;
        else
            iUpperBound = iMiddleNum;

        std::cout << "Step #" << iSteps << ", range [" << iLowerBound
                  << " - " << iUpperBound << "] " << std::endl;
    }

    std::cout << "Found in " << iSteps << " steps." << std::endl;
}

void Exercise5()
{
    //Exercise5: найти среднее арифметическое введённых пользователем чисел
    //(количество вводимых чисел заранее неизвестно)

    std::cout << "Enter numbers to find arithmetical mean, "
                 "cancel input with ctrl+c" << std::endl;

    int iInput = 0;
    int iSum   = 0;
    int iCount = 0;

    double iMeanNumber = 0;

    while(std::cin >> iInput)
    {
        iSum += iInput;
        ++iCount;
    }

    if (iCount) //protect from /0
    {
        iMeanNumber = ((double) iSum)/((double) iCount);
        std::cout << "Arithmetical mean is: " << iMeanNumber << std::endl;
    }
}

void Exercise4()
{
    //Exercise4:  подсчитать количество пар таких бит в числе, которые состоят из 1 и 0
    //1011011000 -> 10 11 01 10 00 -> 3

    int iBaseInt = 175000;
    const int iLastTwoBitsMask = 3; // 11
    int iPairsCount = 0;

    while(iBaseInt)
    {
        int iLastTwoBits = iBaseInt & iLastTwoBitsMask;

        if (iLastTwoBits == 1 || iLastTwoBits == 2)
            ++iPairsCount;

//        if ((iLastTwoBits ^ iLastTwoBitsMask) && (iLastTwoBits & iLastTwoBitsMask))
//            ++iPairsCount; //xor variant

        iBaseInt >>= 2;
    }

    std::cout << "Pairs: " << iPairsCount << std::endl;
}

void Exercise3()
{
    //Exercise3: найти количество единичных бит в заданном числе

    int iBaseInt = 150000;

    const int iSoloBitMask = 1;
    int iActiveBitsCount   = 0;

    while(iBaseInt)
    {
        if (iSoloBitMask & iBaseInt)
            ++iActiveBitsCount;

        iBaseInt >>= 1;
    }

    std::cout << "Active bits: " << iActiveBitsCount << std::endl;
}

void Exercise2NoUB()
{
    //Exercise2: найти минимальное и максимальное по модулю значения
    //в введённой последовательности (на выбор)

    std::cout << "Enter numbers to get absolute minimum and maximum, "
                 "cancel input with ctrl+c" << std::endl;

    int iMaximum(-1);
    int iMinimum(INT_MAX);

    int iOutputMax = 0;
    int iOutputMin = 0;

    int iInput = 0;

    while (std::cin >> iInput)
    {
        int iAbsInput = std::abs(iInput);

        if (iAbsInput > iMaximum)
        {
            iMaximum = iAbsInput;
            iOutputMax = iInput;
        }

        if (iAbsInput < iMinimum)
        {
            iMinimum = iAbsInput;
            iOutputMin = iInput;
        }
    }

    std::cout << "Abs maximum is " << iOutputMax << std::endl;
    std::cout << "Abs minimum is " << iOutputMin << std::endl;
}

void Exercise2UB() //using UB
{
    //Exercise2: найти минимальное и максимальное по модулю значения
    //в введённой последовательности (на выбор)

    std::cout << "Enter numbers to get absolute minimum and maximum, "
                 "cancel input with ctrl+c" << std::endl;

    int iMaximum(INT_MIN);
    int iMinimum(INT_MAX);

    int iInput(0);

    while (std::cin >> iInput)
    {
        int iAbsInput = std::abs(iInput);

        if (iAbsInput > std::abs(iMaximum)) // care: UB abs(INT_MIN) = INT_MIN
            iMaximum = iInput;

        if (iAbsInput < std::abs(iMinimum))
            iMinimum = iInput;
    }

    std::cout << "Abs maximum is " << iMaximum << std::endl;
    std::cout << "Abs minimum is " << iMinimum << std::endl;
}

void Exercise1()
{
    //Exercise1: вычислить сумму всех введённых элементов пользователем
    //до первого значения, которое делится на 7

    int iInput = 0;
    int iSum = 0;

    std::cout << "Enter numbers to sum them (cancel at input, which is divided by 7)" << std::endl;

    while (std::cin >> iInput)
    {
        if (!(iInput % 7))
            break;

        iSum += iInput;
    }

    std::cout << "Sum is: " << iSum << std::endl;
}

int main()
{
//    Exercise6();
//    Exercise5();
//    Exercise4();
//    Exercise3();
//    Exercise2NoUB();
//    Exercise2UB();
//    Exercise1();

    return 0;
}
