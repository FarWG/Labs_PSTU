#include <iostream> // Директива для добавления библиотеки iostream

using namespace std; // Объявления пространства имен std

int main() // Обязательная функия main
{
	int i, a; // Объявляем i и a, тип данных int
	i = 1; // Присваиваем i, 1
	a = ++i * i++; // ++i = 2; i++ = 2; a = 2 * 2; a = 4
	cout << a; // Выводим a
}