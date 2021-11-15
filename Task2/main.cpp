
#include <iostream>

/*
� ����� main.cpp ����� / �������:
1. ������� � ���������������� ���������� ���������� ����� ������(short int, int, long long, char, bool, float, double).
2. ������� ������������(enum) � ���������� ���������� �������� ��� ���� � �������� - ������.
3. ������� ������, ��������� ��������� �������� ������ ������������ � ���������������� ���.
4. * ������� ���������(struct) ������ ����� ��� ���� � �������� - ������ � �������� ��� ����� ������������ ����������(��������� ��� ����� ������������).
5. * *������� ���������(struct MyVariant) ������������ : union MyData(int, float, char) � 3 - � ������� ����(�����)
������������ ������ ���� �������� � ������ ������ ���������� � �����������(isInt, isFloat, isChar).������������������ ������ ������������� � ���� ���� ���������.
*/

//2. ������� ������������(enum) � ���������� ���������� �������� ��� ���� � �������� - ������.
enum GameSymbols
{
	EMPTY,
	CROSS,
	ZERO
};

int main()
{
	//1. ������� � ���������������� ���������� ���������� ����� ������(short int, int, long long, char, bool, float, double).
	short int short_var = 2;
	int int_var = 23'567'887;
	long long long_var = 212'323'545'624'564'356;
	char char_var = 72;
	std::cout << char_var << std::endl;
	bool bool_var = true;
	float float_var = 23.0f;
	double double_var = 23.0;

	//3. ������� ������, ��������� ��������� �������� ������ ������������ � ���������������� ���.
	const int array_size = 9;
	GameSymbols game_state[array_size];
	for (int i = 0; i < array_size; i++)
	{
		game_state[i] = EMPTY;
		std::cout << game_state[i] << " ";

		if ((i + 1) % 3 == 0)
			std::cout << std::endl;
	}
	
	return 0;
}