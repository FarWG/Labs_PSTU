#include <iostream>

using namespace std;

void Sort(int* a, int n)
{
	int d;
	int tmp;
	d = n / 2;
	while (d > 0)
	{
		for (int i = 0; i < n - d; i++)
		{
			int j = i;
			while (j >= 0 && a[j] > a[j + d])
			{
				tmp = a[j];
				a[j] = a[j + d];
				a[j + d] = tmp;
				j--;
			}
		}
		d = d / 2;
	}
}

int InterSearch(int* a, int n, int k)
{
	int left = 0;
	int right = n;
	int mid = 0;
	bool f = false;
	while ((left <= right) && !f)
	{
		mid = left + ((k - a[left]) * (right - left)) / (a[right] - a[left]);
		if (a[mid] < k)
		{
			left = mid + 1;
		}
		else if (a[mid] > k)
		{
			right = mid + 1;
		}
		else
		{
			f = true;
		}
	}
	if (a[left] == k)
	{
		return left;
	}
	else if (a[right] == k)
	{
		return right;
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	int* a = new int[n];
	int k;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
	Sort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Введите число, перед которым нужно удалить элемент: ";
	cin >> k;
	int ikey;
	ikey = InterSearch(a, n, k);
	if (ikey != -1)
	{
		if (ikey == 0)
		{
			cout << "Перед данным элементом ничего нет" << endl;
		}
		else
		{
			for (int i = ikey - 1; i < n - 1; i++)
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