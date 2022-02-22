#include <iostream>

using namespace std;

int main()
{
	int n;
	int d;
	int tmp;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
	cout << "Start array: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
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
	cout << "Final array:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	delete[]a;
	return 0;
}