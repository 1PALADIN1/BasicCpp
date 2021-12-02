
// 1. Создайте проект из 2х cpp файлов и заголовочного(main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: 
// для инициализации массива(типа float), печати его на экран и подсчета количества отрицательных и положительных элементов.
// Вызывайте эти 3 - и функции из main для работы с массивом.
// 5. * Сделайте задание 1 добавив свой неймспейс во втором модуле(первое задание тогда можно не делать).

#include <iostream>
#include "mylib.h"

int main()
{
    std::cout << ">>> Task 1" << std::endl;

    const size_t ARR_SIZE = 30;

    float* arr = new (std::nothrow) float[ARR_SIZE];
    if (arr == nullptr)
    {
        std::cout << "Error! Can not allocate memory!" << std::endl;
        return -1;
    }

    mylib::initArray(arr, ARR_SIZE);
    mylib::printArray(arr, ARR_SIZE);
    mylib::countNumbers(arr, ARR_SIZE);

    delete[] arr;

    return 0;
}
