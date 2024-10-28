#include <bits/stdc++.h>
using namespace std;
typedef struct SinhVien
{
    int MaSV;
    char HoTen[25];
    float DTB;
};

typedef struct Node                         //dinh nghia cau truc
{
    SinhVien info;
    Node *next;
};

typedef struct LIST                         //dinh nghia danh sach
{
    Node *Head;
    Node *Tail;
};
struct LIST Q;

void init(LIST& Q)                           //khoi tao danh sach rong
{
    Q.Head = NULL;
    Q.Tail = NULL;
}

Node *get_node (SinhVien x)                  //tao mot nut moi
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        cout << "Khong du bo nho.";
        exit(1);
    }
    p -> info.MaSV = x.MaSV;
    strcpy_s(p -> info.HoTen, x.HoTen);
    p -> info.DTB = x.DTB;
    p -> next = NULL;
    return p;
}

void InsertFirst (LIST& Q, Node *p)                 //chen phan tu vao dau ds
{
    if (Q.Head == NULL)
    {
        Q.Head = p;
        Q.Tail = Q.Head;
    }
    else
    {
        p -> next = Q.Head;
        Q.Head = p;
    }
}

void InsertLast (LIST& Q, Node *p)                  //chen phan tu vao cuoi ds
{
    if (Q.Head == NULL)
    {
        Q.Head = p;
        Q.Tail = Q.Head;
    }
    else
    {
        Q.Tail -> next = p;
        Q.Tail = p;
    }
}

void InsertAfter (LIST& Q, Node *q, Node *p)       //chen phan tu vao giua ds
{
    if (q != NULL)
    {
        p -> next = q -> next;
        q -> next = p;
        if (q == Q.Tail)
            Q.Tail = p;
    }
}

void nhap(SinhVien& s)
{
    cout << "Nhap ma sinh vien: "; cin >> s.MaSV;
    cout << "Nhap ho va ten: "; fflush(stdin); gets(s.HoTen);
    cout << "Nhap diem trung binh: "; cin >> s.DTB;
}

void nhapDS(LIST& Q)
{
    int n;
    SinhVien s;
    do
    {
        cout << "\nNhap so luong sinh vien: "; cin >> n;
        if (n <= 0)
            cout << "So luong sinh vien phai lon hon 0. Vui long nhap lai.";
    }
    while (n <= 0);
    for (int i = 1; i <= n; i++)
    {
        Node* p;
        cout << "\nNhap thong tin sinh vien thu " << i << endl;
        nhap(s);
    }
}

void xuat(SinhVien s)
{
    cout << "\n" << setw(10) << s.MaSV
                 << setw(20) << s.HoTen
                 << setw(10) << s.DTB << "\n";
}

void xuatDS(LIST Q)
{
    cout << endl << "MaSV \tHo va ten \tDiem trung binh" << endl;
    for (Node* i = Q.Head; i != NULL; i = i -> next)
        xuat(i -> info);
}

int main()
{
    Node *p;
    Node *q;
    LIST Q;
    int n;
    nhapDS(Q);
    xuatDS(Q);
    //InsertFirst(Q, p);
    //InsertLast(Q, p);
    //InsertAfter(Q, q, p);
    return 0;
}
