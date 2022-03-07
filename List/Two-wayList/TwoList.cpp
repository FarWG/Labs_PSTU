#include <iostream>

using namespace std;

struct Node
{
	char data;
	Node* ptr_prev = nullptr;
	Node* ptr_next = nullptr;
};

struct List
{
	Node* headnode = nullptr;
	Node* tailnode = nullptr;
};

void StartList(List& list, char& data)
{
	Node* newnode = new Node;
	newnode->data = data;
	if (list.headnode == nullptr)
	{
		list.headnode = newnode;
		list.tailnode = newnode;
		return;
	}
	Node* currentnode = list.headnode;
	newnode->ptr_prev = currentnode;
	if (currentnode->ptr_next != nullptr)
	{
		newnode->ptr_next = currentnode->ptr_next;
		currentnode->ptr_next->ptr_prev = newnode;
	}
	currentnode->ptr_next = newnode;
	list.tailnode = newnode;
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

void addList(List& list)
{
	Node* newnode = new Node;
	char data;
	int count = 1;
	Node* currentnode = list.headnode;
	while (currentnode != nullptr)
	{
		if (count % 2 != 0)
		{
			cin >> data;
			newnode->data = data;
			currentnode->data = newnode->data;
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
	char tmp;
	cout << "Введите размер списка: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		StartList(list, tmp);
	}
	cout << "Изначальный список" << endl;
	printList(list);
	cout << endl;
	addList(list);
	cout << "Финальный список" << endl;
	printList(list);
	return 0;
}