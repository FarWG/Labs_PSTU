#include <iostream>

using namespace std;

int main()
{
	int n = 10;
	int a[100] = {};
	int b[100] = {};
	int inul = 0;
	bool f = false;
	int cont = 0;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
		if ((a[i] == 0) && (f == false))
		{
			inul = i;
			f = true;
		}
	}
	cout << endl;
	for (int i = inul; i < n; i++) // Удаление элемента со значением 0
	{
		a[i] = a[i + 1];
	}
	for (int i = 0; i < n - 1; i++) // Четные элементы
	{
		if (a[i] % 2 == 0)
		{
			b[cont] = a[i];
			cont++;
			b[cont] = a[i - 1] + 2;
		}
		else
		{
			b[cont] = a[i];
		}
		cont++;
	}
	for (int i = 0; i < cont; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}