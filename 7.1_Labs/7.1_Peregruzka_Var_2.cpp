#include <iostream>
#include <complex>

using namespace std;

float summa(float a, float b)
{
	return a + b;
}

complex<double>summa(complex<double>a, complex<double>b)
{
	return a + b;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Сумма комплескных чисел равна: " << summa(complex<double>(4, 6), complex<double>(3, 5)) << endl;
	cout << "Сумма вещественных чисел равна: " << summa(983.4, 746);
	return 0;
}