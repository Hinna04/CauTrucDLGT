#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1001];
//adj[i]: luu danh sach ke cua dinh
void maTran()
{
    int i, j;
    cout << "Nhap so dinh: "; cin >> n;
    cout << "\nNhap so canh: "; cin >> m;
    for(i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for(int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
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
}
*/
int main()
{
    maTran();
    //cout << "\nDuyet do thi DFS: "; duyetsau();
    //cout << "\nDuyet do thi BFS: "; duyetrong();
    return 0;
}
