#include "stdafx.h"
#include <iostream>

struct node
{
	int data;

	node *left, *right;
};

void add(int element, node **root)
{
	if ((*root) == NULL)
	{
		// Узла нет. Создаем.
		(*root) = new node;
		(*root)->data = element;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else
	{
		// Добавляем узел
		node **temp = (element > (*root)->data) ? &(*root)->right : &(*root)->left;

		add(element, temp);
	}
}

node* remove(node *root, int data) {

	node *p, *p2;

	// Пустой узел
	if (!root) return NULL;

	if (root->data == data) {

		if (root->left == root->right) {
			// Дерево пустое
			free(root);
			return NULL;
		}
		else
			if (root->left == NULL) {
				// Одно из поддеревьев пустое (левое)
				p = root->right;
				free(root);
				return p;
			}
			else
				if (root->right == NULL) {
					// Одно из поддеревьев пустое (правое)
					p = root->left;
					free(root);
					return p;
				}
				else {
					p2 = root->right;
					p = root->right;

					while (p->left)  p = p->left;
					p->left = root->left;
					free(root);
					return p2;
				}
	}

	if (root->data < data) {
		root->right = remove(root->right, data);
	}
	else {
		root->left = remove(root->left, data);
	}

	return root;
}

node* search(node *root, int data) {

	if (!root) return root;

	while (root->data != data) {

		root = (data < root->data) ? root->left : root->right;

		if (root == NULL) break;
	}
	return root;
}

void print(node *root, int u)
{
	using namespace std;

	if (root == NULL) return;
	else
	{
		print(root->left, ++u);
		for (int i = 0; i < u; ++i) cout << ">";
		cout << root->data << endl;
		u--;
	}
	print(root->right, ++u);
}

int main()
{
	using namespace std;

	setlocale(LC_ALL, "");

	int num, s;
	node *tree = NULL;

	cout << "Введите количество элементов :";
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		cout << "Введите число :";
		cin >> s;

		add(s, &tree);
	}

	// Этот метод если убрать комментарии должен удалить узел с данными = 5
	// remove(tree, 5);

	cout << "Дерево :" << endl;
	print(tree, 0);

	system("pause");
	return 0;
}