#include <iostream>

using namespace std;

class ruble
{
private:
	int nominal;
	int count;
public:
	void set(int nominal, int count)
	{
		this->nominal = nominal;
		this->count = count;
	}
	int summa()
	{
		int sum = 0;
			sum = nominal * count;
			return sum;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	ruble a;
	int nom, cou;
	cout << "Введите номинал и кол-во купюр этого достоинства:" << endl;
	cin >> nom;
	while (nom != 1 && nom != 2 && nom != 5 && nom != 10 && nom != 50 && nom != 100 && nom != 500 && nom != 1000 && nom != 2000 && nom != 5000)
	{
		cout << "Вы ввели несуществующий номинал купюры." << endl;
		cin >> nom;
	}
	cin >> cou;
	a.set(nom, cou);
	cout << "Денежная сумма: " << a.summa();
	return 0;
}