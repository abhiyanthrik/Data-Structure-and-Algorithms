#pragma once
#include<iostream>

void rearrange(int* arr, int j, int len)
{
	int x = arr[j];
	while (j < len)
	{
		if (2 * j + 1 < len || 2 * j + 2 < len)
		{
			if (2 * j + 1 < len && 2 * j + 2 < len
				&& arr[arr[j * 2 + 1] > arr[j * 2 + 2] ? j * 2 + 1 : j * 2 + 2] > x)
			{
				arr[j] = arr[arr[j * 2 + 1] > arr[j * 2 + 2] ? j * 2 + 1 : j * 2 + 2];
				j = arr[j * 2 + 1] > arr[j * 2 + 2] ? j * 2 + 1 : j * 2 + 2;
			}
			else if (2 * j + 1 < len && arr[2 * j + 1] > x)
			{
				arr[j] = arr[2 * j + 1];
				j = 2 * j + 1;
			}
			else if (arr[2 * j + 2] > x)
			{
				arr[j] = arr[2 * j + 2];
				j = 2 * j + 2;
			}
			else break;
		}
		else break;
	}
	arr[j] = x;
}

void swap(int* a, int* b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

void heapify(int* arr, int len)
{
	int i = len - 1, j = 0, k = 0, x = 0;
	while(i > -1)
	{
		j = 2 * i + 1, k = 2 * i + 2;
		if (j < len || k < len)
		{
			if (j < len && k < len)
			{
				if (arr[j] > arr[k])
				{
					if (arr[j] > arr[i])
					{
						swap(&arr[i], &arr[j]);
						rearrange(arr, j, len);
					}
				}
				else if (arr[k] > arr[i])
				{
					swap(&arr[i], &arr[k]);
					rearrange(arr, k, len);
				}
			}

			else if (j < len && arr[j] > arr[i])
			{
				swap(&arr[i], &arr[j]);
				rearrange(arr, j, len);
			}

			else if (arr[k] > arr[i])
			{
				swap(&arr[i], &arr[k]);
				rearrange(arr, k, len);
			}
		}
		i--;
	}
}
void heapsort(int* arr, int len)
{
	heapify(arr, len);
	int a = 0;
	while (len > 1)
	{
		a = arr[0];
		arr[0] = arr[len-- - 1];
		arr[len] = a;
		if (len > 1)
			rearrange(arr, 0, len);
	}
}

class Heap
{
private:
	int* root;
	int len;
	int size;

public:
	Heap() { len = 0, size = 0, root = NULL; }
	Heap(int size);
	void insert(int val);
	int search(int key);
	void display();
	int remove();
};

int Heap::search(int key)
{
	for (int i = 0; i < size; i++)
	{
		if (root[i] == key) return i;
	}
	return -1;
}

Heap::Heap(int size)
{
	len = size;
	this->size = 0;
	root = new int[len];
}

void Heap::insert(int val)
{
	int i = size;
	root[size++] = val;
	while (i > 0 && (val > root[(i % 2) ? i / 2 : i / 2 - 1]))
	{
		root[i] = root[(i % 2) ? i / 2 : i / 2 - 1];
		i = (i % 2) ? i / 2 : i / 2 - 1;
	}
	root[i] = val;
}

int Heap::remove()
{
	int a = root[0], i = 0;
	root[0] = root[(size--) - 1];
	int val = root[0];
	while (i < size)
	{
		if (2 * i + 1 < size || 2 * i + 2 < size)
		{
			if (2 * i + 1 < size && 2 * i + 2 < size)
			{
				if (root[root[2 * i + 1] > root[2 * i + 2] ? 2 * i + 1 : 2 * i + 2] > root[i])
				{
					swap(&root[i], &root[root[2 * i + 1] > root[2 * i + 2] ? 2 * i + 1 : 2 * i + 2]);
					i = root[2 * i + 1] > root[2 * i + 2] ? 2 * i + 1 : 2 * i + 2;
				}
				else break;

			}
			else if (2 * i + 1 < size)
			{
				if (root[2 * i + 1] > root[i])
					swap(&root[i], &root[2 * i + 1]), i = 2 * i + 1;
				else break;
				
			}
			else
			{
				if (root[2 * i + 2] > root[i])
					swap(&root[i], &root[2 * i + 2]), i = 2 * i + 2;
				else break;
			}
		}
		else break;
	}
	root[size] = a;
	return a;
}

void Heap::display()
{
	for (int i = 0; i < size; i++)
		std::cout << root[i] << " ";
	std::cout << std::endl;
}