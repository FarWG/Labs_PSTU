#include <iostream>

using namespace std;

void obmen(int **arr, int stolb, int str1, int str2)
{
	int tmp;
	for (int i = 0; i < stolb; i++)
	{
		tmp = arr[str1][i];
		arr[str1][i] = arr[str2][i];
		arr[str2][i] = tmp;
	}
}

int main()
{
	int n = 5; // Строки
	int m = 5; // Столбцы
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
	cout << "Start:";
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i][2] < a[i - 1][2])
		{
			obmen(a, m, i, i - 1);
			i = 0;
		}
	}
	cout << endl;
	cout << "End:";
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
	}
	for (int i = 0; i < n; i++)
	{
		delete[]a[i];
	}
	delete[]a;
	return 0;
}