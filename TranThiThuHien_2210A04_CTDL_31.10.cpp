#include <bits/stdc++.h>

using namespace std;

#define MAX 50

#define TRUE 1

#define FALSE  0

#define VOCUNG 10000000

int a[MAX][MAX];
int n, m;

void Init()
{
    int i, j;
    int u, v, c;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> c;
    cout << "So dinh: " << n << endl;
    cout << "So canh: " << m << endl;
    cin >> u >> v;
    a[u][v] = a[v][u] = c;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cout << a[u][v] << " ";
        }
        cout << endl;
    }
}
int main()
{
    Init();
}
/*
void Result(void){

 cout<<"Duong di ngan nhat tu "<<(char)(s+'A'-1)<<" den "<<(char)(z + 'A' -1)<< " la"<<endl;

 cout<<(char)(z + 'A' - 1)<<"<=";//in đỉnh cuối dưới dạng char.

 int i = truoc[z];

 while (i != s){

  cout<<(char)(i +'A' -1)<<"<=";//in ra kết quả dưới dạng char.

  i = truoc[i];

 }

 cout<<(char)(s+'A' -1);//in đỉnh đầu dưới dạng char.

 cout<<endl<<"Do dai duong di la : "<< d[z];

}
void Dijkstra(void){

 int u, minp;

 //khởi tạo nhãn tạm thời cho các đỉnh.

 for (int v = 1; v <= n; v++){

  d[v] = Matrix[s][v];

  truoc[v] = s;

  chuaxet[v] = FALSE;

 }

 truoc[s] = 0;

 d[s] = 0;

 chuaxet[s] = TRUE;

 //bươc lặp

 while (!chuaxet[z]) {

  minp = VOCUNG;for (int v = 1; v <= n; v++){

   if ((!chuaxet[v]) && (minp > d[v])){

    u = v;

    minp = d[v];

   }

  }

  chuaxet[u] = TRUE;// u la dinh co nhan tam thoi nho nhat

  if (!chuaxet[z]){

   //gán nhãn lại cho các đỉnh.

   for (int v = 1; v <= n; v++){

    if ((!chuaxet[v]) && (d[u] + Matrix[u][v] < d[v])){

     d[v] = d[u] + Matrix[u][v];

     truoc[v] = u;
     }
   }
  }
 }
}*/
