#include <iostream>
using namespace std;
struct Element  // To store val at i,j location in matrix
{
    int i, j, val;
};

class Sparse
{
private:
    int n, m, num;  // Dimensions of the matrix
    Element* p; // Pointer to array of structures containing all the elements
public:
    Sparse(int n, int m, int num)
    {
        this->n = n, this->m = m, this->num = num;
        p = new Element[this->num];
    }

    ~Sparse()
    {
        delete p;
    }
    
    Sparse operator+(Sparse& s);
    friend istream & operator>>(istream& is, Sparse& s);
    friend ostream& operator<<(ostream& os, Sparse& s);
    
};

Sparse Sparse::operator+(Sparse& s) 
{
    if ((n != s.n) || (m != s.m))
        return Sparse(0, 0, 0);
    int i, j, k;
    i = j = k = 0;
    Sparse* sum = new Sparse{ n,m,this->num + s.num };

    while ((i < this->num) && (j < s.num))
    {
        if (p[i].i < s.p[j].i)
            sum->p[k++] = p[i++];
        else if (s.p[j].i < p[i].i)
            sum->p[k++] = s.p[j++];
        else
        {
            if (p[i].j < s.p[j].j)
                sum->p[k++] = p[i++];
            else if (s.p[j].j < p[i].j)
                sum->p[k++] = s.p[j++];
            else
            {
                sum->p[k] = p[i];
                sum->p[k++].val = p[i++].val + s.p[j++].val;
            }
        }
    }
    for (; i < num; i++) sum->p[k++] = p[i];
    for (; j < s.num; j++) sum->p[k++] = s.p[j];
    sum->num = k;
    return *sum;
}

istream & operator>>(istream& is, Sparse& s) 
{
    std::cout << "Enter address and corresponding non zero values in order (i,j,val):\n";
    for (int i = 0; i < s.num; i++)
        std::cin >> s.p[i].i >> s.p[i].j >> s.p[i].val;
    return is;
}

ostream& operator<<(ostream& os, Sparse& s)
{
    int k = 0;
    for (int i = 0; i < s.n; i++)
    {
        for (int j = 0; j < s.m; j++)
        {
            if (i == s.p[k].i && j == s.p[k].j)
                std::cout << s.p[k++].val << " ";
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
    return os;
}


int main()
{
    Sparse s1{ 5,5,5 };
    Sparse s2{ 5,5,5 };

    std::cin >> s1 >> s2;

    Sparse s3 = s1 + s2;

    std::cout << s3;
}