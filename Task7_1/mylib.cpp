
// 1. �������� ������ �� 2� cpp ������ � �������������(main.cpp, mylib.cpp, mylib.h) �� ������ ������ mylib �������� 3 �������: 
// ��� ������������� �������(���� float), ������ ��� �� ����� � �������� ���������� ������������� � ������������� ���������.
// ��������� ��� 3 - � ������� �� main ��� ������ � ��������.
// 5. * �������� ������� 1 ������� ���� ��������� �� ������ ������(������ ������� ����� ����� �� ������).

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