#include <iostream> // Директива для добавления библиотеки iostream

using namespace std; // Объявления пространства имен std

int main() // Обязательная функия main
{
	setlocale(LC_ALL, "Russian"); // Функция для Русского языка при выводе в консоле
	int ga;
	float fu; // Тип данных float, т.к. будут использовны нецелые числа
	cout << "Введите кол-во галлонов:" << endl;
	cin >> ga;
	fu = ga / 7.481;
	cout << "Кубических футов в этих галлонов:" << endl;
	cout << fu;
}