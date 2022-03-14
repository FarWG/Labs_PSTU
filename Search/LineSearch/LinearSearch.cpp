#include <iostream>

using namespace std;

int lineSearch(int a[], int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == k)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	int k;
	cout << "Введите размер массива: ";
	cin >> n; 
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << "Введите то число, после которого нужно удалить элемент: ";
	cin >> k;
	int ikey;
	ikey = lineSearch(a, n, k);
	if (ikey != -1)
	{
		if (ikey == n - 1)
		{
			cout << "После данного элемента ничего нет" << endl;
		}
		else
		{
			for (int i = ikey + 1; i < n - 1; i++)
			{
				a[i] = a[i + 1];
			}
			n--;
		}
	}
	else
	{
		cout << "Данного элемента нет в массиве" << endl;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	delete a;
	return 0;
}