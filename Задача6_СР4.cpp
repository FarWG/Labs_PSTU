#include <iostream> // Директива для добавления библиотеки iostream

using namespace std; // Объявления пространства имен std

int main() // Обязательная функия main
{
    setlocale(LC_ALL, "Russian"); // Функция для Русского языка при выводе в консоле
    int a, b, an; 
    cout << "Введите первое число:" << endl;
    cin >> a;
    cout << "Введите второе число:" << endl;
    cin >> b;
    an = a * b; // Присваиваем к переменной an значение произведение a и b
    cout << "Произведение этих двух числе равно:" << endl;
    cout << an;
}