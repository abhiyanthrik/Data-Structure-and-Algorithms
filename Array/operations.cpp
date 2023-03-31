#include <iostream>
#include "array.h"
using namespace std;


/*
In this function I am running and observing the outputs of all the methods
applied on arrays.
*/
void operations()
{

    cout << "Algorithms in action...!\n";

    int a[] = { 3,4,7,10,15,22,26,31,38,42 };

    Array arr{ 20 };  // Declaration
    arr.setLength(10);
    for (int i = 0; i < 10; i++)
        arr.set(i, a[i]);  // Feeding data manually

    arr.display();  //Displaying the array

    //Let's append an element at the end of the array
    arr.append(7);
    cout << "Array after appending 7 in it:\n\n";
    arr.display();


    //Let's insert 6 at index 2
    arr.insert(2, 6);
    cout << "Array after inserting value 6 at position 2:\n\n";
    arr.display();

    //Let's delet the element at index 3
    int deleted = arr.deleteElement(3);
    cout << "Deleted value is: " << deleted << "\nAnd updated array is:\n";
    arr.display();

    //Linear search
    int index = arr.linearSearch(4);
    cout << "The address of the given value is: " << index << endl;

    //Binary search
    index = arr.binarySearch(10);
    cout << "The address of the given value using binary search is: " << index << endl;

    //Get
    int g = arr.get(2);
    cout << "Value at 3rd position is: " << g << endl;

    // Set
    arr.set(2, g + 2);
    cout << "New value at position 3 is: " << arr.get(2) << "\nAnd new array is:\n";
    arr.display();

    // Max
    int mx = arr.max();
    cout << "Maximum value in array is: " << mx << endl;

    //Sum of all the elements
    int ttl = arr.total();
    cout << "Sum of all the elements of array is: " << ttl << endl;

    //Average
    cout << "Average value of array is: " << arr.average() << endl;

    cout << "\n\nNow let's do some shifting and rotating operations.\n\nOriginal array:\n";
    arr.display();

    cout << "Left shifted array is:\n";
    arr.leftShift();
    arr.display();

    cout << "Right Shifted array is:\n";
    arr.rightShift();
    arr.display();

    cout << "Left rotated array is:\n";
    arr.rotateLeft();
    arr.display();

    cout << "Right rotated array is:\n";
    arr.rotateRight();
    arr.display();


    // Let's insert an element in a sorted array:
    int c[] = { 3,4,7,10,15,22,26,31,38,42 };

    Array arr1{ 15 };  // Declaration
    arr1.setLength(10);
    for (int i = 0; i < 10; i++)
        arr1.set(i, c[i]);  // Feeding data manually

    cout << "\n\n\nThe array is:\n";
    arr1.display();

    if (arr1.isSorted())
        cout << "The array is sorted.\n";
    else if (!arr1.isSorted())
        cout << "The array is not sorted.\n";

    arr1.insertInSorted(5);
    cout << "Array after insertion operation:\n";
    arr1.display();

    int y[] = { -1, 4, -2, 8, 7, -3, 6, -9, 12, -14, 6 };
    Array arr2{ 15 };  // Declaration
    arr2.setLength(11);
    for (int i = 0; i < 11; i++)
        arr2.set(i, y[i]);  // Feeding data manually

    cout << "Array before arranging:\n";
    arr2.display();
    arr2.rearrange();
    cout << "Array after rearranging:\n";
    arr2.display();

    int yelo[] = { 1,4,5,7,9,17 };
    Array arr3{ 6 };
    arr3.setLength(6);
    for (int i = 0; i < 6; i++)
        arr3.set(i, yelo[i]);

    int melo[] = { 2,3,5,10,17 };
    Array arr4{ 5 };
    arr4.setLength(5);
    for (int i = 0; i < 5; i++)
        arr4.set(i, melo[i]);

    // Merging two sorted arrays
    cout << "Arrays to be merged:\n";
    arr3.display();
    arr4.display();

    Array* arr5 = arr3.mergeSorted(&arr4);
    cout << "Merged array:\n";
    arr5->display();

    Array* set1 = arr3.unionSet(&arr4); // Union of two sorted sets
    Array* set2 = arr3.intersectionSet(&arr4);  // Intersection of two sorted sets
    Array* set3 = arr3.differenceSet(&arr4); // Difference between two sorted sets

    cout << "Union of sets:\n";
    set1->display();

    cout << "Intersection of sets is:\n";
    set2->display();

    cout << "Diffence:\n";
    set3->display();

}

