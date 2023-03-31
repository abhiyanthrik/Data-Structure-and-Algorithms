#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    BFS(7);
    DFS(7);
    // primsMinCostSpanningTree();
    kruskalsMethod();

    /*int set[11] = { 0, -1, -1, -3, -4, 3, -1, 4, 4, 3, 4 };
    for (int i = 1; i < 11; i++)
        cout << i << " belongs to: " << collapsingFind(i, set) << endl;
    cout << endl;

    weightedUnion(3, 4, set);

    for (int i = 1; i < 11; i++)
        cout << i << " belongs to: " << collapsingFind(i, set) << endl;
    cout << endl;*/

}
