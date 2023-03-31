#pragma once
#include<iostream>
#include"/home/rohit/Documents/DSA/Queue/queue.h"
#include"/home/rohit/Documents/DSA/Stack/stack.h"

using namespace std;

struct Node
{
	Node* left;
	int data;
	Node* right;
};

class Tree
{
private:
	Node* root;
	void inOrder(Node* p);
	void preOrder(Node* p);
	void postOrder(Node* p);
	void levelOrder(Node* p);
	int leaves(Node* p);
	int cnt(Node* p);
	int deg2(Node* p);
	int deg1(Node* p);
	int deg2Or1(Node* p);
	int height(Node* p);
	int levels(Node* p);
public:
	Tree();
	~Tree();
	void inOrder();
	void preOrder();
	void postOrder();
	void levelOrder();
	int countNodes();
	int countLeaves();
	int twoDNodes();
	int oneDNodes();
	int deg2Or1();
	int height();
	int levels();
};

Tree::Tree()
{
	int a = 0;
	root = new Node;
	root->left = root->right = NULL;
	cout << "Enter the value of root node: ";
	cin >> a; cout << endl;
	root->data = a;
	Node* p = NULL, * t = NULL;
	queue::Queue<Node*> q;
	q.enqueue(root);
	while (!q.isEmpty())
	{
		p = q.dequeue();
		cout << "Enter Left child of " << p->data << ": ";
		cin >> a; cout << endl;
		if (a == -1)
			p->left = NULL;
		else
		{
			t = new Node;
			t->data = a;
			t->left = t->right = NULL;
			q.enqueue(t);
			p->left = t;
			t = NULL;
		}

		cout << "Enter right child of " << p->data << ": ";
		cin >> a; cout << endl;
		if (a == -1)
			p->right = NULL;
		else
		{
			t = new Node;
			t->data = a;
			t->left = t->right = NULL;
			q.enqueue(t);
			p->right = t;
			t = NULL;
		}

	}
}

Tree::~Tree()
{
	queue::Queue<Node*> q;
	q.enqueue(root);
	Node* p = NULL;
	while (!q.isEmpty())
	{
		p = q.dequeue();
		if (p->left)
			q.enqueue(p->left);
		if (p->right)
			q.enqueue(p->right);
		delete p;
		p = NULL;
	}
}

void Tree::preOrder(Node* p)
{
	if (!p) return;
	cout << p->data << " ";
	preOrder(p->left);
	preOrder(p->right);
}

void Tree::postOrder(Node* p)
{
	if (!p) return;
	cout << p->data << " ";
	postOrder(p->right);
	postOrder(p->left);
}

void Tree::inOrder(Node* p)
{
	if (!p) return;
	inOrder(p->left);
	cout << p->data << " ";
	inOrder(p->right);
}

void Tree::levelOrder(Node* p)
{
	Node* t = NULL;
	queue::Queue<Node*> q;
	q.enqueue(p);
	while (!q.isEmpty())
	{
		t = q.dequeue();
		cout << t->data << " ";
		if (t->left)
			q.enqueue(t->left);
		if (t->right)
			q.enqueue(t->right);
	}
	cout << endl;
}

int Tree::cnt(Node* p)
{
	if (p)
		return cnt(p->left) + cnt(p->right) + 1;
	return 0;
}

int Tree::leaves(Node* p)
{
	if (p)
	{
		if (!p->left && !p->right)
			return leaves(p->left) + leaves(p->right) + 1;
		return leaves(p->left) + leaves(p->right);
	}
	return 0;
}

int Tree::deg2(Node* p)
{
	if (p)
	{
		if (p->left && p->right)
			return deg2(p->left) + deg2(p->right) + 1;
		return deg2(p->left) + deg2(p->right);
	}
	return 0;
}

int Tree::deg1(Node* p)
{
	if (p)
	{
		if (!p->left ^ !p->right)
			return deg1(p->left) + deg1(p->right) + 1;
		return deg1(p->left) + deg1(p->right);
	}
	return 0;
}

int Tree::deg2Or1(Node* p)
{
	if (p)
	{
		if (p->left || p->right)
			return deg2Or1(p->left) + deg2Or1(p->right) + 1;
		return deg2Or1(p->left) + deg2Or1(p->right);
	}
	return 0;
}

int Tree::height(Node* p)
{
	if (p)
	{
		if (p->left || p->right)
		{
			int x = height(p->left);
			int y = height(p->right);
			return x >= y ? x + 1 : y + 1;
		}
		return 0;
	}
	return 0;
}


int Tree::levels(Node* p)
{
	if (p)
	{
		if (p->left || p->right)
		{
			int x = levels(p->left);
			int y = levels(p->right);
			return x >= y ? x + 1: y + 1;
		}
		return 1;
	}
	return 0;
}

void Tree::preOrder()
{
	preOrder(root);
	cout << endl;
}

void Tree::postOrder()
{
	postOrder(root);
	cout << endl;
}

void Tree::inOrder()
{
	inOrder(root);
	cout << endl;
}

void Tree::levelOrder()
{
	levelOrder(root);
}


int Tree::countNodes()
{
	return cnt(root);
}

int Tree::countLeaves()
{
	return leaves(root);
}

int Tree::twoDNodes()
{
	return deg2(root);
}

int Tree::oneDNodes()
{
	return deg1(root);
}
int Tree::deg2Or1()
{
	return deg2Or1(root);
}

int Tree::height()
{
	return height(root);
}

int Tree::levels()
{
	return levels(root);
}



class BST
{
private:
	Node* root;
	int height(Node* p);
	void preOrder(Node* p);
	void levelOrder(Node* p);
	void inOrder(Node* p);
	Node* Delete(Node* p, int key);
	Node* predecessor(Node* p);
	Node* successor(Node* p);
	int balanceFactor(Node* p);
	void bFactor(Node* p);
	void llRotation(Node* A);
	void rrRotation(Node* A);
	void lrRotation(Node* A);
	void rlRotation(Node* A);
	bool isBalanced(Node* p);
	int treeBF(Node* p);
	void balance(Node* p);
	Node* imbalanced(Node* p);
public:
	BST() { root = NULL; }
	BST(int* arr, int n);
	void createAVL(int* arr, int n);
	void convertIntoAVL();
	void display();
	int height();
	Node* search(int key);
	void insert(int val);
	void remove(int key);
	void bFactor();
	int treeBF();
	bool isBalanced();
	void avlDelete(int key);
	void insertAVL(int key);
};

BST::BST(int* arr, int n)
{
	int i = 1;
	int x = 0;
	stack::LinkedStack<Node*> st;
	root = new Node;
	root->data = arr[0];
	root->left = root->right = NULL;
	st.push(root);
	Node* p = root, * t = NULL;
	while (i < n)
	{
		x = arr[i];
		if (x < p->data)
		{
			t = new Node;
			t->left = t->right = NULL;
			t->data = x;
			p->left = t;
			st.push(p);
			p = t;
			i++;
		}
		else
		{
			if (!st.isEmpty())
			{
				if (x < st.stackTop()->data)
				{
					t = new Node;
					t->left = t->right = NULL;
					t->data = x;
					p->right = t;
					p = t;
					i++;
				}
				else
				{
					p = st.pop();
				}
			}
			else
			{
				t = new Node;
				t->left = t->right = NULL;
				t->data = x;
				p->right = t;
				p = t;
				i++;
			}
		}
	}
}

int BST::height(Node* p)
{
	if (p)
	{
		if (p->left || p->right)
		{
			int x = height(p->left);
			int y = height(p->right);
			return x >= y ? x + 1 : y + 1;
		}
		return 0;
	}
	return -1;
}

int BST::height()
{
	return height(root);
}

Node* BST::predecessor(Node* p)
{
	Node* t = p->left, * r = NULL;
	while (t)
	{
		r = t;
		t = t->right;
	}
	return r;
}

Node* BST::successor(Node* p)
{
	Node* t = p->right, * r = NULL;
	while (t)
	{
		r = t;
		t = t->left;
	}
	return r;
}

Node* BST::Delete(Node* p, int key) {
	Node* q;

	if (p == NULL) {
		return NULL;
	}

	if (!p->left && !p->right) {
		if (p == root) {
			root = NULL;
		}
		delete p;
		return NULL;
	}

	if (key < p->data) {
		p->left = Delete(p->left, key);
	}
	else if (key > p->data) {
		p->right = Delete(p->right, key);
	}
	else {
		if (height(p->left) > height(p->right)) {
			q = predecessor(p);
			p->data = q->data;
			p->left = Delete(p->left, q->data);
		}
		else {
			q = successor(p);
			p->data = q->data;
			p->right = Delete(p->right, q->data);
		}
	}
	return p;
}

void BST::preOrder(Node* p)
{
	if (!p) return;
	cout << p->data << " ";
	preOrder(p->left);
	preOrder(p->right);
}

void BST::levelOrder(Node* p)
{
	Node* t = NULL;
	queue::Queue<Node*> q;
	q.enqueue(p);
	while (!q.isEmpty())
	{
		t = q.dequeue();
		cout << t->data << " ";
		if (t->left)
			q.enqueue(t->left);
		if (t->right)
			q.enqueue(t->right);
	}
	cout << endl;
}

void BST::inOrder(Node* p)
{
	if (!p) return;
	inOrder(p->left);
	cout << p->data << " ";
	inOrder(p->right);
}

void BST::display()
{
	inOrder(root);
	cout << endl;
}

Node* BST::search(int key)
{
	Node* p = root;
	while (p)
	{
		if (p->data == key) return p;
		if (key > p->data) p = p->right;
		else p = p->left;
	}
	return NULL;
}

void BST::insert(int val)
{
	Node* p = root, * t = NULL;
	while (p)
	{
		if (p->data == val) return;
		if (val < p->data)
		{
			t = p;
			p = p->left;
		}
		else
		{
			t = p;
			p = p->right;
		}
	}
	Node* q = new Node;
	q->left = q->right = NULL;
	q->data = val;
	if (val < t->data)
		t->left = q;
	else
		t->right = q;
}

void BST::remove(int key)
{
	Delete(root, key);
}

int BST::balanceFactor(Node* p)
{
	if (!p) return 0;
	return height(p->left) - height(p->right);
}

void BST::bFactor(Node* p)
{
	if (p)
	{
		bFactor(p->left);
		cout << "bf of " << p->data << " is " << balanceFactor(p) << endl;
		bFactor(p->right);
	}
}

void BST::bFactor()
{
	bFactor(root);
}

bool BST::isBalanced(Node* p)
{
	if (!p || (!p->left && !p->right)) return true;
	bool a = false, b = false, c = false;
	a = balanceFactor(p) >= -1 && balanceFactor(p) <= 1;
	b = !p->left ? true : isBalanced(p->left);
	c = !p->right ? true : isBalanced(p->right);
	return a && b && c;
}

bool BST::isBalanced()
{
	return isBalanced(root);
}

int BST::treeBF(Node* p)
{
	if (!p || (!p->left && !p->right)) return 0;
	int a, b, c;
	a = b = c = 0;
	a = balanceFactor(p);
	b = treeBF(p->left);
	c = treeBF(p->right);
	return a*a > (c*c > b*b ? c*c : b*b) ? a : (c*c > b*b ? c : b);
}

int BST::treeBF()
{
	return treeBF(root);
}

void BST::llRotation(Node* A)
{
	Node* B = A->left;
	Node* C = B->left;
	A->left = C;
	B->left = B->right;
	B->right = A->right;
	A->right = B;
	int temp = A->data;
	A->data = B->data;
	B->data = temp;

	/*A->left = B->right;
	B->right = A;
	p = B;*/
}

void BST::rrRotation(Node* A)
{
	Node* B = A->right;
	Node* C = B->right;

	A->right = C;
	B->right = B->left;
	B->left = A->left;
	A->left = B;
	int temp = A->data;
	A->data = B->data;
	B->data = temp;
	/*A->right = B->left;
	B->left = A;
	p = B;*/
	
}

void BST::lrRotation(Node* A)
{
	Node* B = A->left;
	Node* C = B->right;

	int temp = A->data;
	A->data = C->data;
	B->right = C->left;
	C->left = C->right;
	C->right = C->left;
	A->right = C;
	C->data = temp;
	/*B->right = C->left;
	A->left = C->right;
	C->left = B;
	C->right = A;
	p = C;*/
}

void BST::rlRotation(Node* A)
{
	int temp = A->data;
	Node* B = A->right;
	Node* C = B->left;

	/*A->right = C->left;
	B->left = C->right;
	C->left = A;
	C->right = B;
	p = C;*/

	A->data = C->data;
	B->left = C->right;
	C->right = C->left;
	C->left = A->left;
	A->left = C;
	C->data = temp;
}

void BST::balance(Node* p)
{
	int bf = balanceFactor(p);
	if (bf > 0)
	{
		Node* q = p->left;
		int qlh = height(q->left);
		int qrh = height(q->right);
		if (qlh > qrh)
			llRotation(p);
		else lrRotation(p);
	}
	else
	{
		Node* q = p->right;
		int qrh = height(q->right);
		int qlh = height(q->left);
		if (qrh > qlh)
			rrRotation(p);
		else rlRotation(p);
	}

}

Node* BST::imbalanced(Node* p)
{
	if (!p || (!p->left && !p->right)) return NULL;
	if (imbalanced(p->left)) return p->left;
	if (imbalanced(p->right)) return p->right;
	if (balanceFactor(p) * balanceFactor(p) > 1) return p;
	return NULL;
}

void BST::createAVL(int* arr, int n)
{
	root = new Node;
	root->left = root->right = NULL;
	root->data = arr[0];
	int i = 1;
	while (i < n)
	{
		insert(arr[i++]);
		if (!isBalanced())
		{
			Node* p = imbalanced(root);
			balance(p);
		}
	}
}

void BST::convertIntoAVL()
{
	while (!isBalanced())
	{
		Node* p = imbalanced(root);
		balance(p);
	}
}

void BST::avlDelete(int key)
{
	remove(key);
	while (!isBalanced())
	{
		Node* p = imbalanced(root);
		balance(p);
	}
}

void BST::insertAVL(int key)
{
	insert(key);
	while (!isBalanced())
	{
		Node* p = imbalanced(root);
		balance(p);
	}
}