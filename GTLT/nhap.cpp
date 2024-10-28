/*procedure Duyệt(u)
begin
  <Dùng BFS hoặc DFS liệt kê và đánh dấu những đỉnh có thể đến được từ u>
end;

begin
  for ∀ v ∈ V do <khởi tạo v chưa đánh dấu>;
    Count := 0;
    for u := 1 to n do
      if <u chưa đánh dấu> then
      begin
        Count := Count + 1;
        WriteLn('Thành phần liên thông thứ ', Count, ' gồm các đỉnh : ');
        Duyệt(u);
      end;
end.*/
// https://youtu.be/JtWcUHRyqkA?si=AK8hXXcne52hr8X6
// ma trận kề
#include <bits/stdc++.h>
using namespace std;
/*int n, m;
int a[1001][1001];
int main()
{
    int i, j;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// Danh sach cạnh sang kề
int n, m;
vector<int> adj[1001];
//adj[i]: luu danh sach ke cua dinh
int main()
{
    int i, j, x;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for(x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}*/void dfs(int u) // Tìm kiếm theo chiều sâu từ u.
{
    for (int v: adj[u])
    {
        if (v == par[u]) // Kiểm tra v không được trùng với cha của u.
            continue;

        par[v] = u; // Đặt cha của v là u.
        dfs(v); // Tiếp tục tiến vào con của u.
    }
}

void trace(int s, int f)
{
    vector < int > path; // Lưu đường đi từ s tới f.
    while (f != 0)
    {
        path.push_back(f);
        f = trace[f];
    }

    for (int i = path.size() - 1; i >= 0; --i) // In ngược lại để thu được thứ tự từ s -> f.
        cout << path[i] << "->";
}

int main()
{
    // Nhập dữ liệu đồ thị.
    cin >> n >> m >> s >> f;

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(s); // Tìm kiếm theo chiều sâu bắt đầu từ s.

    if (trace[f] == 0) // Đỉnh f chưa được thăm thì thông báo không tìm được đường đi.
        cout << "Can't find a path from s to f";
    else
        trace(s, f); // Truy vết đường đi từ s tới f.
}
/*
#include <bits/stdc++.h>

using namespace std;

int chuaXet[max];
int a[max][max], n, m;
void nhapxuatMaTran()
{
    int i, j;
    vector<int> adj[1001];  //adj[i]: luu danh sach ke cua dinh
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for(int x :: adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

void KhoiTao_ChuaXet()
{
    for (int i = 0; i < max; i++)
        chuaXet[i] = 1;
}

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

int KT_ChuaXet()
{
    for (int i = 0; i < n; i++)
        if (chuaXet[i] == 1)
            return i;
        return -1;
}

// Dem so thanh phan lien thong
int DemSLT()
{
    int s = 0;
    KhoiTao_ChuaXet();
    while (KT_ChuaXet() != -1)
    {
        int i = KT_ChuaXet();
        DFS(i);
        s++;
    }
    cout << "\nSo lien thong: " << s;
    return s;
}

// Tim bac cac dinh
int Deg(int i)
{
    int deg = 0;
    for (int j = 0; j < n; j++)
    {
        deg += A[i][j];
    }
    return deg;
}

void duyetsau()
{
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

int main()
{
    int n, m;
    vector<int> adj[1001];
    nhapxuatMaTran();
    KhoiTao_ChuaXet();
    cout << "\nDuyet do thi DFS: "; duyetsau();
    KhoiTao_ChuaXet();
    cout << "\nDuyet do thi BFS: "; duyetrong();
    return 0;
}
*/

/*
#include <iostream>
#include <stdio.h>
#include <conio.h>

#define max 100

#define FileIn "D:\\G.txt"

using namespace std;
int chuaXet[max];

// A: ma tran ke cua G, n: so dinh
int A[max][max], n;

// doc file chua do thi G luu vao ma tran A

void Doc_File(int A[max][max], int &n)
{
  FILE *f = fopen(FileIn, "rb");
  fscanf(f, "%d", &n);
  cout << "\n So dinh: " << n << "\n Ma tran ke: " << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      fscanf(f, "%d", &A[i][j]);
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  fclose(f);
}

// Khoi tao chua xet
void KhoiTao_ChuaXet()
{
  for (int i = 0; i < max; i++)
    chuaXet[i] = 1;
}

// thuat toan DFS
void DFS(int u)
{
  // xet dinh u
  chuaXet[u] = 0;
  cout << u << "->";
  for (int v = 0; v < n; v++)
    if (chuaXet[v] == 1 && A[u][v] == 1)
    {
      DFS(v);
    }
}

// thuat toan BFS

void BFS(int u)
{
  int queue[max], dau = 0, cuoi = 0;
  for (int i = 0; i < max; i++)
    queue[i] = 0;
  queue[cuoi] = u;
  chuaXet[u] = 0;
  cout << u << "->";

  while (dau >= cuoi)
  {
    int p = queue[cuoi];
    cuoi++;
    for (int v = 0; v < n; v++)
      if (chuaXet[v] == 1 && A[p][v] == 1)
      {
        dau++;
        queue[dau] = v;
        chuaXet[v] = 0;
        cout << v << "->";
      }
  }
}

// Kiem tra chuaXet
int KT_ChuaXet()
{
  for (int i = 0; i < n; i++)
    if (chuaXet[i] == 1)
      return i;
  return -1;
}

// Dem so thanh phan lien thong

int DemSLT()
{
  int slt = 0;
  KhoiTao_ChuaXet();
  while (KT_ChuaXet() != -1)
  {
    int i = KT_ChuaXet();
    DFS(i);
    slt++;
  }
  cout << "\n So lien thong: " << slt;
  return slt;
}

// tim bac cac dinh
int Deg(int i)
{
  int deg = 0;
  for (int j = 0; j < n; j++)
  {
    deg += A[i][j];
  }
  return deg;
}

// Kiem tra do thi Euler

void Test_Euler()
{
  if (DemSLT() == 1)
  {
    // tim bac cua do thi
    int soDinhLe = 0;
    for (int i = 0; i < n; i++)
      if (Deg(i) % 2 != 0)
        soDinhLe++;
    if (soDinhLe == 0)
      cout << "\n Do thi la Euler";
    else if (soDinhLe == 2)
      cout << "\n Do thi la nua Euler";
    else
      cout << "\n Do thi khong phai Euler";
  }
  else
    cout << "\n Do thi khong la Euler";
}

// ham chinh

int main()
{
  // doc ma tran
  Doc_File(A, n);
  // Duyet do thi DFS
  KhoiTao_ChuaXet();
  cout << "\n Duyet do thi DFS: ";
  DFS(0);
  // Duyet do thi BFS
  KhoiTao_ChuaXet();
  cout << "\n Duyet do thi BFS: ";
  BFS(0);

  // Dem so lien thong
  DemSLT();

  // Kiem tra Euler
  Test_Euler();
  return 0;
}
*/
int i, j, c;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            a[u][v] = 0;
    for(i = 1; i <= m; i++)
    {
        cin >> u >> v;
        cin >> c;
        a[u][v] = c;
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
