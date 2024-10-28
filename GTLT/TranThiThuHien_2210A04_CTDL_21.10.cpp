#include <iostream>
#include <stdio.h>
#include <conio.h>
#define max 100
using namespace std;
int unvisited[max];
int A[1001][1001], n, m;
//adj[i]: luu danh sach ke cua dinh
void maTran()
{
    int i, j;
    cout << "Nhap so dinh: "; cin >> n;
    cout << "Nhap so canh: "; cin >> m;
    for(i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        A[x][y] = A[y][x] = 1;
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
void KhoiTao_Unvisited()
{
    for (int i = 0; i < max; i++)
        unvisited[i] = 1;
}
void DFS(int u)
{
   unvisited[u] = 0;
    cout << u << "->";
    for (int v = 0; v < n; v++)
        if (unvisited[v] == 1 && A[u][v] == 1)
        {
            DFS(v);
        }
}
void BFS(int u)
{
    int queue[max], dau = 0, cuoi = 0;
    for (int i = 0; i < max; i++)
        queue[i] = 0;
        queue[cuoi] = u;
        unvisited[u] = 0;
        cout << u << "->";
    while (dau >= cuoi)
    {
        int p = queue[cuoi];
        cuoi++;
        for (int v = 0; v < n; v++)
            if (unvisited[v] == 1 && A[p][v] == 1)
            {
                dau++;
                queue[dau] = v;
                unvisited[v] = 0;
                cout << v << "->";
            }
    }
}
int KT_unvisited()
{
    for (int i = 0; i < n; i++)
        if (unvisited[i] == 1)
            return i;
        return -1;
}
/*
void dfs(vertex v)
{
    vertex w;
    mark[v - 1] = visited;
    for(w = 1; w <= v; w++)
    {
        if(mark[w - 1] == unvisited)
            dfs(w);
    }
}
void bfs(vertex v)
{
    Queue of vertex Q;
    vertex x, y;
    mark[v - 1] = visited;
    Insert(v, Q);
    while!(Empty_queue(Q))
    {
        Remove(x, Q);
        for(y = 1; y <= x; y++)
            if(mark[y - 1] == unvisited)
            {
                mark[y - 1] = visited;
                Insert(y, Q);
            }
}
void duyetsau()
{
    int v;
    for(v = 1; v <= n; v++)
    {
        mark[v - 1] = unvisited;
        for(v = 1; v <= n; v++)
        {
            if(mark[v - 1] == unvisited)
                dfs(v);
        }
    }
}
void duyetrong()
{
    int v;
    for(v = 1; v <= n; v++)
    {
        mark[v - 1] = unvisited;
        for(v = 1; v <= n; v++)
        {
            if(mark[v - 1] == unvisited)
                bfs(v);
        }
    }
}*/
int main()
{
    maTran();
    KhoiTao_Unvisited();
    cout << "\n Duyet do thi DFS: ";
    DFS(0);
    KhoiTao_Unvisited();
    cout << "\n Duyet do thi BFS: ";
    BFS(0);
    return 0;
}

// Tai lieu tham khao: https://expressmagazine.net/development/4506/cai-dat-thuat-toan-duyet-do-thi-lien-thong-bang-dfs-bfs-euler-khong
