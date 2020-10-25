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
		// ���� ���. �������.
		(*root) = new node;
		(*root)->data = element;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else
	{
		// ��������� ����
		node **temp = (element > (*root)->data) ? &(*root)->right : &(*root)->left;

		add(element, temp);
	}
}

node* remove(node *root, int data) {

	node *p, *p2;

	// ������ ����
	if (!root) return NULL;

	if (root->data == data) {

		if (root->left == root->right) {
			// ������ ������
			free(root);
			return NULL;
		}
		else
			if (root->left == NULL) {
				// ���� �� ����������� ������ (�����)
				p = root->right;
				free(root);
				return p;
			}
			else
				if (root->right == NULL) {
					// ���� �� ����������� ������ (������)
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

	cout << "������� ���������� ��������� :";
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		cout << "������� ����� :";
		cin >> s;

		add(s, &tree);
	}

	// ���� ����� ���� ������ ����������� ������ ������� ���� � ������� = 5
	// remove(tree, 5);

	cout << "������ :" << endl;
	print(tree, 0);

	system("pause");
	return 0;
}