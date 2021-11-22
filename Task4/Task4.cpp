
//Задания которые успел сделать:

// 1. Написать программу, проверяющую что сумма двух(введенных с клавиатуры) чисел лежит в пределах от 10 до 20 (включительно), если да – вывести строку "true",
// в противном случае – "false";
// 2. Написать программу, выводящую на экран строку “true”, если две целочисленные константы, объявленные в её начале либо обе равны десяти сами по себе,
// либо их сумма равна десяти. Иначе "false".
// 3. Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50. Например: "Your numbers: 1 3 5 7 9 11 13 …".Для решения используйте любой С++ цикл.
// 4. Со звёздочкой. Написать программу, проверяющую, является ли некоторое число - простым. Простое число — это целое положительное число, которое делится без
// остатка только на единицу и себя само.

#include <iostream>

int main()
{
    // 1. Написать программу, проверяющую что сумма двух(введенных с клавиатуры) чисел лежит в пределах от 10 до 20 (включительно), если да – вывести строку "true",
    // в противном случае – "false";
    int firstNumber;
    int secondNumber;

    std::cout << ">> Task 1" << std::endl;
    std::cout << "Enter first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter second number: ";
    std::cin >> secondNumber;
    int sum = firstNumber + secondNumber;

    if (sum >= 10 && sum <= 20)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    
    // 2. Написать программу, выводящую на экран строку “true”, если две целочисленные константы, объявленные в её начале либо обе равны десяти сами по себе,
    // либо их сумма равна десяти. Иначе "false".
    std::cout << ">> Task 2" << std::endl;
    //-> test1, expect true
    const int firstNumber_task2 = 10;
    const int secontNumber_task2 = 2;
    //-> test2, expect true
    //const int firstNumber_task2 = -2;
    //const int secontNumber_task2 = 10;
    //-> test3, expect true
    //const int firstNumber_task2 = -2;
    //const int secontNumber_task2 = 10;
    //-> test4, expect false
    //const int firstNumber_task2 = -2;
    //const int secontNumber_task2 = 6;

    if (firstNumber_task2 == 10 || secontNumber_task2 == 10 || (firstNumber_task2 + secontNumber_task2 == 10))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    // 3. Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50. Например: "Your numbers: 1 3 5 7 9 11 13 …".Для решения используйте любой С++ цикл.
    std::cout << ">> Task 3" << std::endl;
    for (int i = 1; i <= 50; i++)
    {
        if (i % 2 != 0)
        {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    // 4. Со звёздочкой. Написать программу, проверяющую, является ли некоторое число - простым. Простое число — это целое положительное число, которое делится без
    // остатка только на единицу и себя само.
    std::cout << ">> Task 4" << std::endl;
    const int checkNumber = 191;
    int count = 0;
    for (int i = 1; i <= checkNumber; i++)
    {
        if (checkNumber % i == 0)
        {
            count++;
        }

        if (count > 2)
        {
            break;
        }
    }

    if (count <= 2)
    {
        std::cout << "Number " << checkNumber << " is simple" << std::endl;
    }
    else
    {
        std::cout << "Number " << checkNumber << " is NOT simple" << std::endl;
    }

    return 0;
}
