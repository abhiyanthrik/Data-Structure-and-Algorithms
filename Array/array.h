/*
This header file contains definition of array ADT and operations that are applied on it.
*/


#pragma once
#include <iostream>

void operations();
void challenges();

// The data type
class Array
{
private:
    int* A;
    int size;
    int length;

    void swap(int* a, int* b)
    {
        /*
        Description: swaps two numbers in place.

        Inputs: 
            int* a = Pointer to first number
            int* b = pointer to second number
        */
        int temp = *a;
        *a = *b;
        *b = temp;
    }

public:

    Array() // Default constructor 
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz)
    {
        /*
        Initialize the object with desired size of the array.

        Input:
            int sz: desired size of the array
        */
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array() { delete []A; }

    int getLength()
    {
        // This funtion returns the lenth upto which the array is filled
        return length;
    }

    int getSize()
    {
        // This function returns the size upto which array could store elements
        return size;
    }

    void setLength(int lth)
    {
        // This function is used to change the lenth of the array.
        length = lth;
    }

    void setSize(int sz)
    {
        // This function is used to change the size of the array.
        size = sz;
    }

    void setPtr(int* p)
    {
        // To reassign new location to the array
        A = p;
    }

    void display()
    {
        // Display all the elements of the array.
        for (int i = 0; i < length; i++)
            std::cout << A[i] << " ";
        std::cout << "\n";
    }

    void append(int val)
    {
        // To append a new value at the end of the array
        if (length >= size)
        {
            std::cerr << "Operation denied...\nInsufficient space in the array.";
            return;
        }
        A[length] = val;
        length++;
    }

    void insert(int index, int val)
    {

        if (index >= size)
        {
            std::cerr << "Operation denied...Index out of bound.\n";
            return;
        }

        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = val;
        length++;
    }

    int deleteElement(int index)
    {
        // To delete an element from the given index in the array
        int a = 0;
        if (index < 0 || index >= length)
        {
            std::cerr << "Operation denied...Index out of bound.\n";
            return 0;
        }

        a = A[index];
        for (int i = index; i < (length - 1); i++)
            A[i] = A[i + 1];
        length--;
        return a;
    }

    int get(int index)
    {
        /*
        Function to get a value from an index;

        Parameters:
            Array arr: An array under consideration
            int index: The index from which the value should be taken
        Return:
            Value from requested index.

        Coomplexities:
            Time:
                Best/Worst/Average: O(1)
            Space:
                Best/Worst/Average: O(1)
        */
        return A[index];
    }

    int set(int index, int val)
    {

        /*
        Function to replace a value at the give index be the requested replacement;

        Parameters:
            Array* arr: A pointer array under consideration
            int index: The index from which the value should be taken
        Return:
            Value from requested index.

        Coomplexities:
            Time:
                Best/Worst/Average: O(1)
            Space:
                Best/Worst/Average: O(1)
        */

        if ((index > (size-1)) || (index < 0))
            return 0;

        A[index] = val;
        return 1;
    }

    int max()
    {
        int x = 0;
        for (int i = 0; i < length; i++)
            if (A[i] > x) x = A[i];
        return x;
    }

    int min()
    {
        int x = A[0];
        for (int i = 1; i < length; i++)
            if (A[i] > x) x = A[i];
        return x;
    }

    int total()
    {
        int t = 0;
        for (int i = 0; i < length; i++)
            t += A[i];

        return t;
    }

    float average()
    {
        return (float)total() / length;
    }

    /*
    // Linear search ( Unoptimized)
    int linearSearch(Array arr, int index)
    {
        for (int i = 0; i < arr.length; i++)
            if (arr.A[i] == key) return(i); return -1;
    }
    */

    // Linear search (Optimized)
    int linearSearch(int key)
    {
        //Transposition
        for (int i = 0; i < length; i++)
        {
            if (A[i] == key)
            {
                A[i] = A[i - 1];
                A[i - 1] = key;
                return i - 1;
            }
        }
        return -1;

        // Move to one
        /*
        for (int i = 0; i < arr->length; i++)
        {
            if (arr->A[i] == key)
            {
                arr->A[i] = arr->A[0];
                arr->A[0] = key;
                return 0;
            }
        }
        */
    }

    int recursiveBinSearch(int key, int l, int h, int mid)
    {
        if (l >= h) return -1;

        if (A[mid] == key)
            return mid;

        if (A[mid] < key)
            return recursiveBinSearch(key, mid + 1, h, (mid + 1 + h) / 2);

        if (A[mid] > key)
            return recursiveBinSearch(key, l, mid - 1, (l + mid - 1) / 2);
    }

    int binarySearch(int key)
    {
        int l = 0;
        int h = length;
        int mid = 0;

        //return recursiveBinSearch(key, l, h, (l + h) / 2);

        while (l <= h)
        {
            mid = (l + h) / 2;
            if (key == A[mid]) return mid;

            if (key > A[mid])
                l = mid + 1;
            else
                h = mid - 1;
        }
        return -1;
    }

    void reverse()
    {
        for (int i = 0, j = length; (i < j); i++, j--)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    void rightShift()
    {
        for (int i = length - 2; i >= 0; i--)
            A[i + 1] = A[i];

        A[0] = 0;
    }

    void leftShift()
    {
        for (int i = 1; i < length; i++)
            A[i - 1] = A[i];
        A[length - 1] = 0;
    }

    void rotateRight()
    {
        int temp = A[length - 1];
        for (int i = length - 1; i >= 0; i--)
            A[i + 1] = A[i];

        A[0] = temp;
    }

    void rotateLeft()
    {
        int temp = A[0];
        for (int i = 1; i < length; i++)
            A[i - 1] = A[i];

        A[length - 1] = temp;
    }

    bool isSorted()
    {
        for (int i = 0; i < length - 1; i++)
            if (A[i] > A[i + 1])
                return false;
        return true;
    }

    void insertInSorted(int val)
    {
        if (isSorted())
        {
            if (length == size)
            {
                std::cerr << "Array is full... Aborting!!!\n" ;
                return;
            }

            int i = length - 1;
            while ((i > 0) && (A[i] > val))
            {
                A[i + 1] = A[i];
                i--;

            }
            A[i + 1] = val;
            length++;
        }
    }

    void rearrange()
    {
        int i = 0;
        int j = length - 1;

        while (i < j)
        {
            while (A[i] < 0) i++;
            while (A[j] > 0) j--;
            if (i<j) swap(&A[i], &A[j]);
            //display();
        }
    }

    Array* mergeSorted(Array* arr)    //  Hypothesis: Both arrays are sorted
    {
        
        Array* arr2 = new Array(size + arr->getSize());
        int i = 0, j = 0, k = 0;
        while ((i < length) && (j < arr->getLength()))
        {
            if (A[i] < arr->get(j))
                arr2->set(k++, A[i++]);
            else
                arr2->set(k++, arr->get(j++));
        }

        for (; i < length; i++)
            arr2->set(k++, A[i]);

        for (; j < arr->getLength(); j++)
            arr2->set(k++, arr->get(j));

        arr2->setLength(k);
        return arr2;
    }

    Array* unionSet(Array* arr)    //  Hypothesis: Both arrays are sorted
    {

        Array* arr2 = new Array(size + arr->getSize());
        int i = 0, j = 0, k = 0;
        while ((i < length) && (j < arr->getLength()))
        {
            if (A[i] < arr->get(j))
                arr2->set(k++, A[i++]);
            else if(A[i] == arr->get(j))
                arr2->set(k++, A[i++]), j++;
            else
                arr2->set(k++, arr->get(j++));
        }

        for (; i < length; i++)
            arr2->set(k++, A[i]);

        for (; j < arr->getLength(); j++)
            arr2->set(k++, arr->get(j));

        arr2->setLength(k);
        return arr2;
    }

    Array* intersectionSet(Array* arr)    //  Hypothesis: Both arrays are sorted
    {

        Array* arr2 = new Array(size + arr->getSize());
        int i = 0, j = 0, k = 0;
        while ((i < length) && (j < arr->getLength()))
        {
            if (A[i] < arr->get(j))
                i++;
            else if (A[i] == arr->get(j))
                arr2->set(k++, A[i++]), j++;
            else
                j++;
        }

        arr2->setLength(k);
        return arr2;
    }

    Array* differenceSet(Array* arr)    //  Hypothesis: Both arrays are sorted
    {

        Array* arr2 = new Array(size + arr->getSize());
        int i = 0, j = 0, k = 0;
        while ((i < length) && (j < arr->getLength()))
        {
            if (A[i] < arr->get(j))
                i++;
            else if (A[i] < arr->get(j))
                i++, j++;
            else
                arr2->set(k++, arr->get(j++));
        }

        for (; j < arr->getLength(); j++)
            arr2->set(k++, arr->get(j));

        arr2->setLength(k);
        return arr2;
    }

};