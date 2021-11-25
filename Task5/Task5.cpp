// Что успел сделать:
// 1. Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер.Вызвать эту функцию из main.
// 2. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [1, 1, 0, 0, 1, 0, 1, 1, 0, 0].
// Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.
// 3. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.
// Для продвинутых :
// 4. *Написать функцию, которой на вход подаётся одномерный массив и число n(может быть положительным, или отрицательным), при этом метод должен циклически сместить
// все элементы массива на n позиций.

#include <iostream>
#include <cmath>

void printArray(double[], int);
void printArray(int arr[], int size);
void inverseNumbers(int arr[], int size);
void fillArray(int arr[], int size);
void moveArrayNumbers(int arr[], int num);

int main()
{
    //Task 1
    std::cout << ">> Task 1" << std::endl;
    double arr[] = { 2.0, 2.1, -90.203, 1233.65 };
    const int arraySize = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, arraySize);

    //Task 2
    std::cout << ">> Task 2" << std::endl;
    int arr2[] = {1, 1, 0, 0, 1, 0, 1, 1, 0, 0};
    const int arraySize2 = sizeof(arr2) / sizeof(arr2[0]);
    printArray(arr2, arraySize2);
    inverseNumbers(arr2, arraySize2);
    printArray(arr2, arraySize2);

    //Task 3
    std::cout << ">> Task 3" << std::endl;
    const int arraySize3 = 8;
    int arr3[arraySize3];
    fillArray(arr3, arraySize3);
    printArray(arr3, arraySize3);

    //Task 4
    std::cout << ">> Task 4" << std::endl;
    int arr4[] = { 31, 2, -9, 45, 5 };
    const int arraySize4 = sizeof(arr4) / sizeof(arr4[0]);
    printArray(arr4, arraySize4);
    moveArrayNumbers(arr4, 3);
    printArray(arr4, arraySize4);
    moveArrayNumbers(arr4, -2);
    printArray(arr4, arraySize4);
    moveArrayNumbers(arr4, 1);
    printArray(arr4, arraySize4);

    return 0;
}

// 1. Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер.Вызвать эту функцию из main.
void printArray(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    std::cout << std::endl;
}

// 2. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [1, 1, 0, 0, 1, 0, 1, 1, 0, 0].
// Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.
void inverseNumbers(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i] == 0 ? 1 : 0;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

// 3. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.
void fillArray(int arr[], int size)
{
    int number = 1;
    for (int i = 0; i < size; i++)
    {
        arr[i] = number;
        number += 3;
    }
}

// 4. *Написать функцию, которой на вход подаётся одномерный массив и число n(может быть положительным, или отрицательным), при этом метод должен циклически сместить
// все элементы массива на n позиций.
void moveArrayNumbers(int arr[], int num)
{
    if (num == 0)
        return;
    const int size = 5;
    int originalArray[size];
    for (int i = 0; i < size; i++)
    {
        originalArray[i] = arr[i];
    }

    std::cout << "Move: " << num << std::endl;
    for (int i = 0; i < size; i++)
    {
        int newIndex = i + num;

        if (newIndex >= size)
        {
            newIndex = abs(size - newIndex);
        }

        if (newIndex < 0)
        {
            newIndex = size + newIndex;
        }

        arr[newIndex] = originalArray[i];
    }
}