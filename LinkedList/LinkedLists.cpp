#include <iostream>
#include "linkedlist.h"
using namespace std;

/*
struct Node
{
    int data;
    Node* next;
} *first;

void display(Node* list)
{
    while (list)
        cout << list->data << " ", list = list->next;
    cout << endl;
}
Node* create(int* A, int n)
{
    Node* p = new Node;
    p->data = A[0];
    p->next = NULL;
    Node* q = p, *temp;
    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        q->next = temp;
        q = temp;
    }
    return p;
}

int len(Node* p)
{
    int c = 0;
    while (p)
    {
        p = p->next;
        c += 1;
    }
    return c;
}

int sum(Node* p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int max(Node* p)
{
    int max = 0;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
        
    }
    return max;
}

int min(Node* p)
{
    int min = p->data;
    while (p)
    {
        if (p->data < min)
            min = p->data;
        p = p->next;

    }
    return min;
}

Node* search(Node* p, int key)
{
    int temp;
    Node* q, *last;
    q = last = p;
    while (q)
    {
        if (q->data == key)
        {
            last->next = q->next;
            q->next = p;
            first = q;
            return q;
        }
        last = q;
        q = q->next;
    }
    return NULL;
}

void insert(int index, int value)
{
    if (index < 0 || index > len(first))
        return;
    Node* t = new Node;
    t->data = value;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }

    else
    {
        Node* p = first;
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void insertSorted(int value)
{
    Node* temp = new Node;
    temp->data = value;

    if (!first)
        first = temp;

    else if (value < first->data)
    {
        temp->next = first;
        first = temp;
    }
    else
    {
        Node* p = first;
        while (p)
        {
            if (value < p->next->data)
            {
                temp->next = p->next;
                p->next = temp;
                return;
            }
            p = p->next;
        }
    }
}

int delet(int index)
{
    if (index < 0 || index > len(first))
    {
        cerr << "Invalid index!!!\n";
        return 0;
    }
    
    Node* p = first, * q = NULL;
    int x = 0;
    if (index == 0)
    {
        first = first->next;
    }

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

bool isSorted()
{
    if (!first)
    {
        cerr << "List is empty!!!";
        return false;
    }

    Node* p = first;
    while (p->next)
    {
        if (p->data > p->next->data)
            return false;
        p = p->next;
    }
    return true;
}

void removeDuplicates(Node* f)
{
    Node* p = f, * q = NULL;
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

void reverseLink(Node* p)
{
    Node* q = NULL, * r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverseLink(Node* p, Node* q)
{
    if (p)
    {
        reverseLink(p->next, p);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

Node* concate(Node* p, Node* q)
{
    Node* r = p;
    while (p->next)
        p = p->next;
    p->next = q;
    return r;
}

Node* merge(Node* p, Node* q)
{
    Node* r = NULL, * t = NULL;
    if (p->data <= q->data)
    {
        r = t = p;
        p = p->next;
        r->next = NULL;
    }

    else
    {
        r = t = q;
        q = q->next;
        r->next = NULL;
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
    else t->next = q;
    return r;
}

bool isLoop(Node* p)
{
    Node* q, * r;
    q = r = p;
    
    do
    {
        q = q->next;
        r = r->next;
        r = r ? r->next : r;

    } while (p && q && p!=q);
    if (p == q) return true;
    return false;
}
 

int main()
{
    std::cout << "This is starting of Linked list data structure...\n";

    int A[5] = { 2,4,6,8,14 };
    first = create(A, 5);
    display(first);
    cout << "Len of linked-list is: " << len(first) << endl;
    cout << "Sum of elements of linked list is: " << sum(first) << endl;
    cout << "Maximum value in linked list is: " << max(first) << endl;
    cout << "Mininmum value in list is: " << min(first) << endl;
    //Node* ind = search(first, 6);
    //cout << "Address of the key is: " <<  ind << endl;
    //cout << ind->data << endl;
    display(first);
    //insert(0, 2);
    //display(first);
    insert(4, 11);
    display(first);
    insertSorted(10);
    display(first);
    delet(51);
    display(first);
    isSorted() ? cout << "List is sorted.\n" : cout << "Not sorted.\n";
    int B[6] = { 1,3,5,7,10,12 };
    Node* list = create(B, 6);
    display(list);
    removeDuplicates(list);
    display(list);
    display(first);
    reverseLink(first,NULL);
    display(first);
    int l1[5] = { 3,6,8,10,14 };
    Node* link1 = create(l1, 5);
    int l2[5] = { 2,5,7,12,20 };
    Node* link2 = create(l2, 5);
    Node* mer = merge(link1, link2);
    display(mer);
}
*/

int main()
{
    cout << "This is the start of linked list section...\n";
    int A[8] = { 2,4,4,6,6,8,8,14 };
    LinkedList l{ A,8 };
    l.display();

    cout << "length of the linked list is: " << l.len() << '\n';
    cout << "Max element in list is: " << l.max() << endl;
    cout << "Minimum element in the list is: " << l.min() << endl;
    cout << "Sum of all the elements in the list is: " << l.sum() << endl;
    int key = 4;
    //l.search(key) ? cout << key << " exist in list.\n" : cout << key << " doesn't exist.\n";
    l.display();
    l.insert(2, 5);
    l.display();
    l.insertSorted(10);
    l.display();
    l.remove(2);
    l.display();
    l.isSorted() ? cout << "List is sorted.\n" : cout << "List isn't sorted.\n";
    l.isLoop() ? cout << "List is looping.\n" : cout << "List isn't looping.\n";
    l.removeDupes();
    l.display();
    l.reverseList();
    l.display();
    l.reverseList();
    l.display();
    int B[8] = { 16,24,34,36,46,48,50,54 };
    LinkedList l2{ B,8 };
    l2.display();
    l.concate(l2);
    l.display();
    int C[4] = { 1,7,11,16 };
    LinkedList l3{ C,4 };
    l.merge(l3);
    l.display();
    int D[5] = { 20,27,33,36,41 };
    Circular l4(D, 5);
    cout << "Length of list is: " << l4.len() << endl;
    l4.display();
    cout << "33 is located at: " << l4.search(33) << endl;
    l4.insert(0, 18);
    l4.insert(3, 30);
    l4.display();
    cout << "Length of list is: " << l4.len() << endl;
    int a = l4.remove(5);
    l4.display();
    cout << "removed element is: " << a << endl;
    l4.reverse();
    l4.display();

    DoublyCircular l5{ D, 5 };
    l5.display();

    cout <<"Length of the list is: " << l5.len() << endl;
    cout << "33 is located at: " << l5.search(33) << endl;
    l5.insert(0, 18);
    l5.display();
    l5.insert(2, 30);
    l5.display();
    int v = l5.remove(0);
    cout << "Removed value is: " << v << endl;
    l5.display();
    l5.reverse();
    l5.display();
}