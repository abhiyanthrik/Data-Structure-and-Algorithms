#pragma once
#include<iostream>

namespace queue
{
	template <class T>
	class QueueArray
	{
	private:
		int front;
		int rear;
		int size;
		T* Q;
	public:
		QueueArray();
		QueueArray(int size);
		QueueArray(int size, T* arr, int n);
		~QueueArray() { delete[]Q; }
		void enqueue(T val);
		T dequeue();
		void display();
		bool isEmpty();
		bool isFull();
	};

	template<class T>
	QueueArray<T>::QueueArray()
	{
		front = rear = size = 0;
		Q = NULL;
	}

	template<class T>
	QueueArray<T>::QueueArray(int size)
	{
		this->size = size;
		front = rear = 0;
		Q = new T[size]{ 0 };
	}

	template<class T>
	QueueArray<T>::QueueArray(int size, T* arr, int n)
	{
		if (n > size)
		{
			std::cout << "More values than size!!!\nCan't create array...\n";
			return;
		}
		this->size = size;
		front = rear = 0;
		Q = new T[size]{ 0 };
		while (rear < n)
		{
			rear++;
			Q[rear] = arr[rear - 1];
		}
	}

	template<class T>
	void QueueArray<T>::display()
	{
		int i = front;
		while (i != rear)
		{
			i = (i + 1) % size;
			std::cout << Q[i] << " ";
		}
		std::cout << std::endl;
	}

	template<class T>
	bool QueueArray<T>::isFull()
	{
		if (((rear + 1) % size) == front) return true;
		return false;
	}

	template<class T>
	bool QueueArray<T>::isEmpty()
	{
		if (rear == front) return true;
		return false;
	}

	template<class T>
	void QueueArray<T>::enqueue(T val)
	{
		if (isFull())
		{
			std::cout << "Queue is full!!!\n";
			return;
		}
		rear = (rear + 1) % size;
		Q[rear] = val;
	}

	template<class T>
	T QueueArray<T>::dequeue()
	{
		T x = T();
		if (isEmpty()) return x;
		front = (front + 1) % size;
		x = Q[front];
		Q[front] = 0;
		return x;
	}

	template <class S>
	struct Node
	{
		S data;
		Node* next;
	};

	template <class S>
	class Queue
	{
	private:
		Node<S>* front;
		Node<S>* rear;
	public:
		Queue() { front = rear = NULL; }
		Queue(S* arr, int n);
		~Queue();
		bool isEmpty();
		bool isFull();
		void display();
		void enqueue(S val);
		S dequeue();
	};

	template <class S>
	Queue<S>::Queue(S* arr, int n)
	{
		Node<S>* p = new Node<S>;
		p->data = arr[0];
		p->next = NULL;
		front = rear = p;
		p = NULL;
		for (int i = 1; i < n; i++)
		{
			p = new Node<S>;
			p->data = arr[i];
			p->next = NULL;
			rear->next = p;
			rear = p;
			p = NULL;
		}

	}

	template <class S>
	Queue<S>::~Queue()
	{
		Node<S>* p = front, * q = NULL;
		while (p)
		{
			q = p;
			p = p->next;
			delete q;
			q = NULL;
		}
	}

	template <class S>
	bool Queue<S>::isEmpty()
	{
		return !front; // if front is NULL queue is empty else not.
	}

	template <class S>
	bool Queue<S>::isFull()
	{
		bool x = false;
		Node<S>* p = new Node<S>;
		x = p;
		if (x)
		{
			delete p;
			return !x;
		}

		return !x;
	}

	template <class S>
	void Queue<S>::display()
	{
		Node<S>* p = front;
		while (p)
		{
			std::cout << p->data << " ";
			p = p->next;
		}
		std::cout << std::endl;
	}

	template <class S>
	void Queue<S>::enqueue(S val)
	{
		if (isFull()) return;
		Node<S>* p = new Node<S>;
		p->data = val;
		p->next = NULL;
		if (!front)
		{
			rear = front = p;
			return;
		}
		rear->next = p;
		rear = p;
		p = NULL;
	}

	template <class S>
	S Queue<S>::dequeue()
	{
		S x = S();
		if (isEmpty()) return x;
		Node<S>* p = front;
		x = p->data;
		front = front->next;
		delete p;
		p = NULL;
		return x;
	}
}
