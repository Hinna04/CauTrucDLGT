#include <bits/stdc++.h>

using namespace std;

struct SinhVien
{
    char MaSV[12];
    char HoTen[25];
    char Lop[7];
    float diemLT, diemTH, diemThi, diemTB;
};

struct Node
{
    SinhVien info;
    struct Node *next;
};

struct List
{
    Node *Head;
    Node *Tail;
};

void init(List &Q)
{
    Q.Head = NULL;
    Q.Tail = NULL;
}

Node *get_node(SinhVien x)
{
    Node *p;
    p = new Node;
    if (p==NULL)
    {
        cout << "Khong du bo nho.";
        exit(1);
    }
    p->info = x;
    p->next = NULL;
    return p;
}

void InsertFirst (List& Q, Node *p)
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

void InsertLast(List &Q, Node *p)
{
    if (Q.Head == NULL)
    {
        Q.Head = p;
        Q.Tail = Q.Head;
    }
    else
    {
        Q.Tail->next = p;
        Q.Tail = p;
    }
}

void InsertAfter(List &Q, Node *q, Node *p)
{
    if (q != NULL)
    {
        p -> next = q -> next;
        q -> next = p;
        if (q == Q.Tail)
            Q.Tail = p;
    }
}

void nhapDS(List &Q)
{
    Node *p;
    SinhVien x;
	int n,i;
	cout << "\n Nhap so luong sinh vien: "; cin >> n;
	for(i = 0; i < n; i++)
	{
		cout << "\n Sinh vien thu " << i+1;
		cout << "\n Nhap ma sinh vien: "; cin >> x.MaSV; cin.ignore();
        cout << " Nhap ho va ten: "; cin.ignore(); gets(x.HoTen);
        cout << " Nhap ten lop: "; cin >> x.Lop; cin.ignore();
        cout << " Nhap diem ly thuyet: "; cin >> x.diemLT;
        cout << " Nhap diem thuc hanh: "; cin >> x.diemTH;
        cout << " Nhap diem thi: "; cin >> x.diemThi;
        x.diemTB = x.diemLT*0.1 + x.diemTH*0.2 + x.diemThi*0.7;
	}
	p = get_node(x);
    InsertLast(Q, p);
}

void xuatDS(List Q)
{
    Node *p;
    cout << setw(6)  << "\n MaSV "
         << setw(20) << " Ho ten"
         << setw(14) << " Lop "
         << setw(13) << " Diem LT "
         << setw(12) << " Diem TH "
         << setw(12) << " Diem thi"
         << setw(13) << " Diem TB " << "\n";
    for(p = Q.Head; p!= NULL; p = p->next)
    {
        cout << "\n" << setw(6)  << p->info.MaSV
             << setw(20) << p->info.HoTen
             << setw(10) << p->info.Lop
             << setw(7)  << p->info.diemLT
             << setw(12) << p->info.diemTH
             << setw(12) << p->info.diemThi
             << setw(14) << p->info.diemTB << "\n";
    }
}

//them 1 sv va chen vao dau ds
void chenSV(List &Q)
{
    SinhVien x;
    cout << "\n Nhap thong tin sinh vien";
    cout << "\n Nhap ma sinh vien: "; cin >> x.MaSV; cin.ignore();
    cout << " Nhap ho va ten: "; gets(x.HoTen);
    cout << " Nhap ten lop: "; cin >> x.Lop; cin.ignore();
    cout << " Nhap diem ly thuyet: "; cin >> x.diemLT;
    cout << " Nhap diem thuc hanh: "; cin >> x.diemTH;
    cout << " Nhap diem thi: "; cin >> x.diemThi;
    x.diemTB = x.diemLT*0.1 + x.diemTH*0.2 + x.diemThi*0.7;
    Node *p;
    p = get_node(x);
    InsertFirst(Q, p);
    cout<<"\n\t DANH SACH SINH VIEN SAU KHI THEM\n";
    xuatDS(Q);
}

Node *Searchk(List Q, SinhVien k, Node *&q)
{
    Node *p ;
    q = NULL;
    p = Q.Head;
    while((p != NULL) && (p->info.MaSV != k.MaSV))
    {
        q = p;
        p = p->next;
    }
    return p;
}
/*
Node *Search(List Q, string s, Node *&q){
	Node *p = Q.Head;
	q = NULL;
	while((p != NULL) && (p->info.MaSV != s))
    {
		q = p;
		p = p->next;
	}
	return p;
}
*/
void them1SVSaux(List Q, SinhVien k)
{
    Node *q ;
    Node *p;
    SinhVien x;
    q = Searchk(Q, k, q);
    if(q == NULL)
    {
        cout<<"Khong thay X ";
    }
    p = q->next;
    if(p != NULL)
    {
        if(p == Q.Tail)
        {
            cout << "\n Nhap ma sinh vien: "; cin >> x.MaSV; cin.ignore();
        cout << " Nhap ho va ten: "; gets(x.HoTen);
        cout << " Nhap ten lop: "; cin >> x.Lop; cin.ignore();
        cout << " Nhap diem ly thuyet: "; cin >> x.diemLT;
        cout << " Nhap diem thuc hanh: "; cin >> x.diemTH;
        cout << " Nhap diem thi: "; cin >> x.diemThi;
        x.diemTB = x.diemLT*0.1 + x.diemTH*0.2 + x.diemThi*0.7;
            InsertLast(Q, p);
        }
        else
        {
            cout << "\n Nhap ma sinh vien: "; cin >> x.MaSV; cin.ignore();
        cout << " Nhap ho va ten: "; gets(x.HoTen);
        cout << " Nhap ten lop: "; cin >> x.Lop; cin.ignore();
        cout << " Nhap diem ly thuyet: "; cin >> x.diemLT;
        cout << " Nhap diem thuc hanh: "; cin >> x.diemTH;
        cout << " Nhap diem thi: "; cin >> x.diemThi;
        x.diemTB = x.diemLT*0.1 + x.diemTH*0.2 + x.diemThi*0.7;
            InsertAfter(Q, q, p);
        }
    }
}
// xoa cac sinh vien co diemTB < 3.5
void xoa(List &Q)
{
	SinhVien x;
	Node *p;
    for(p = Q.Head; p != NULL; p = p->next)
    {
        if(p->info.diemTB < 3.5)
            delete p;
    }
   xuatDS(Q);
}

//sap xep theo thu tu tang dan cua diem tb
void sapXep(List Q)
{
	Node *q,*p;
	SinhVien x;
	p = Q.Head;
	while(p != NULL)
	{
        q = p->next;
		while(q != NULL)
		{
			if(p->info.diemTB > q->info.diemTB)
            {
				x = p->info;
				p->info = q->info;
				q->info = x;
		    }
		    q = q->next;
		}
		p = p->next;
	}
	xuatDS(Q);
}

void sapXepChon(List Q)
{
    Node *i, *j;
    Node *p = Q.Head;
    int tg;
    for(i = Q.Head; i != NULL; i = i->next)
    {
        Node *minNode = i;
        for(j = i->next; j != NULL; j = j->next)
        {
            if(minNode->info.diemTB > j->info.diemTB)
                minNode = j;
        }
        tg = minNode->info.diemTB;
        minNode->info.diemTB = i->info.diemTB;
        i->info.diemTB = tg;
    }
    xuatDS(Q);
}

//dem so luong sv dat hoc bong voi dieu kien diemTB >= 8.0
void dem(List Q)
{
    int dem = 0;
    Node *p;
    for(p = Q.Head; p!= NULL; p = p->next)
    {
        if(p->info.diemTB >= 8.0)
            dem++;
    }
    cout << "\n So luong sinh vien dat hoc bong: " << dem << endl;
}

int main()
{
	int n;
	List Q;
	SinhVien x;
	SinhVien k;
	Node *q,*p;
	int chon;
	menu:
        cout << "\n\t  MENU";
        cout << "\n 1. Nhap danh sach sinh vien";
        cout << "\n 2. Xuat danh sach ra man hinh";
        cout << "\n 3. Chen 1 sv vao dau danh sach";
        cout << "\n 4. Them 1 sinh vien sau sv co masv x";
        cout << "\n 5. Xoa cac SV co diemTB < 3.5";
        cout << "\n 6. Sap xep theo thu tu tang dan cua diem tb";
        cout << "\n 7. Sap xep chon truc tiep";
        cout << "\n 8. Dem so SV dat hoc bong";
        cout << "\n 0. Thoat chuong trinh";
        cout << "\n Moi ban chon: "; cin >> chon;
        switch(chon)
        {
            case 1:
                nhapDS(Q);
                goto menu;
            case 2:
                cout << "\n\t\t\t\t DANH SACH SINH VIEN\n";
                xuatDS(Q);
                goto menu;
            case 3:
                chenSV(Q);
                goto menu;
            case 4:
                them1SVSaux(Q, k);
                goto menu;
            case 5:
                cout << "\n\t DANH SACH SINH VIEN SAU KHI XOA \n";
                xoa(Q);
                goto menu;
            case 6:
                cout<<"\n\t DANH SACH SINH VIEN SAU KHI SAP XEP \n";
                sapXep(Q);
                goto menu;
            case 7:
                sapXepChon(Q);
                goto menu;
            case 8:
                dem(Q);
                goto menu;
            case 0:
                exit(0);
            default:
                cout << "Nhap sai! Moi ban nhap lai!" << endl;
                goto menu;
        }
    return 0;
}
