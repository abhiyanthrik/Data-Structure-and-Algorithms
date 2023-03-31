#include <iostream>
#include "stack.h"
using namespace stack;
using namespace std;

int main()
{
    int arr[5] = { 3,8,9,2,4 };
    LinkedStack<int> stack{arr, 5};
    stack.display();
    cout << "poped element is: " << stack.pop() << endl;
    stack.display();
    stack.push(7);
    stack.display();
    cout << "First element in stack is: " << stack.stackTop() << endl;
    cout << "3rd element in stack is: " << stack.peap(3) << endl;
    // for(int i = 0; i<5; i++) stack.pop();
    stack.isFull() ? cout << "Stack is full.\n" : cout << "stack is not full.\n";

    Stack<int> s{ arr, 6, 5 };
    s.display();
    cout << "poped element is: " << s.pop() << endl;
    s.display();
    s.push(7);
    s.display();
    cout << "First element in stack is: " << s.stackTop() << endl;
    cout << "3rd element in stack is: " << s.peap(3) << endl;
    for(int i = 0; i<6; i++) s.pop();
    s.isEmpty() ? cout << "Stack is empty.\n" : cout << "stack is not empty.\n";
}
