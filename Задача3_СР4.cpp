﻿#include <iostream> // Директива для добавления библиотеки iostream

using namespace std; // Объявления пространства имен std

int main() // Обязательная функия main
{
    setlocale(LC_ALL, "Russian"); // Функция для Русского языка при выводе в консоле
    const int a = 10; // Целая константа
    int b;
    b = a * 2; // Присваивание b
    cout << "Вывод:" << endl;
    cout << a << endl;
    cout << b << endl;
    cout << --b << endl; // Операция декремента
}
