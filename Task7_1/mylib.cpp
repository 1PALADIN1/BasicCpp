
// 1. Создайте проект из 2х cpp файлов и заголовочного(main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: 
// для инициализации массива(типа float), печати его на экран и подсчета количества отрицательных и положительных элементов.
// Вызывайте эти 3 - и функции из main для работы с массивом.
// 5. * Сделайте задание 1 добавив свой неймспейс во втором модуле(первое задание тогда можно не делать).

#include <iostream>

namespace mylib
{
	void initArray(float* arr, size_t size)
	{
		srand(time(0));
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 100 - 50;
		}
	}

	void printArray(float* arr, size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}

		std::cout << std::endl;
	}

	void countNumbers(float* arr, size_t size)
	{
		size_t positive = 0;
		size_t negative = 0;

		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] > 0)
			{
				positive++;
				continue;
			}

			if (arr[i] < 0)
				negative++;
		}

		std::cout << "Positive numbers: " << positive << ", negative: " << negative << std::endl;
	}
}