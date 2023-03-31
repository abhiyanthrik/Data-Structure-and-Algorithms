#pragma once
#include <iostream>
#include <limits.h> 
#include "/home/rohit/Documents/DSA/Queue/queue.h"

using namespace std;
using namespace queue;
#define I INT_MAX

int adjacency_mat[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 1, 1, 1, 0, 0, 0},
                            {0, 1, 0, 1, 0, 0, 0, 0},
                            {0, 1, 1, 0, 1, 1, 0, 0},
                            {0, 1, 0, 1, 0, 1, 0, 0},
                            {0, 0, 0, 1, 1, 0, 1, 1},
                            {0, 0, 0, 1, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0, 1, 0, 0} };

int cost_adj_mat[8][8] = { {I},
                           {I, I, 25, I, I, I, 5, I },
                           {I, 25, I, 12, I, I, I, 10 },
                           {I, 12, I, I, 8, I, I, I},
                           {I, I, I, 8, I, 16, I, 14}, 
                           {I, I, I, I, 16, I, 20, 18}, 
                           {I, 5, I, I, I, 20, I, I}, 
                           {I, I, 10, I, 14, 18, I, I}, };

int edges[3][9] = { {1, 1, 2, 2, 3, 4, 4, 5, 5},
                    {2, 6, 3, 7, 4, 5, 7, 6, 7},
                    {25, 5, 12, 10, 8, 16, 14, 20, 18} };

int t[2][6]{ 0 };

void BFS(int v)
{
    Queue<int> q;
    int i, j, visited[8]{ 0 };
    cout << v << " ";
    visited[v] = 1;
    q.enqueue(v);
    while (!q.isEmpty())
    {
        i = q.dequeue();
        for (j = 1; j < 8; j++)
        {
            if (adjacency_mat[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                q.enqueue(j);
                visited[j] = 1;
            }
        }
    }
    cout << endl;
}

void DFS(int i)
{
    static int visited[8]{ 0 };
    cout << i << " ";
    visited[i] = 1;
    for (int j = 1; j < 8; j++)
        if (adjacency_mat[i][j] == 1 && visited[j] == 0)
            DFS(j);
    if (i == 7) cout << endl;
}

void primsMinCostSpanningTree()
{
    int u, v, i, j, k, min = I;
    int near[8]{ 0 };

    for (i = 1; i < 8; i++)
        near[i] = I;

    for (i = 1; i < 8; i++)
        for (j = 1; j < 8; j++)
            if (cost_adj_mat[i][j] < min)
                u = i, v = j, min = cost_adj_mat[i][j];
    t[0][0] = u;
    t[1][0] = v;

    near[u] = near[v] = 0;

    for (i = 1; i < 8; i++)
        if(near[i] != 0)
            near[i] = cost_adj_mat[u][i] < cost_adj_mat[v][i] ? u : v;

    for (i = 1; i < 6; i++)
    {
        min = I;
        for (j = 1; j < 8; j++)
        {
            if (near[j] != 0 && cost_adj_mat[j][near[j]] < min)
            {
                min = cost_adj_mat[j][near[j]];
                k = j;
            }
        }

        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for (j = 1; j < 8; j++)
            if (near[j] != 0 && cost_adj_mat[j][k] < cost_adj_mat[j][near[j]])
                near[j] = k;
    }

    for (i = 0; i < 6; i++)
        cout << t[0][i] << " " << t[1][i] << endl;
}

int collapsingFind(int key, int set[])
{
    if (set[key] < 0) return key;
    else return set[key];
}

void weightedUnion(int h1, int h2, int set[])
{
    if (set[h1] < set[h2])
    {
        set[h1] += set[h2];
        set[h2] = h1;
    }
    else
    {
        set[h2] += set[h1];
        set[h1] = h2;
    }
}

void kruskalsMethod()
{
    int i = 0, j, min, k;
    int set[8];
    for (j = 0; j < 8; j++)
        set[j] = -1;
    int included[9]{ 0 };
    while (i < 6)
    {
        min = I;
        for (j = 0; j < 9; j++)
        {
            if (!included[j] && edges[2][j] < min)
            {
                min = edges[2][j];
                k = j;
            }
        }
        if (collapsingFind(edges[0][k], set) != collapsingFind(edges[1][k], set))
        {
            t[0][i] = edges[0][k], t[1][i] = edges[1][k];
            weightedUnion(collapsingFind(edges[0][k], set), collapsingFind(edges[1][k], set), set);
            i++;
        }
        included[k] = 1;
    }
    for (i = 0; i < 6; i++)
        cout << t[0][i] << " " << t[1][i] << endl;
}

