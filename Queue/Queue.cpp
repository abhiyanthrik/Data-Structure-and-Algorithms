#include <iostream>
#include "queue.h"
using namespace queue;

int main()
{
    int arr1[5] = { 3,5,7,2,4 };
    QueueArray<int> q1{ 10, arr1, 5 };
    q1.display();
    q1.enqueue(9);
    q1.enqueue(18);
    q1.enqueue(11);
    q1.enqueue(13);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.display();

    q1.enqueue(9);
    q1.enqueue(18);
    q1.enqueue(11);
    q1.enqueue(13);
    q1.enqueue(11);
    q1.enqueue(13);
    q1.display();
    

    float arr2[5] = { 3.5,5.3,7.9,2.0,4.13 };
    Queue<float> q2{ arr2, 5 };
    q2.display();
    q2.enqueue(6.75);
    q2.display();
    float x = q2.dequeue();
    q2.display();

    Queue<int> q3;
    q3.enqueue(5);
    q3.display();

}