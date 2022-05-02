#include <iostream>
#include <string>

using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmMake = 6;
const int cmFind = 7;
const int cmQuit = 101;

struct TEvent
{
	int what;
	union
	{
		int command;
		struct
		{
			int message;
			int a;
		};
	};
};

class Object
{
public:
	Object() {}
	virtual void Show() = 0;
	virtual void input() = 0;
	virtual ~Object() {}
	virtual void HandleEvent(const TEvent& e) = 0;
};

class Person : public Object
{
protected:
	string name;
	int age;
public:
	Person()
	{
		name = "nothing";
		age = 0;
	}
	virtual ~Person() {}
	void Show() override
	{
		cout << "\nИмя: " << name;
		cout << "\nВозраст: " << age << endl;
	}
	void input() override
	{
		cout << "\nИмя: ";
		cin >> name;
		cout << "\nВозраст: ";
		cin >> age;
		cout << endl;
	}
	Person(string n, int a)
	{
		name = n;
		age = a;
	}
	Person(const Person& tmp)
	{
		name = tmp.name;
		age = tmp.age;
	}
	string GetName() { return name; }
	int GetAge() { return age; }
	void SetName(string n)
	{
		name = n;
	}
	void SetAge(int a)
	{
		age = a;
	}
	Person& operator=(const Person& tmp)
	{
		if (&tmp == this)
		{
			return *this;
		}
		name = tmp.name;
		age = tmp.age;
		return *this;
	}
	void HandleEvent(const TEvent& e)
	{
		if (e.what == evMessage)
		{
			switch (e.command)
			{
				case cmGet: cout << "Имя: " << GetName() << endl;
				break;
			}
		}
	}
};

class Employee : public Person
{
protected:
	float zp;
	string job;
public:
	Employee() : Person()
	{
		zp = 0;
		job = "nothing";
	}
	~Employee() {}
	void Show() override
	{
		cout << "\nИмя: " << name;
		cout << "\nВозраст: " << age;
		cout << "\nЗ/п: " << zp;
		cout << "\nДолжность: " << job << endl;
	}
	void input() override
	{
		cout << "\nИмя: ";
		cin >> name;
		cout << "\nВозраст: ";
		cin >> age;
		cout << "\nЗ/п: ";
		cin >> zp;
		cout << "\nДолжность: ";
		cin >> job;
		cout << endl;
	}
	Employee(string n, int a, float z, string j) : Person(n, a)
	{
		zp = z;
		job = j;
	}
	Employee(const Employee& tmp)
	{
		name = tmp.name;
		age = tmp.age;
		zp = tmp.zp;
		job = tmp.job;
	}
	float GetZp() { return zp; }
	string GetJob() { return job; }
	void SetZp(float z)
	{
		zp = z;
	}
	void SetJob(string j)
	{
		job = j;
	}
	Employee& operator=(const Employee& tmp)
	{
		if (&tmp == this) return *this;
		name = tmp.name;
		age = tmp.age;
		zp = tmp.zp;
		job = tmp.job;
	}
};

class Vector
{
protected:
	Object** beg;
	int size;
	int cur;
public:
	Vector()
	{
		beg = nullptr;
		size = 0;
		cur = 0;
	}
	Vector(int n)
	{
		beg = new Object* [n];
		cur = 0;
		size = n;
	}
	~Vector()
	{
		if (beg != 0) delete[] beg;
		beg = 0;
	}
	void Add()
	{
		Object* p;
		cout << "1. Person" << endl;
		cout << "2. Employee" << endl;
		int y;
		cin >> y;
		if (y == 1)
		{
			Person* tmp = new Person;
			tmp->input();
			p = tmp;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else
		{
			if (y == 2)
			{
				Employee* tmp1 = new Employee;
				tmp1->input();
				p = tmp1;
				if (cur < size)
				{
					beg[cur] = p;
					cur++;
				}
			}
			else return;
		}
	}
	void Show()
	{
		if (cur == 0) cout << "Пусто" << endl;
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->Show();
			p++;
		}
	}
	int operator()()
	{
		return cur;
	}
	void Del()
	{
		if (cur == 0) return;
		cur--;
	}
	void Find(int tmp)
	{
		beg[tmp];
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			if (i == tmp - 1)
			{
				(*p)->Show();
			}
			p++;
		}
	}
	void HandleEvent(const TEvent& e)
	{
		if (e.what == evMessage)
		{
			Object** p = beg;
			for (int i = 0; i < cur; i++)
			{
				(*p)->HandleEvent(e);
				p++;
			}
		}
	}
};

class Dialog : public Vector
{
protected:
	int EndState;
public:
	Dialog() : Vector()
	{
		EndState = 0;
	}
	~Dialog() {}
	void GetEvent(TEvent& event)
	{
		string Icode = "+-szqm";
		string s;
		string param;
		char code;
		cout << '>';
		cin >> s;
		code = s[0];
		if (Icode.find(code) >= 0)
		{
			event.what = evMessage;
			switch (code)
			{
			case 'm': event.command = cmMake; break;
			case '+': event.command = cmAdd; break;
			case '-': event.command = cmDel; break;
			case 's': event.command = cmShow; break;
			case 'q': event.command = cmQuit; break;
			case 'z': event.command = cmFind; break;
			}
			if (s.length() > 1)
			{
				param = s.substr(1, s.length() - 1);
				int A = atoi(param.c_str());
				event.a = A;
			}
		}
		else event.what = evNothing;
	}
	int Execute()
	{
		TEvent event;
		do {
			EndState = 0;
			GetEvent(event);
			HandleEvent(event);
		} while (!Valid());
		return EndState;
	}
	int Valid()
	{
		if (EndState == 0) return 0;
		else return 1;
	}
	void ClearEvent(TEvent& event)
	{
		event.what = evNothing;
	}
	void EndExec()
	{
		EndState = 1;
	}
	void HandleEvent(TEvent& event)
	{
		if (event.what == evMessage)
		{
			switch (event.command)
			{
			case cmMake:
				size = event.a;
				beg = new Object*[size];
				cur = 0;
				ClearEvent(event);
				break;
			case cmAdd:
				Add();
				ClearEvent(event);
				break;
			case cmDel:
				Del();
				ClearEvent(event);
				break;
			case cmShow:
				Show();
				ClearEvent(event);
				break;
			case cmQuit:
				EndExec();
				ClearEvent(event);
				break;
			case cmFind:
				int tmp = event.a;
				//cout << "Введите номер элемента: "; cin >> tmp;
				Find(tmp);
				ClearEvent(event);
				break;
			//default: HandleEvent(event);
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "+ - добавить элемент" << "\n- - удалить элемент" << "\nm - создать группу (m6 - из 6 элементов)" << "\ns - просмотр группы" << "\nz - Вывести определенный элемент (Например z2 - о 2-ом элементе)" << "\nq - конец" << "" << endl;
	Dialog D;
	D.Execute();
	return 0;
}