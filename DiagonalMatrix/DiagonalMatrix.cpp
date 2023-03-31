// DiagonalMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Diagonal
{
private:
    int d;
    int* A;
public:
    Diagonal(int d);
    void display();
    void set(int i, int j, int val);
    int get(int i, int j);
    ~Diagonal() { delete[]A; };
};

Diagonal::Diagonal(int d)
{
    this->d = d;
    A = new int[d] {0};
}

void Diagonal::display()
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (i == j)
                cout << A[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << '\n';
    }
}

void Diagonal::set(int i, int j, int val)
{
    if (i == j)
        A[i - 1] = val;
}

int Diagonal::get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    else
        return 0;
}


int main()
{
    Diagonal d{5};
    for (int i = 1; i <= 5; i++)
        d.set(i, i, i * i);
    d.display();
    int val = d.get(4, 4);
    cout << val << "\n";
}