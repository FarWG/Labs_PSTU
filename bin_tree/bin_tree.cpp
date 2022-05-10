#include <iostream>

using namespace std;

int mx = 0;
int count;

class Tree
{
private:
	int data;
	Tree* left;
	Tree* right;
	Tree* parent;
public:
	Tree(int d)
	{
		data = d;
		left = right = parent = nullptr;
	}
	Tree()
	{
		data = -1;
		left = right = parent = nullptr;
	}
	int get_data()
	{
		return data;
	}
	Tree* get_left()
	{
		return left;
	}
	Tree* get_right()
	{
		return right;
	}
	Tree* get_parent()
	{
		return parent;
	}
	void add_left(Tree* tmp)
	{
		left = tmp;
	}
	void add_right(Tree* tmp)
	{
		right = tmp;
	}
	Tree* fill(int count)
	{
		if (count <= 0)
		{
			return nullptr;
		}
		int d;
		cout << "Введите число: ";
		cin >> d;
		Tree* tmp = new Tree(d);
		tmp->add_left(fill(count / 2));
		tmp->add_right(fill(count - count / 2 - 1));
		return tmp;
	}
	void insert_right(int d)
	{
		Tree* temp = new Tree(d);
		if (right != nullptr)
		{
			right->parent = temp;
			temp->right = right;
		}
		right = temp;
		temp->parent = this;
	}
	void insert_left(int d)
	{
		Tree* temp = new Tree(d);
		if (left != nullptr)
		{
			left->parent = temp;
			temp->left = left;
		}
		left = temp;
		temp->parent = this;
	}
	void insert(int d)
	{
		Tree* cur = this;
		while (cur != nullptr)
		{
			if (d > cur->data)
			{
				if (cur->right != nullptr)
				{
					cur = cur->right;
				}
				else
				{
					cur->insert_right(d);
					return;
				}
			}
			else if (d < cur->data)
			{
				if (cur->left != nullptr)
				{
					cur = cur->left;
				}
				else
				{
					cur->insert_left(d);
					return;
				}
			}
			else return;
		}
	}
	void way(Tree* cur)
	{
		if (cur == nullptr)
		{
			return;
		}
		else
		{
			//cout << cur->get_data() << endl;
			if (cur->get_data() > mx)
			{
				mx = cur->get_data();
			}
			way(cur->get_left());
			way(cur->get_right());
		}
	}
	void searchTree(int count)
	{
		Tree* search_tree = new Tree();
		for (int i = 0; i < count; i++)
		{
			search_tree->insert(count);
		}
	}
	void print(Tree* root, int space = 0) {
		if (!root)
			return;
		enum { COUNT = 2 };
		space += COUNT;
		print(root->right, space);
		for (int i = COUNT; i < space; ++i)
			std::cout << "  ";
		std::cout << root->data << std::endl;
		print(root->left, space);
	}
};



int main()
{
	setlocale(LC_ALL, "Russian");
	Tree* t = new Tree();
	int count;
	cin >> count;
	Tree* balT = t->fill(count);
	balT->way(balT);
	cout << "Максимальный элемент: " << mx << endl;
	balT->print(balT);
	cout << "Дерево поиска: " << endl;
	Tree* SearchT = balT->searchTree(count);
	SearchT->print(SearcT);
	return 0;
}