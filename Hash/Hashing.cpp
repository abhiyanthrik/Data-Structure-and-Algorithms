#include <iostream>
#include "hash.h"
using namespace std;

int main()
{
	int arr[21] = { 2,3,4,5,6,7,8,9,1,10,20,17, 27, 52, 72, 52, 41, 87, 32, 12, 11 };
	DoubleHash hash(arr, 21);
	hash.display();
	hash.insert(15);
	hash.display();
	hash.insert(19);
	hash.display();
	int ind = hash.search(72);
	ind > -1 ? cout << 72 << " is at " << ind << endl: cout << "Not found...\n";
	/*hash.remove(20);
	hash.display();
	hash.remove(27);
	hash.display();*/
	int arr2[5] = { 23, 43, 13, 27, 0 };
	DoubleHash h(arr2, 5);
	h.display();
}