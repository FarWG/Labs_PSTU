#include <iostream>
#include <stdarg.h>

using namespace std;

float mult(int i, ...)
{
	va_list p;
	va_start(p, i);
	float mul = 1;
	for (int j = 0; j < i; j++)
	{
		mul *= va_arg(p, double);
	}
	va_end(p);
	return mul;
}

int main()
{
	cout << mult(3, 5.5, 9.34, 1.5) << endl;
	cout << mult(7, 23.5, -459.6, 1.3, 45.5, -85.3, 12.3, 6.4) << endl;
	cout << mult(11, 1.1, 875.2, 12354.3, -9564.5, 767.4, 845.3, 87.4, 9.4, 2.3, 1.97, 4873.3) << endl;
	return 0;
}