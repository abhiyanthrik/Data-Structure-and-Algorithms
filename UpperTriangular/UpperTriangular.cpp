#include<iostream>
using namespace std;

class UpperTriangular
{
private:

	int* A;
	int d;

public:
	UpperTriangular();
	UpperTriangular(int dim);
	void display();
	void set(int i, int j, int val);
	int get(int i, int j);
	~UpperTriangular() { delete A; }
};

UpperTriangular::UpperTriangular()
{
	d = 10;
	A = new int[d * (d + 1) / 2] {0};
}

UpperTriangular::UpperTriangular(int dim)
{
	d = dim;
	A = new int[d * (d + 1) / 2] {0};
}

void UpperTriangular::display()
{
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			if (j < i) cout << 0 << " ";
			else cout << A[d * (i - 1) - ((i - 2) * (i - 1) / 2) + (j - i)] << " ";
		}
		cout << endl;
	}
}

void UpperTriangular::set(int i, int j, int val)
{
	if (i <= j)
		A[d * (i - 1) - ((i - 2) * (i - 1) / 2) + (j - i)] = val;
}

int UpperTriangular::get(int i, int j)
{
	if (i > j) return 0;
	return A[d * (i - 1) - ((i - 2) * (i - 1) / 2) + (j - i)];
}

int main()
{
	UpperTriangular ltm{ 4 };
	ltm.set(1, 1, 2);
	ltm.set(1, 2, 4);
	ltm.set(1, 3, 5);
	ltm.set(1, 4, 9);
	ltm.set(2, 2, 6);
	ltm.set(2, 3, 10);
	ltm.set(2, 4, 12);
	ltm.set(3, 3, 17);
	ltm.set(3, 4, 8);
	ltm.set(4, 4, 18);
	ltm.display();
}