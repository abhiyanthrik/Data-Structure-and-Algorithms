#pragma once
#include<iostream>

namespace stack
{
	template <class T>
	class Stack
	{
	private:
		int size;
		int top;
		T* S;
	public:
		Stack();
		Stack(T* arr, int size, int n);
		~Stack() { delete[]S; }
		void display();
		T pop();
		void push(T val);
		T stackTop();
		T peap(int index);
		bool isEmpty();
		bool isFull();

	};

	template <class T>
	Stack<T>::Stack()
	{
		size = 0;
		top = -1;
		S = NULL;
	}

	template <class T>
	Stack<T>::Stack(T* arr, int size, int n)
	{
		this->size = size;
		top = -1;
		S = new T[size]{ 0 };

		for (int i = 0; i < n; i++)
		{
			top++;
			S[i] = arr[i];
		}
	}

	template <class T>
	void Stack<T>::display()
	{
		for (int i = top; i > -1; i--)
			std::cout << S[i] << " ";
		std::cout << std::endl;
	}

	template <class T>
	T Stack<T>::pop()
	{
		if (top < 0) return T();
		T x = S[top];
		S[top] = 0;
		top--;
		return x;
	}

	template <class T>
	void Stack<T>::push(T val)
	{
		if (top == size - 1)
		{
			std::cout << "Stack Overflow!!!\n";
			return;
		}

		top++;
		S[top] = val;
	}

	template <class T>
	T Stack<T>::stackTop()
	{
		if (size == 0) return T();
		return S[top];
	}

	template <class T>
	T Stack<T>::peap(int index)
	{
		if (index < 0 || index > size - 1) return -1;
		if (top == -1) return T();
		return(S[top - index]);
	}

	template <class T>
	bool Stack<T>::isEmpty()
	{
		if (top >= 0) return false;
		return true;
	}

	template <class T>
	bool Stack<T>::isFull()
	{
		if (top < size - 1) return false;
		return true;
	}

	template <class S>
	struct Block
	{
		S top;
		Block<S>* next;
	};

	template <class S>
	class LinkedStack
	{
	private:
		Block<S>* block;
		int size;
	public:
		LinkedStack() { block = NULL; int size = 0; }
		LinkedStack(S* arr, int size);
		~LinkedStack();
		void display();
		S pop();
		void push(S val);
		S stackTop();
		S peap(int index);
		bool isEmpty();
		bool isFull();
	};

	template <class S>
	LinkedStack<S>::LinkedStack(S* arr, int size)
	{
		this->size = 0;
		block = new Block<S>;
		block->top = arr[0];
		block->next = NULL;
		this->size++;
		Block<S>* p = block, * q = NULL;
		for (int i = 1; i < size; i++)
		{
			this->size++;
			q = new Block<S>;
			q->top = arr[i];
			q->next = NULL;
			p->next = q;
			p = q;
		}
	}

	template <class S>
	LinkedStack<S>::~LinkedStack()
	{
		Block<S>* p = block, * q = NULL;
		while (p)
		{
			q = p;
			p = p->next;
			delete q;
			q = NULL;
		}
	}

	template <class S>
	void LinkedStack<S>::display()
	{
		Block<S>* p = block;
		while (p)
		{
			std::cout << p->top << " ";
			p = p->next;
		}
		std::cout << std::endl;
	}

	template <class S>
	S LinkedStack<S>::pop()
	{
		if (!block) return S();
		Block<S>* p = block;
		S x = S();
		x = block->top;
		block = block->next;
		delete p;
		p = NULL;
		return x;
	}

	template <class S>
	void LinkedStack<S>::push(S val)
	{
		Block<S>* p = new Block<S>;
		p->top = val;
		p->next = block;
		block = p;
		p = NULL;
		size++;
	}

	template <class S>
	S LinkedStack<S>::stackTop()
	{
		if (!block) return S();
		return block->top;
	}

	template <class S>
	S LinkedStack<S>::peap(int index)
	{
		if (index < 0 || index > size) return S();
		Block<S>* p = block;
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		return p->top;
	}

	template <class S>
	bool LinkedStack<S>::isEmpty()
	{
		return !block;
	}

	template <class S>
	bool LinkedStack<S>::isFull()
	{
		Block<S>* p = new Block<S>;
		return !p;
	}
}
