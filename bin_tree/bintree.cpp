#include <glut.h>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int mx = 0;
int count;
int depth = 0, width = 0;
float radA = 0.35;

class Tree
{
private:
	int data;
	Tree* left;
	Tree* right;
	Tree* parent;
public:
	GLfloat x = 0, y = 4;
	int state, level = 1;
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
	friend void LevelCount(Tree* root);
	friend void CountLevels(Tree* root, void (*LevelCount)(Tree* root));
	friend void Coord(Tree* node);
	friend void CoordCalc(Tree* node, void (*Coord)(Tree* node));
	friend void DrawOneNode(Tree* root);
	friend void DrawNode(Tree* root, void (*DrawOneNode)(Tree* node));
	friend void DrawOneline(Tree* root);
	friend void DrawLine(Tree* root, void (*DrawOneLine)(Tree* root));
	void drawTree(int argc, char** argv, int winH, int winW);
};

Tree* tree = new Tree(5);

void LevelCount(Tree* root)
{
	if (root->parent != NULL)
		root->level = root->parent->level + 1;
	if (depth < root->level)
		depth = root->level;
}

void CountLevels(Tree* root, void (*LevelCount)(Tree* root))
{
	if (root == NULL)
		return;
	(*LevelCount)(root);
	CountLevels(root->right, LevelCount);
	CountLevels(root->right, LevelCount);
}

void Coord(Tree* node)
{
	if (node->parent != NULL) {
		if (node->level == 2)
			node->x = node->parent->x + node->state * (pow(2, depth - 1) / 2);
		else
			node->x = node->parent->x + node->state * (pow(2, depth - 1) / pow(2, node->level - 1));
		node->y = node->parent->y - 1;
	}
}

void CoordCalc(Tree* node, void (*Coord)(Tree* node))
{
	if (node == NULL)
		return;
	(*Coord)(node);
	if (node->left != NULL) {
		node->left->state = -1;
		CoordCalc(node->left, Coord);
	}
	if (node->right != NULL)
	{
		node->right->state = 1;
		CoordCalc(node->right, Coord);
	}
	return;
}

void DrawCircle(GLfloat x, GLfloat y, float radB, int count)
{
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (int i = 0; i <= count; i++)
	{
		glVertex2f((x + (radA * cos(i * count))), (y + (radA * sin(i * count))));
	}
	glEnd();
}

void DrawOutline(float tmpX, float tmpY, float radB)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for (int i = 0; i <= radA; i++)
	{
		for (int j = 0; j <= 540; j++)
		{
			tmpX = radA * sin(j) + tmpX;
			tmpY = radB * cos(j) + tmpY;
			glVertex2f(tmpX - 0.35, tmpY - 0.1);
		}
	}
	glEnd();
}

void drawNode(const char* str, GLfloat x, GLfloat y)
{
	double coeff = 0;
	coeff = (4 + depth) / pow(2, depth);
	float radB = coeff * radA;
	int count = 50;
	DrawCircle(x, y, radB, count);
	DrawOutline(x, y, radB);
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(x - 0.075, y - 0.075);
	const char* p;
	for (p = str; *p != '\0'; p++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}
}

void DrawOneline(Tree* root)
{
	if (root->parent != NULL)
	{
		glBegin(GL_LINES);
		glVertex2d(root->parent->x, root->parent->y);
		glVertex2d(root->x, root->y);
		glEnd();
	}
}

void DrawLine(Tree* root, void (*DrawOneLine)(Tree* root))
{
	if (root == NULL)
		return;
	(*DrawOneLine)(root);
	DrawLine(root->left, DrawOneLine);
	DrawLine(root->right, DrawOneLine);
}

void DrawOneNode(Tree* root)
{
	if (root->parent != NULL)
	{
		drawNode(to_string(root->data).c_str(), root->x, root->y);
	}
}

void DrawNode(Tree* root, void (*DrawOneNode)(Tree* node))
{
	if (root == NULL)
		return;
	(*DrawOneNode)(root);
	DrawNode(root->left, DrawOneNode);
	DrawNode(root->right, DrawOneNode);
	drawNode(to_string(root->data).c_str(), root->x, root->y);
}

void reshape(int h, int w)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, h, w);
	gluOrtho2D(-pow(2, depth - 1), pow(2, depth - 1), -depth, 5);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	DrawLine(tree, DrawOneline);
	DrawNode(tree, DrawOneNode);
	glutSwapBuffers();
}

void Tree::drawTree(int argc, char** argv, int winH, int winW)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(winH, winW);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("BinTree");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	int count;
	cin >> count;
	Tree* balT = tree->fill(count);
	//tree = tree->fill(count);
	balT->way(balT);
	cout << "Максимальный элемент: " << mx << endl;
	CountLevels(balT, LevelCount);
	CoordCalc(balT, Coord);
	balT->drawTree(argc, argv, 960, 720);
	return 0;
}