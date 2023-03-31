#pragma once
#include<iostream>
using namespace std;

struct Node
{
	Node* last;
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* head;

public:
	LinkedList() { head = NULL; }
	LinkedList(int* arr, int size);
	~LinkedList();
	void display();
	Node* getHead() {return head;}
	void setHead(Node* p) { head = p; }
	int len();
	int sum();
	int max();
	int min();
	bool search(int key);
	void insert(int index, int val);
	void insertSorted(int val);
	int remove(int index);
	bool isSorted();
	bool isLoop();
	void removeDupes();
	void reverseList();
	void concate(LinkedList &list);
	void merge(LinkedList &list);
};


LinkedList::LinkedList(int* arr, int size)
{
	head = new Node;
	head->data = arr[0];
	head->next = NULL;
	Node* q = head, * temp;
	for (int i = 1; i < size; i++)
	{
		temp = new Node;
		temp->data = arr[i];
		temp->next = NULL;
		q->next = temp;
		q = temp;
	}
}

LinkedList::~LinkedList()
{
	Node* q = NULL;
	while (head)
	{
		q = head;
		head = head->next;
		delete q;
		q = NULL;
	}
}

void LinkedList::display()
{
	Node* p = head;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int LinkedList::len()
{
	Node* p = head;
	int c = 0;
	while (p)
	{
		p = p->next;
		c += 1;
	}
	return c;
}

int LinkedList::sum()
{
	Node* p = head;
	int s = 0;
	while (p)
	{
		s += p->data;
		p = p->next;
	}
	return s;
}


int LinkedList::max()
{
	Node* p = head;
	int m = p->data;
	p = p->next;
	while (p)
	{
		if (m < p->data)
			m = p->data;
		p = p->next;
	}
	return m;
}

int LinkedList::min()
{
	Node* p = head;
	int m = p->data;
	p = p->next;
	while (p)
	{
		if (m > p->data)
			m = p->data;
		p = p->next;
	}
	return m;
}

bool LinkedList::search(int key)
{
	if (head->data == key) return true;
	Node* q, * last;
	q = last = head;
	while (q)
	{
		if (q->data == key)
		{
			last->next = q->next;
			q->next = head;
			head = q;
			return true;
		}
		last = q;
		q = q->next;
	}
	return false;
}

void LinkedList::insert(int index, int val)
{
	if (index < 0 || index > len())
		return;
	Node* t = new Node;
	t->data = val;
	if (index == 0)
	{
		t->next = head;
		head = t;
	}

	else
	{
		Node* p = head;
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}

void LinkedList::insertSorted(int val)
{
	Node* temp = new Node;
	temp->data = val;

	if (!head)
		head = temp;

	else if (val < head->data)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		Node* p = head;
		while (p)
		{
			if (val < p->next->data)
			{
				temp->next = p->next;
				p->next = temp;
				return;
			}
			p = p->next;
		}
	}
}

int LinkedList::remove(int index) 
{
	if (index < 0 || index > len())
	{
		cerr << "Invalid index!!!\n";
		return 0;
	}

	Node* p = head, * q = NULL;
	int x = 0;
	if (index == 0)
		head = head->next;

	else
	{
		for (int i = 0; i < index; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
	}
	x = p->data;
	delete p;
	p = NULL;
	return x;
}

bool LinkedList::isSorted()
{
	if (!head)
	{
		cerr << "List is empty!!!";
		return false;
	}

	Node* p = head;
	while (p->next)
	{
		if (p->data > p->next->data)
			return false;
		p = p->next;
	}
	return true;
}

bool LinkedList::isLoop()
{
	Node* q, * r;
	q = r = head;

	do
	{
		q = q->next;
		r = r->next;
		r = r ? r->next : r;

	} while (q && r && q != r);
	if (q == r) return true;
	return false;
}

void LinkedList::removeDupes()
{
	Node* p = head, * q = NULL;
	while (p->next)
	{
		if (p->data == p->next->data)
		{
			q = p->next;
			p->next = p->next->next;
			delete q;
			continue;
		}
		p = p->next;
	}
}

void LinkedList::reverseList()
{
	Node* p = head, * q = NULL, * r = NULL;
	while (p)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	head = q;
}

void LinkedList::concate(LinkedList &list)
{
	Node* p = head;
	while (p->next)
		p = p->next;
	p->next = list.getHead();
	list.setHead(NULL);

}

void LinkedList::merge(LinkedList &list)
{
	Node* p = head, * q = list.getHead(), * t = NULL;

	if (p->data <= q->data)
	{
		head = t = p;
		p = p->next;
		t->next = NULL;
	}

	else
	{
		head = t = q;
		q = q->next;
		t->next = NULL;
	}

	while (p && q)
	{
		if (p->data <= q->data)
		{
			t->next = p;
			t = p;
			p = p->next;
			t->next = NULL;

		}
		else
		{
			t->next = q;
			t = q;
			q = q->next;
			t->next = NULL;
		}

	}
	if (p) t->next = p;
	else if(q) t->next = q;
	list.setHead(NULL);
}


class Circular
{
private:
	Node* head;
public:
	Circular();
	Circular(int* arr, int size);
	void display();
	int len();
	Node* search(int key);
	void insert(int index, int val);
	int remove(int index);
	void reverse();
};



Circular::Circular()
{
	head = NULL;
}


Circular::Circular(int* arr, int size)
{
	head = new Node;
	head->data = arr[0];
	head->next = NULL;
	Node* p = head, * temp = NULL;
	for (int i = 1; i < size; i++)
	{
		temp = new Node;
		temp->data = arr[i];
		temp->next = head;
		p->next = temp;
		p = p->next;
	}
}

void Circular::display()
{
	Node* p = head;
	cout << p->data << " ";
	p = p->next;
	while (p != head)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int Circular::len()
{
	if (head == NULL) return 0;
	if (head->next == head) return 1;
	Node* p = head->next;
	int l = 2;
	while (p->next != head)
	{
		p = p->next;
		l++;
	}
	return l;
}

Node* Circular::search(int key)
{
	if (!head) return NULL;
	if (head->data == key) return head;
	if (head->next == head) return NULL;
	Node* p = head->next;
	while (p != head)
	{
		if (p->data == key) return p;
		p = p->next;
	}
	return NULL;
}

void Circular::insert(int index, int val)
{
	if (index < 0 || index > len())
		return;
	Node* p = new Node , * q = head;
	p->data = val;
	p->next = NULL;

	if (index == 0)
	{
		while (q->next != head)
			q = q->next;
		p->next = head;
		q->next = p;
		head = p;
	}

	else
	{
		int t = 0;
		while (t != index-1)
		{
			q = q->next;
			t++;
		}
		p->next = q->next;
		q->next = p;
	}
}

int Circular::remove(int index)
{
	if (index < 0 || index > len()) return -1;
	int x = -1;
	if (index == 0)
	{
		x = head->data;
		if (head->next == head)
		{
			delete head;
			head = NULL;
			return x;
		}
		Node* p = head;
		while (p->next != head)
			p = p->next;
		p->next = head->next;
		delete head;
		head = p->next;
		return x;
	}
	Node* p = head, * q = NULL;
	for (int i = 0; i < index-1; i++)
		p = p->next;
	q = p->next;
	p->next = q->next;
	x = q->data;
	delete q;
	q = NULL;
	return x;
}

//void Circular::reverse()
//{
//	if (head == NULL || head->next == head || head->next->next == head) return;
//	Node* p = head, * t = NULL;
//	Node* q = p->next;
//	Node* r = q->next;
//
//	q->next = p;
//	p = q;
//	q = r;
//	r = r->next;
//
//	while (p!= head)
//	{
//		q->next = p;
//		t = p;
//		p = q;
//		q = r;
//		r = r->next;
//	}
//	head = t;
//}


void Circular::reverse()
{
	if (head == NULL || head->next == head || head->next->next == head) return;
	Node* p = head;
	Node* q = NULL;
	Node* r = NULL;

	while (p->next->next)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	head->next = p;
	p->next = q;
	head = p;
}

class DoublyCircular
{
private:
	Node* head;
public:
	DoublyCircular();
	DoublyCircular(int* arr, int size);
	void display();
	int len();
	Node* search(int key);
	void insert(int index, int val);
	int remove(int index);
	void reverse();
};

DoublyCircular::DoublyCircular()
{
	head = NULL;
}

DoublyCircular::DoublyCircular(int* arr, int size)
{
	head = new Node;
	head->last = head;
	head->data = arr[0];
	head->next = head;
	Node* p = head, * t = NULL;
	for (int i = 1; i < size; i++)
	{
		t = new Node;
		t->last = p;
		t->next = head;
		t->data = arr[i];
		p->next = t;
		p = p->next;
		head->last = p;
		t = NULL;
	}
}

void DoublyCircular::display()
{
	Node* p = head;
	while (p->next != head)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << " \n";
}

int DoublyCircular::len()
{
	int l = 0; Node* p = head;
	do
	{
		l++;
		p = p->next;
	} while (p!=head);
	return l;
}

Node* DoublyCircular::search(int key)
{
	if (!head || head->next == head) return NULL;
	if (head->data == key) return head;

	Node* p = head->next;
	while (p != head)
	{
		if (p->data == key) return p;
		p = p->next;
	}
	return NULL;
}

void DoublyCircular::insert(int index, int val)
{
	Node* p = new Node;
	p->data = val;
	p->next = p->last = p;
	if (index == 0)
	{
		p->next = head;
		p->last = head->last;
		head->last->next = p;
		head->last = p;
		head = p;
		return;
	}
	Node* t = head;
	for (int i = 0; i < index-1; i++)
		t = t->next;
	t->next->last = p;
	p->next = t->next;
	t->next = p;
	p->last = t;
}

int DoublyCircular::remove(int index)
{
	if (index < 0 || index > len()) return -1;
	int x = 0;
	if (index == 0)
	{
		Node* p = head->next;
		head->next->last = head->last;
		head->last->next = head->next;
		x = head->data;
		delete head;
		head = p;
		return x;
	}
}

void DoublyCircular::reverse()
{
	if (head == NULL || head->next == head || head->next->next == head) return;
	Node* p = head;
	Node* q = NULL;
	q = p->last;
	p->last = p->next;
	p->next = q;
	p = p->next;
	q = NULL;
	while (p != head)
	{
		q = p->last;
		p->last = p->next;
		p->next = q;
		p = p->next;
		q = NULL;
	}
	head = p->next;
	
}