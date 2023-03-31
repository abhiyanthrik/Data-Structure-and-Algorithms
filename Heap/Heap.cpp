#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
	int arr[27] = { 2,5,9,45,92,83,73,16,61,28,93,59,48,46,61,29,93,7,29,37,19,73,85,26,99,29,59 };
	Heap h{ 27 };
	for (int i = 0; i < 27; i++)
		h.insert(arr[i]);
	h.display();
}