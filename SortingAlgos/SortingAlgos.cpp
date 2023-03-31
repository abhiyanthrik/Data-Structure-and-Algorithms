#include <iostream>
#include "sorting.h"

using namespace std;

int main()
{
    int arr[15] = { 100, 143, 23, 34, 4, 14, 29, 58, 7, 2, 6, 8, 45, 5, 19 };
    // selectionSort(arr, 10);
    int arr1[5] = { 10, 8, 9, 12, 7 };
    // mergeSort(arr, 0, 14);
    for (int i = 0; i < 15; i++)
        cout << arr[i] << " ";
    cout << endl;

    int arr2[11] = { 4,6,12,15,18,21,2,7,9,17,20 };

    /*countSort(arr, 15);
    for (int i = 0; i < 15; i++)
        cout << arr[i] << " ";*/
    cout << endl;
    shellSort(arr, 15);
    for (int i = 0; i < 15; i++)
        cout << arr[i] << " ";
    cout << endl;
}
