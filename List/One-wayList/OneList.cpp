#include <iostream>

using namespace std;

struct Node
{
	double data;
	Node* ptr_next = nullptr;
};

struct List
{
	Node* headnode = nullptr;
	Node* tailnode = nullptr;
};

void pushBack(List& list, int& data)
{
	Node* newnode = new Node;
	newnode->data = data;
	if (list.headnode == nullptr)
	{
		list.headnode = newnode;
		list.tailnode = newnode;
	}
	else
	{
		list.tailnode->ptr_next = newnode;
		list.tailnode = newnode;
	}
}

void printList(List& list)
{
	Node* currentnode = list.headnode;
	while (currentnode != nullptr)
	{
		cout << currentnode->data << " ";
		currentnode = currentnode->ptr_next;
	}
}

void changeList(List& list)
{
	Node* currentnode = list.headnode;
	Node* prednode = list.headnode;
	int count = 1;
	while (currentnode != nullptr)
	{
		if (count % 2 == 0)
		{
			prednode->ptr_next = currentnode->ptr_next;
			prednode = currentnode->ptr_next;
		}
		currentnode = currentnode->ptr_next;
		count++;
	}
	
}

int main()
{
	setlocale(LC_ALL, "Russian");
	List list;
	int n;
	cout << "Введите размер списка: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		pushBack(list, i);
	}
	cout << "Изначальный список" << endl;
	printList(list);
	changeList(list);
	cout << endl;
	cout << "Финальный список" << endl;
	printList(list);
	return 0;
}