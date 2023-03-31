/*
This file contains the solutions to all the challenges of Array ADT series of this course.
*/
#include <iostream>
#include "array.h"
using namespace std;

// Sum of all natural numbers till n
int sumNat(int n)
{
    return (n * (n + 1)) / 2;
}

/*
Challenge 1: Find the missing value in an array of firs n natural numners.
    parameters:
            Array *arr: Pointer to array under consideration.

    Hypotheses: Only one value is missing from the list.

    Return:
            int: The missing value.
*/

int challenge1(Array* arr)
{
    int a = arr->get(arr->getLength() - 1);
    int sum = arr->total();
    int act = sumNat(a);

    return act - sum;
}

/*
Challenge 2: Find multiple missing values in an array of n continuous natural numners.

Parameters: 
        Array* arr: pointer to array under consideration.

    Returns:
        Array* missing: Pointer to an Array type object containing missing values.
*/
Array* challenge2(Array* arr)
{
    int length = arr->get(arr->getLength() - 1) - arr->get(0) + 1;
    int num_missing = length - arr->getLength();
    Array* missing = new Array(num_missing);
    int diff = arr->get(0), d = 0;
    for (int i = 1; i < arr->getLength(); i++)
    {
        d = arr->get(i) - i;
        if (d > diff)
        {
            for (int j = 1; j < (d - diff + 1); j++)
                missing->append(arr->get(i - 1) + j);

            diff = d;
        }
    }
    return missing;

}

/*
Challenge 3: Find multiple missing values in an unsorted array of n natural numners.
    Parameter:
        Array* arr : pointer to the array object under consideration.

    REturn:
        Array* missing: Pointer to an Array type object containing missing values.
*/
Array* challenge3(Array* arr)
{
    int length = arr->max();
    int num_missing = length - arr->getLength();
    bool* flags{ new bool[length] {false} };
    Array* missing = new Array(num_missing);
    int j = 0;
    for (int i = 0; i < arr->getLength(); i++)
        flags[arr->get(i) - 1] = true;

    for (int i = 0; i < length; i++)
        if (!flags[i])
            missing->append(i + 1);
    delete[]flags;
    flags = NULL;
    return missing;
}

/*
Challenge 4: Find duplicate values in an unsorted array.
    Parameter:
        Array* arr : pointer to the array object under consideration.

    REturn:
        Array* missing: Pointer to an Array type object containing duplicate values.
*/
Array* challenge4(Array* arr)
{
    int* duplicate{ new int[arr->getSize()] {0} };
    int length = 0;

    for (int i = 0; i < arr->getLength(); i++)
        for (int j = i + 1; j < arr->getLength(); j++)
            if (arr->get(i) == arr->get(j))
                duplicate[length] = arr->get(i), length++;

    Array* d{ new Array(length + 1) };
    for (int i = 0; i < length; i++)
        d->append(duplicate[i]);

    delete[] duplicate;
    duplicate = NULL;
    return d;

}

/*
Challenge 5: Find duplicate values in a sorted array.
    Parameter:
        Array* arr : pointer to the array object under consideration.

    REturn:
        Array* missing: Pointer to an Array type object containing duplicate values.
*/
Array* challenge5(Array* arr)
{
    int* duplicate{ new int[arr->getSize()] {0} };
    int* duplicate_cnt{ new int[arr->getSize()] {0} };
    int length = 0, i = 0, j = 0;
    int last_duplicate = 0;

    for (; i < arr->getLength(); i++)
        if ((arr->get(i) == arr->get(i + 1)) && arr->get(i) != last_duplicate)
        {
            j = i + 1;
            while (arr->get(i) == arr->get(j))
                duplicate_cnt[length]++, j++;

            duplicate[length] = arr->get(i);
            last_duplicate = arr->get(i);
            i = j - 1, length++;
        }

    Array* d{ new Array(length * 2) };
    for (int i = 0; i < length; i++)
        d->append(duplicate[i]), d->append(duplicate_cnt[i] + 1);

    delete[] duplicate;
    duplicate = NULL;
    return d;
}

/*
Challenge 6: Find all pairs of numbers with their sum equals k.
    Parameter:
        Array* arr : pointer to the array object under consideration.
        int x: The sum.

    REturn:
        Array* a: Pointer to an Array type object containing pairs.
        NOTE: The last value in a is the number of pairs.
*/

Array* challenge6(Array* arr, int x)
{
    int* pairs{ new int[arr->getSize() * 2] {0} };
    int i = 0, j = 0, k = 0, pair_cnt = 0;
    for (; i < arr->getLength(); i++)
        for (j = i + 1; j < arr->getLength(); j++)
            if ((arr->get(j) + (arr->get(i))) == x)
            {
                pairs[k] = arr->get(i);
                pairs[k + 1] = arr->get(j);
                pair_cnt++;
                k += 2;
            }

    Array* a{ new Array(k + 1) };
    for (int s = 0; s < k; s += 2)
    {
        a->append(pairs[s]);
        a->append(pairs[s + 1]);
    }
    a->append(pair_cnt);

    delete[] pairs;
    pairs = NULL;
    return a;

}

Array* challenge6a(Array* arr, int x)
{
    //arr->display();
    int* pairs{ new int[arr->getSize()] {0} };
    bool* flag_table{ new bool[arr->max() + 1] {0} };
    int i = 0, r = 0, k = 0, pair_cnt = 0;
    for (; i < arr->getLength(); i++)
    {
        flag_table[arr->get(i)] = true;
        r = x - arr->get(i);
        if (r > 0)
        {
            if (flag_table[r])
            {
                pairs[k] = arr->get(i);
                pairs[k + 1] = r;
                k += 2, pair_cnt++;
            }
        }
    }

    Array* a{ new Array(k + 1) };
    for (int s = 0; s < k; s += 2)
    {
        a->append(pairs[s]);
        a->append(pairs[s + 1]);
    }
    a->append(pair_cnt);

    delete[] pairs;
    delete[] flag_table;
    pairs = NULL;
    flag_table = NULL;
    return a;

}

Array* challenge6b(Array* arr, int x)
{
    //arr->display();
    int* pairs{ new int[arr->getSize()] {0} };
    bool* flag_table{ new bool[arr->max() + 1] {0} };
    int i = 0, j = arr->getLength() - 1, k = 0, pair_cnt = 0;
    while (i < j)
    {
        if (arr->get(i) + arr->get(j) == x)
        {
            pairs[k] = arr->get(i);
            pairs[k + 1] = arr->get(j);
            pair_cnt++;
            k += 2, i++, j--;
        }
        else if (arr->get(i) + arr->get(j) > x) j--;
        else i++;
    }

    Array* a{ new Array(k + 1) };
    for (int s = 0; s < k; s += 2)
    {
        a->append(pairs[s]);
        a->append(pairs[s + 1]);
    }
    a->append(pair_cnt);

    delete[] pairs;
    delete[] flag_table;
    pairs = NULL;
    flag_table = NULL;
    return a;

}


/*
Challenge 7: Find all pairs of numbers with their sum equals k.
    Parameters:
        Array* arr: Pointer to Array type object under consideration.
    Return:
        int* v: Pointer to the array containing both min and max values.
*/
int* challenge7(Array* arr)
{
    int* v{ new int[2] };
    v[0] = v[1] = arr->get(0);
    for (int i = 1; i < arr->getLength(); i++)
    {
        if (arr->get(i) < v[0])
            v[0] = arr->get(i);
        else if (arr->get(i) > v[1])
            v[1] = arr->get(i);
    }
    return v;
}

void challenges()
{
    Array arr{ 20 };
    for (int i = 0; i < 10; i++)
        arr.append(i + 1);
    arr.deleteElement(4);
    cout << challenge1(&arr) << " is missing from the array.\n\n";

    int a[] = { 6,7,8,9,11,12,13,15,16,20 };
    Array* arr2 = new Array(sizeof(a) / sizeof(a[0]));
    cout << "The array is:\n";
    for (int i : a)
        arr2->append(i);
    arr2->display();

    Array* arr3 = challenge2(arr2);
    cout << "Missing values from the array:\n";
    arr3->display();

    Array* arr4 = challenge3(arr2);
    cout << "Missing values from the array:\n";
    arr4->display();

    int b[] = { 6,7,6,9,11,12,9,15,7,20 };
    Array* arr5 = new Array(sizeof(b) / sizeof(b[0]));
    cout << "The array is:\n";
    for (int i : b)
        arr5->append(i);

    Array* arr6 = challenge4(arr5);
    cout << "Values in the array which has duplicates are:\n";
    arr6->display();


    int c[] = { 6,7,7,9,9,9,9,11,12,15,15,20 };
    Array* arr7 = new Array(sizeof(c) / sizeof(c[0]));
    cout << "The array is:\n";
    for (int i : c)
        arr7->append(i);

    Array* arr8 = challenge5(arr7);
    cout << "Values in the array which has duplicates are:\n";
    cout << "VALUE\tREPETITION\n";
    for (int i = 0; i < arr8->getLength(); i += 2)
    {
        cout << arr8->get(i) << '\t' << arr8->get(i + 1) << endl;
    }

    int d[] = { 2,4,5,6,7,8,9,11,20 };
    Array* arr9 = new Array(sizeof(d) / sizeof(d[0]));
    for (int i : d)
        arr9->append(i);

    Array* arr10 = challenge6(arr9, 13);
    cout << "Total numbers of pairs: " << arr10->get(arr10->getLength() - 1);
    cout << "\nThe pairs:\n";
    cout << "A\tB\n";
    for (int i = 0; i < arr10->getLength() - 1; i += 2)
    {
        cout << arr10->get(i) << '\t' << arr10->get(i + 1) << endl;
    }

    Array* arr11 = challenge6b(arr9, 13);
    cout << "Using method2:\n"; \
        cout << "A\tB\n";
    for (int i = 0; i < arr11->getLength() - 1; i += 2)
    {
        cout << arr11->get(i) << '\t' << arr11->get(i + 1) << endl;
    }

    int* min_max = challenge7(arr9);
    cout << "min: " << min_max[0] << ", max: " << min_max[1] << endl;
}

