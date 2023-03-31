#include<iostream>
using namespace std;

class LowerTriangular 
{
private:

	int* A;
	int d;

public:
	LowerTriangular();
	LowerTriangular(int dim);
	void display();
	void set(int i, int j, int val);
	int get(int i, int j);
	~LowerTriangular() { delete A; }
};

LowerTriangular::LowerTriangular()
{
	d = 10;
	A = new int[d * (d + 1) / 2] {0};
}

LowerTriangular::LowerTriangular(int dim)
{
	d = dim;
	A = new int[d * (d + 1) / 2] {0};
}

void LowerTriangular::display()
{
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			if (j > i) cout << 0 << " ";
			else cout << A[(i * (i - 1) / 2) + (j - 1)] << " ";
		}
		cout << endl;
	}
}

void LowerTriangular::set(int i, int j, int val)
{
	if (i >= j)
		A[(i * (i - 1) / 2) + (j - 1)] = val;
}

int LowerTriangular::get(int i, int j)
{
	if (i < j) return 0;
	return A[(i * (i - 1) / 2) + (j - 1)];
}

int main()
{
	LowerTriangular ltm{ 4 };
	ltm.set(1, 1, 2);
	ltm.set(2,1,4);
	ltm.set(2,2,5);
	ltm.set(3,1,9);
	ltm.set(3,2,6);
	ltm.set(3,3,10);
	ltm.set(4,1,12);
	ltm.set(4,2,17);
	ltm.set(4,3,8);
	ltm.set(4,4,18);
	ltm.display();
}