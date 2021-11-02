#include <iostream> // Директива для добавления библиотеки iostream

using namespace std; // Объявления пространства имен std

int main() // Обязательная функия main
{
    setlocale(LC_ALL, "Russian"); // Функция для Русского языка при выводе в консоле
    float c, f;
    cout << "Введите градусы по Фаренгейту:" << endl;
    cin >> f;
    c = (5.0 / 9.0) * (f - 32); // 5.0 и 9.0 для нецелочисленного деления
    cout << "Градусы Цельсия" << endl;
    cout << c << endl;
}
