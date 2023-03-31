#pragma once
#include<iostream>

using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int max(int arr[], int len)
{
	int x = arr[0];
	for (int i = 1; i < len; i++)
		x = x < arr[i] ? arr[i] : x;
	return x;
}

void bubbleSort(int* arr, int len)
{
	int i = 0, j = 0;
	bool flag = true;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]), flag = false;
		if (flag) break;
	}
}

void insertionSort(int arr[], int len)
{
	if (len < 2) return;
	int i, j, x;
	for (i = 1; i < len; i++)
	{
		j = i, x = arr[i];
		while (j && arr[j - 1] > x)
			arr[j--] = arr[j-1];
		arr[j] = x;
	}
}

void selectionSort(int* arr, int len)
{
	int i = 0, j, k;
	while (i < len)
	{
		j = k = i++;
		while (j < len)
			if (arr[j++] < arr[k])
				k = j-1;
		swap(&arr[i-1], &arr[k]);
	}
}

void quickSort(int arr[], int i, int j)
{
	int len = j - i + 1;
	if (len < 2 || i > j) return;
	else if (len == 2)
	{
		if (arr[i] > arr[j]) swap(&arr[i], &arr[j]);
		return;
	}
	int i_max = j;
	int k = i++;
	while (i < j)
	{
		while (arr[i] < arr[k] && i <= i_max) i++;
		while (arr[j] > arr[k] && j > k) j--;
		if(i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[k], &arr[j]);
	quickSort(arr, k, j - 1);
	quickSort(arr, j + 1, i_max);
}

void quickSort(int arr[], int len)
{
	quickSort(arr, 0, len - 1);
}

void merge(int arr[], int l, int mid, int h)
{
	if (l == h) return;
	int* auxiliary_arr = new int[h - l + 1];
	int i = l, j = mid+1, k = 0;
	while (i <= mid && j <= h)
	{
		if (arr[i] <= arr[j])
			auxiliary_arr[k++] = arr[i++];
		else
			auxiliary_arr[k++] = arr[j++];
	}
	for (; i <= mid; i++)
		auxiliary_arr[k++] = arr[i];
	for (; j <= h; j++)
		auxiliary_arr[k++] = arr[j];
	i = l, j = 0;
	for (; j < k; j++)
		arr[i++] = auxiliary_arr[j];

	delete auxiliary_arr;
}

void mergeSort(int arr[], int len)
{
	int p, i, l, mid, h;
	for(p = 2; p <= len; p*=2)
		for (i = 0; i + p - 1 <= len; i += p)
		{
			l = i;
			h = i + p - 1 >= len ? len - 1 : i + p - 1;
			mid = (l + h) / 2;
			merge(arr, l, mid, h);
		}
	if (p / 2 < len)
		merge(arr, 0, p / 2 - 1, len - 1);
}

void mergeSort(int arr[], int l, int h)
{
	if (l < h)
	{
		mergeSort(arr, l, (l + h) / 2);
		mergeSort(arr, ((l + h) / 2) + 1, h);
	}
	merge(arr, l, (l + h) / 2, h);
}

void countSort(int arr[], int len)
{
	int x = max(arr, len), j = 0;
	int* auxiliary_arr = new int[x+1] {0};
	for (int i = 0; i < len; i++)
	{
		auxiliary_arr[arr[i]]++;
	}
	for (int i = 0; i < x + 1; i++)
	{
		while (auxiliary_arr[i]-- > 0)
		{
			arr[j++] = i;
		}
	}
}

struct Node
{
	int data;
	Node* next;
};

void insert(Node* &node, int val)
{
	if (!node)
	{
		node = new Node;
		node->data = val;
		node->next = NULL;
	}

	else
	{
		Node* i = node;
		while (i->next)
			i = i->next;
		i->next = new Node;
		i->next->data = val;
		i->next->next = NULL;
	}
}

int remove(Node* &node)
{
	if (!node) return -1;
	Node* p = node;
	node = node->next;
	int x = p->data;
	delete p;
	return x;
}

void bucketSort(int arr[], int len)
{
	int x = max(arr, len), a = 0, j = 0;
	Node** bins = new Node*[x + 1]{ NULL };
	for (int i = 0; i < len; i++)
	{
		insert(bins[arr[i]], arr[i]);
	}
	for (int i = 0; i < x + 1; i++)
	{
		a = remove(bins[i]);
		if (a >= 0) arr[j++] = a;
	}
}

void shellSort(int arr[], int len)
{
	int gap, i, j, temp;
	for (gap = len / 2; gap >= 1; gap /= 2)
	{
		for (i = gap; i < len; i++)
		{
			temp = arr[i];
			j = i - gap;
			while (j >= 0 && arr[j] > temp)
			{
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = temp;
		}
	}
}

