#pragma once
#include <iostream>
using namespace std;

class IdealHash
{
private:
	int* hash_table;
	int size;
	int max(int arr[], int len);

public:
	IdealHash() { hash_table = NULL, size = 0; }
	IdealHash(int arr[], int len);
	~IdealHash() { delete hash_table; }
	void display();
	void insert(int key);
	int search(int key);
	int remove(int key);
};

int IdealHash::max(int arr[], int len)
{
	int m = arr[0];
	for (int i = 1; i < len; i++)
		m = arr[i] > m ? arr[i] : m;
	return m;
}

IdealHash::IdealHash(int arr[], int len)
{
	int index = 0;
	size = max(arr, len) + 1;
	hash_table = new int[size] {0};
	for (int i = 0; i < len; i++)
	{
		index = arr[i];
		hash_table[index] = arr[i];
	}
}

void IdealHash::display()
{
	for (int i = 0; i < size; i++)
		cout << hash_table[i] << " ";
	cout << endl;
}

void IdealHash::insert(int key)
{
	if (key > size - 1)
	{
		int new_size = key + 1;
		int* new_hash = new int[new_size] {0};
		for (int i = 0; i < size; i++)
			new_hash[i] = hash_table[i];
		new_hash[key] = key;
		int* t = hash_table;
		hash_table = new_hash;
		delete t;
		t = new_hash = NULL;
	}
	else
	{
		hash_table[key] = key;
	}
}

int IdealHash::search(int key)
{
	if (key > size - 1) return 0;
	if (hash_table[key]) return key;
	return 0;
}

int IdealHash::remove(int key)
{
	int val = hash_table[key];
	if (val == size - 1)
	{
		hash_table[key] = 0;
		size = key;
		while (!hash_table[size--]);
		++++size;
		int* new_hash = new int[size] {0};
		for (int i = 0; i < size; i++)
			new_hash[i] = hash_table[i];
		delete hash_table;
		hash_table = new_hash;
		new_hash = NULL;
		return val;
	}
	hash_table[key] = 0;
	return val;
}


struct Node
{
	int data;
	Node* next;
};

class OpenHash // Chaining
{
private:
	Node** hash_table;
	int size = 10;
public:
	OpenHash() { hash_table = NULL, size = 0; }
	OpenHash(int arr[], int len);
	~OpenHash() { delete hash_table; }
	void display();
	void insert(int key);
	Node* search(int key);
	int remove(int key);
};

OpenHash::OpenHash(int arr[], int len)
{
	hash_table = new Node * [size] {NULL};
	Node* head = NULL, * tail = NULL;
	int index;
	for (int i = 0; i < len; i++)
	{
		index = arr[i] % 10;
		if (!hash_table[index])
		{
			head = new Node;
			head->data = arr[i];
			head->next = NULL;
			hash_table[index] = head;
			head = NULL;
		}
		else
		{
			head = hash_table[index];
			while (head && head->data <= arr[i])
				tail = head, head = head->next;
			if (!head)
			{
				head = new Node;
				head->data = arr[i];
				head->next = NULL;
				tail->next = head;
			}
			else
			{
				tail->next = new Node;
				tail->next->data = arr[i];
				tail->next->next = head;
			}
		}
	}
}

void OpenHash::display()
{
	Node* head = NULL;
	for (int i = 0; i < size; i++)
	{
		head = hash_table[i];
		while (head)
		{
			cout << head->data << " ";
			head = head->next;
		}
	}
	cout << endl;
}


void OpenHash::insert(int key)
{
	Node* head = NULL, * tail = NULL;
	int index = key % 10;
	if (!hash_table[index])
	{
		head = new Node;
		head->data = key;
		head->next = NULL;
		hash_table[index] = head;
		head = NULL;
	}
	else
	{
		head = hash_table[index];
		while (head && head->data <= key)
			tail = head, head = head->next;
		if (!head)
		{
			head = new Node;
			head->data = key;
			head->next = NULL;
			tail->next = head;
		}
		else
		{
			tail->next = new Node;
			tail->next->data = key;
			tail->next->next = head;
		}
	}
}

Node* OpenHash::search(int key)
{
	Node* p = NULL;
	int i = key % 10;
	p = hash_table[i];
	while (p)
	{
		if (p->data == key) return p;
		if (p->data > key) break;
		p = p->next;
	}
	return NULL;
}

int OpenHash::remove(int key)
{
	Node* p = NULL, * q = NULL;
	int i = key % 10, x;
	if (!hash_table[i]) return -1;
	if (hash_table[i]->data == key)
	{
		p = hash_table[i];
		x = p->data;
		hash_table[i] = hash_table[i]->next;
		delete p;
		return x;
	}
	q = hash_table[i];
	p = q->next;
	while (p)
	{
		if (p->data == key)
		{
			q->next = p->next;
			x = p->data;
			delete p;
			return x;
		}
		q = p;
		p = p->next;
	}
	return -1;
}

class LinearProbing
{
private:
	int* hash_table;
	int size;
public:
	LinearProbing() { hash_table = NULL, size = 0; }
	LinearProbing(int arr[], int len);
	~LinearProbing() { delete hash_table; }
	void display();
	void insert(int key);
	int search(int key);
};

void LinearProbing::insert(int key)
{
	int index = key % size, aux_index = index + 1;
	if (!hash_table[index])
	{
		hash_table[index] = key;
		return;
	}
	int i = 1;
	while (aux_index != index)
	{
		aux_index = (key + i++) % size;
		if (!hash_table[aux_index])
		{
			hash_table[aux_index] = key;
			return;
		}
	}
}

LinearProbing::LinearProbing(int arr[], int len)
{
	size = len * 2;
	hash_table = new int[size] {0};
	for (int i = 0; i < len; i++)
		insert(arr[i]);
}

void LinearProbing::display()
{
	for (int i = 0; i < size; i++)
		cout << hash_table[i] << " ";
	cout << endl;
}

int LinearProbing::search(int key)
{
	int index = key % size, aux_index = index + 1;
	if (hash_table[index] == key)
	{
		return index;
	}
	int i = 1;
	while (aux_index != index)
	{
		aux_index = (key + i++) % size;
		if (hash_table[aux_index] == key)
		{
			return aux_index;
		}
	}
	return -1;
}


class QuadProbing
{
private:
	int* hash_table;
	int size;
public:
	QuadProbing() { hash_table = NULL, size = 0; }
	QuadProbing(int arr[], int len);
	~QuadProbing() { delete hash_table; }
	void display();
	void insert(int key);
	int search(int key);
};

void QuadProbing::insert(int key)
{
	int index = key % size, aux_index = index + 1;
	if (!hash_table[index])
	{
		hash_table[index] = key;
		return;
	}
	int i = 0;
	while (aux_index != index)
	{
		aux_index = (key + ++i*i) % size;
		if (!hash_table[aux_index])
		{
			hash_table[aux_index] = key;
			return;
		}
	}
}

QuadProbing::QuadProbing(int arr[], int len)
{
	size = len * 2;
	hash_table = new int[size] {0};
	for (int i = 0; i < len; i++)
		insert(arr[i]);
}

void QuadProbing::display()
{
	for (int i = 0; i < size; i++)
		cout << hash_table[i] << " ";
	cout << endl;
}

int QuadProbing::search(int key)
{
	int index = key % size, aux_index = index + 1;
	if (hash_table[index] == key)
	{
		return index;
	}
	int i = 0;
	while (aux_index != index)
	{
		aux_index = (key + ++i*i) % size;
		if (hash_table[aux_index] == key)
		{
			return aux_index;
		}
	}
	return -1;
}


class DoubleHash
{
private:
	int* hash_table;
	int size,r ;
	int prime(int p);
	int hashFun1(int x);
	int hashFun2(int x);
public:
	DoubleHash() { hash_table = NULL, r = size = 0; }
	DoubleHash(int arr[], int len);
	~DoubleHash() { delete hash_table; }
	void display();
	void insert(int key);
	int search(int key);
};

int DoubleHash::prime(int p)
{
	int d = p / 2;
	while (d > 1)
	{
		if (p % d--) continue;
		else return prime(--p);
	}
	return p;
}

int DoubleHash::hashFun1(int x)
{
	return x % r;
}

int DoubleHash::hashFun2(int x)
{
	return 2 * r - x; // h2(x) = r - (x - r) : secondary hash function
}

void DoubleHash::insert(int key)
{
	int index = key % r, aux_index = index + 1;
	if (!hash_table[index])
	{
		hash_table[index] = key;
		return;
	}
	
	int i = 0;
	while (aux_index != index)
	{
		aux_index = (hashFun1(key) + ++i * hashFun2(key)) % r;
		if (!hash_table[aux_index])
		{
			hash_table[aux_index] = key;
			return;
		}
	}
}

DoubleHash::DoubleHash(int arr[], int len)
{
	size = len * 2;
	hash_table = new int[size] {0};
	r = prime(size);
	for (int i = 0; i < len; i++)
		insert(arr[i]);
}

void DoubleHash::display()
{
	for (int i = 0; i < size; i++)
		cout << hash_table[i] << " ";
	cout << endl;

	// cout << primeBelow(5) << endl;
}

int DoubleHash::search(int key)
{
	int index = key % r, aux_index = index + 1;
	if (hash_table[index] == key)
	{
		return index;
	}
	int i = 0;
	while (aux_index != index)
	{
		aux_index = (hashFun1(key) + ++i * hashFun2(key)) % r;
		if (hash_table[aux_index] == key)
		{
			return aux_index;
		}
	}
	return -1;
}
