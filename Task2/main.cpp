
#include <iostream>

/*
В одном main.cpp файле / проекте:
1. Создать и инициализировать переменные пройденных типов данных(short int, int, long long, char, bool, float, double).
2. Создать перечисление(enum) с возможными вариантами символов для игры в крестики - нолики.
3. Создать массив, способный содержать значения такого перечисления и инициализировать его.
4. * Создать структуру(struct) данных «Поле для игры в крестики - нолики» и снабдить его всеми необходимыми свойствами(подумайте что может понадобиться).
5. * *Создать структуру(struct MyVariant) объединяющую : union MyData(int, float, char) и 3 - и битовых поля(флага)
указывающими какого типа значение в данный момент содержится в объединении(isInt, isFloat, isChar).Продемонстрировать пример использования в коде этой структуры.
*/

//2. Создать перечисление(enum) с возможными вариантами символов для игры в крестики - нолики.
enum GameSymbols
{
	EMPTY,
	CROSS,
	ZERO
};

//4. * Создать структуру(struct) данных «Поле для игры в крестики - нолики» и снабдить его всеми необходимыми свойствами(подумайте что может понадобиться).
//Результат окончания игры
enum GameFinishResult
{
	TIE,
	WIN_PlAYER1,
	WIN_PLAYER2
};

struct GameField
{
	GameSymbols firstPlayerSymbol;
	GameSymbols secondPlayerSymbol;
	GameSymbols gameField[3][3];
	bool isFinished;
	bool isFirstPlayerTurn;
	GameFinishResult gameResult;
};

int main()
{
	//1. Создать и инициализировать переменные пройденных типов данных(short int, int, long long, char, bool, float, double).
	short int short_var = 2;
	int int_var = 23'567'887;
	long long long_var = 212'323'545'624'564'356;
	char char_var = 72;
	std::cout << char_var << std::endl;
	bool bool_var = true;
	float float_var = 23.0f;
	double double_var = 23.0;

	//3. Создать массив, способный содержать значения такого перечисления и инициализировать его.
	const int arraySize = 9;
	GameSymbols gameState[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		gameState[i] = EMPTY;
		std::cout << gameState[i] << " ";

		if ((i + 1) % 3 == 0)
			std::cout << std::endl;
	}
	
	return 0;
}