
// Что успел сделать:
// 1. Создайте проект из 2х cpp файлов и заголовочного(main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: 
// для инициализации массива(типа float), печати его на экран и подсчета количества отрицательных и положительных элементов.
// Вызывайте эти 3 - и функции из main для работы с массивом.
// 2. Описать макрокоманду(через директиву define), проверяющую, входит ли переданное ей число(введенное с клавиатуры)
// в диапазон от нуля(включительно) до переданного ей второго аргумента(исключительно) и возвращает true или false, вывести на экран «true» или «false».
// 3. Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define.Инициализируйте его через ввод с клавиатуры.
// Напишите для него свою функцию сортировки(например Пузырьком).Реализуйте перестановку элементов как макрокоманду SwapINT(a, b).
// Вызывайте ее из цикла сортировки.
// 4. * Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack.
// Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл.
// 5. * Сделайте задание 1 добавив свой неймспейс во втором модуле(первое задание тогда можно не делать).


#include <iostream>
#include <string> 
#include <fstream>

#define CHECK_NUMBER(num, maxValue) (num >= 0 && num < maxValue)
#define ARR_SIZE 10
#define SwapINT(a, b) b = a + b; \
a = b - a; \
b = b - a;

void task2();
void task3();
void task4();
void printArray(int* arr, size_t size);

int main()
{
    task2();
    task3();
    task4();

    return 0;
}

// 2. Описать макрокоманду(через директиву define), проверяющую, входит ли переданное ей число(введенное с клавиатуры)
// в диапазон от нуля(включительно) до переданного ей второго аргумента(исключительно) и возвращает true или false, вывести на экран «true» или «false».
void task2()
{
    std::cout << ">>> Task 2" << std::endl;
    
    const int MAX_VALUE = 500;
    int n;
    std::cout << "Enter number: ";
    std::cin >> n;

    if (CHECK_NUMBER(n, MAX_VALUE) == 0)
    {
        std::cout << "false" << std::endl;
        return;
    }

    std::cout << "true" << std::endl;
}

// 3. Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. Инициализируйте его через ввод с клавиатуры.
// Напишите для него свою функцию сортировки(например Пузырьком). Реализуйте перестановку элементов как макрокоманду SwapINT(a, b).
// Вызывайте ее из цикла сортировки.
void task3()
{
    std::cout << ">>> Task 3" << std::endl;

    int* arr = new (std::nothrow) int[ARR_SIZE];
    if (arr == nullptr)
    {
        std::cout << "Error! Can not allocate memory!" << std::endl;
        return;
    }

    int inputVal;
    for (size_t i = 0; i < ARR_SIZE; i++)
    {
        std::cout << "Enter number: ";
        std::cin >> inputVal;
        arr[i] = inputVal;
    }

    std::cout << "Array before sorting:" << std::endl;
    printArray(arr, ARR_SIZE);

    for (size_t iter = 1; iter < ARR_SIZE; iter++)
    {
        for (size_t i = 0; i < ARR_SIZE - iter; i++)
        {
            int val1 = arr[i];
            int val2 = arr[i + 1];
            if (val1 > val2)
            {
                SwapINT(val1, val2);
            }

            arr[i] = val1;
            arr[i + 1] = val2;
        }
    }

    std::cout << "Array after sorting:" << std::endl;
    printArray(arr, ARR_SIZE);

    delete[] arr;
}

void printArray(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

// 4. * Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack.
// Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл.
#pragma pack(push, 1)
struct Employee
{
    std::string firstName;
    std::string secondName;
    int age;
    float salary;
    char sex;

    std::string toString()
    {
        return "First name: " + firstName + ", second name: " + secondName 
            + ", age: " + std::to_string(age) + ", salary: " + std::to_string(salary)
            + ", sex: " + sex;
    }
};
#pragma pack(pop)

void task4()
{
    std::cout << ">>> Task 4" << std::endl;

    Employee* emp = new Employee();
    emp->firstName = "Johnny";
    emp->secondName = "Bravo";
    emp->age = 27;
    emp->salary = 300'000.0f;
    emp->sex = 'M';

    std::cout << "Struct size: " << sizeof(emp) << ". Data: " << emp->toString() << std::endl;

    std::ofstream fout("emp.txt");
    fout << emp->toString();
    fout.close();
}