
// Что успел сделать:
// 1. Выделить в памяти динамический одномерный массив типа int.Размер массива запросить у пользователя.
// Инициализировать его числами степенями двойки : 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран.
// Не забыть освободить память. = ) Разбить программу на функции.
// 2. Динамически выделить матрицу 4х4 типа int.Инициализировать ее псевдослучайными числами через функцию rand.Вывести на экран.
// Разбейте вашу программу на функции которые вызываются из main.
// 3. Написать программу, которая создаст два текстовых файла(*.txt), примерно по 50 - 100 символов в каждом(особого значения не имеет с каким именно содержимым).
// Имена файлов запросить у польлзователя.
// 4. * Написать функцию, «склеивающую» эти файлы в третий текстовый файл(имя файлов спросить у пользователя).

#include <iostream>
#include <fstream>
#include <string>

void task1();
void task2();
void task3();
void task4();
void printArray(int* arr, int size);
void printArray(int** arr, int sizeX, int sizeY);
void fillArrayWithRandomNumbers(int** arr, int sizeX, int sizeY);
void createFile(std::string fileName);
void copyFileToFile(std::ifstream* fromStream, std::ofstream* toStream);

int main()
{
    task1();
    task2();
    task3();
    task4();

    return 0;
}

// 1. Выделить в памяти динамический одномерный массив типа int.Размер массива запросить у пользователя.
// Инициализировать его числами степенями двойки : 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран.
// Не забыть освободить память. = ) Разбить программу на функции.
void task1()
{
    std::cout << ">>> Task 1" << std::endl;
    std::cout << "Enter size of your array: ";

    int* arr;
    int n;
    std::cin >> n;


    if (n <= 0)
    {
        std::cout << "Input number [" << n << "] is not valid!" << std::endl;
        return;
    }

    arr = new (std::nothrow) int[n];
    if (arr == nullptr)
    {
        std::cout << "Error! Can not allocate memory!" << std::endl;
        return;
    }

    int prevValue = 1;
    for (int i = 0; i < n; i++)
    {
        arr[i] = prevValue * 2;
        prevValue = arr[i];
    }

    printArray(arr, n);

    delete[] arr;
    arr = nullptr;
}


// 2. Динамически выделить матрицу 4х4 типа int.Инициализировать ее псевдослучайными числами через функцию rand.Вывести на экран.
// Разбейте вашу программу на функции которые вызываются из main.
void task2()
{
    std::cout << ">>> Task 2" << std::endl;

    int** arr;
    const int sizeX = 4;
    const int sizeY = 4;

    arr = new int* [sizeX];
    for (int i = 0; i < sizeX; i++)
    {
        arr[i] = new int[sizeY];
    }

    fillArrayWithRandomNumbers(arr, sizeX, sizeY);
    printArray(arr, sizeX, sizeY);

    for (int i = 0; i < sizeX; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    arr = nullptr;
}

void fillArrayWithRandomNumbers(int** arr, int sizeX, int sizeY)
{
    srand(time(0));
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
}

// 3. Написать программу, которая создаст два текстовых файла(*.txt), примерно по 50 - 100 символов в каждом(особого значения не имеет с каким именно содержимым).
// Имена файлов запросить у польлзователя.
void task3()
{
    std::cout << ">>> Task 3" << std::endl;

    std::string firstFileName;
    std::string secondFileName;

    std::cout << "Enter first file name: ";
    std::cin >> firstFileName;
    std::cout << "Enter second file name: ";
    std::cin >> secondFileName;

    srand(time(0));
    createFile(firstFileName);
    createFile(secondFileName);
}

void createFile(std::string fileName)
{
    std::ofstream fout(fileName);
    
    const int fileSize = rand() % 50 + 50;
    for (int i = 0; i < fileSize; i++)
    {
        char randomChar = rand() % 255;
        fout << randomChar;
    }

    fout.close();

    std::cout << "File " << fileName << " is created!" << std::endl;
}

// 4. * Написать функцию, «склеивающую» эти файлы в третий текстовый файл(имя файлов спросить у пользователя).
void task4()
{
    std::cout << ">>> Task 4" << std::endl;

    std::string firstFileName;
    std::string secondFileName;
    std::string resultFileName;

    std::cout << "Enter first file name: ";
    std::cin >> firstFileName;
    std::cout << "Enter second file name: ";
    std::cin >> secondFileName;
    std::cout << "Enter result file name: ";
    std::cin >> resultFileName;

    std::ifstream fin1(firstFileName);
    if (!fin1.is_open())
    {
        std::cout << "Error. Can not open file: " << firstFileName << std::endl;
        return;
    }

    std::ifstream fin2(secondFileName);
    if (!fin2.is_open())
    {
        std::cout << "Error. Can not open file: " << secondFileName << std::endl;
        fin1.close();
        return;
    }

    std::ofstream fout(resultFileName);

    copyFileToFile(&fin1, &fout);
    copyFileToFile(&fin2, &fout);

    std::cout << "File " << resultFileName << " is created!" << std::endl;

    fin1.close();
    fin2.close();
    fout.close();
}

void copyFileToFile(std::ifstream* fromStream, std::ofstream* toStream)
{
    std::string buf;

    while (!fromStream->eof())
    {
        std::getline((*fromStream), buf);
        (*toStream) << buf << std::endl;;
    }
}

// shared
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void printArray(int** arr, int sizeX, int sizeY)
{
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}