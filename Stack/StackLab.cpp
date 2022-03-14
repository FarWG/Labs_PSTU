#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
};

template <typename T>
struct Stack
{
	Node<T>* head = nullptr;
	int size = 0;
};

template <typename T>
void setNode(Node<T>& node, T data, Node<T>* next = null)
{
	node = new Node<T>;
	node->next = next;
	node->data = data;
}

template <typename T>
void Push(Stack<T>& tmp, const T& data)
{
	Node<T>* newnode = new Node<T>;
	newnode->next = tmp.head;
	newnode->data = data;
	tmp.head = newnode;
	tmp.size++;
}

template <typename T>
void pop(Stack<T>& tmp)
{
	if (tmp.head != nullptr)
	{
		Node<T>* deleted = tmp.head;
		tmp.head = tmp.head->next;
		delete deleted;
		tmp.size--;
	}
}

template <typename T>
void printStack(Stack<T>& tmp)
{
	Node<T>* currentnode = tmp.head;
	while (currentnode != nullptr)
	{
		cout << currentnode->data << " ";
		currentnode = currentnode->next;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	int count = 1;
	cout << "Введите размер стака: ";
	cin >> n;
	double k;
	Stack <double> st;
	Stack <double> st2;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		Push(st, k);
	}
	cout << endl;
	printStack(st);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (count % 2 == 0)
		{
			Push(st2, st.head->data);
		}
		pop(st);
		count++;
	}
	printStack(st2);
	return 0;
}