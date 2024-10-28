#include <bits/stdc++.h>

using namespace std;

struct SinhVien
{
    string MaSV, HoTen, Lop;
    float diemLT, diemTH, diemThi, diemTB;
};

typedef struct Node
{
    SinhVien info;
    struct Node *next;
};

typedef struct List
{
    Node *Head;
    Node *Tail;
};
struct List Q;

int KiemTraRong(List Q)
{
    if (Q.Head == NULL)
    {
        return 1;
    }
    return 0;
}

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
        cout << " Khong du bo nho.";
        exit(1);
    }
    p->info = x;
    p->next = NULL;
    return p;
}

SinhVien Nhap(){
	SinhVien x;
	cin.ignore();
	cout << "\n Nhap ma sinh vien: "; getline(cin, x.MaSV);
	cout << " Nhap ho ten sinh vien: "; getline(cin, x.HoTen);
	cout << " Nhap lop: "; getline(cin, x.Lop);
	cout << " Nhap diem ly thuyet: "; cin >> x.diemLT;
	cout << " Nhap diem thuc hanh: "; cin >> x.diemTH;
	cout << " Nhap diem thi: "; cin >> x.diemThi;
	x.diemTB = x.diemLT*0.1 + x.diemTH*0.2 + x.diemThi*0.7;
	return x;
}

// chen dau
void InsertFirst(List& Q, int n)
{
    SinhVien data = Nhap();
    Node *p = get_node(data);
    if(Q.Head == NULL)
    {
        Q.Head = p;
        Q.Tail = Q.Head;
    }
    else
    {
        p->next = Q.Head;
        Q.Head = p;
    }
    n++;
}
// chen cuoi
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
// chen giua
void InsertAfter(List &Q, Node *q, Node *p)
{
    if (q != NULL)
    {
        p->next = q->next;
        q->next = p;
        if (q == Q.Tail)
            Q.Tail = p;
    }
}

void nhapDS(List &Q, int n)
{
    SinhVien x;
    int i;
	cout << "\n Nhap so luong sinh vien: "; cin >> n;
	for(i = 0; i < n; i++)
	{
		cout << "\n Sinh vien thu " << i+1;
		cout << "\n Nhap ma sinh vien: "; cin.ignore();getline(cin, x.MaSV);
        cout << " Nhap ho va ten: "; getline(cin, x.HoTen);
        cout << " Nhap ten lop: "; getline(cin, x.Lop);
        cout << " Nhap diem ly thuyet: "; cin >> x.diemLT;
        cout << " Nhap diem thuc hanh: "; cin >> x.diemTH;
        cout << " Nhap diem thi: "; cin >> x.diemThi;
        x.diemTB = x.diemLT*0.1 + x.diemTH*0.2 + x.diemThi*0.7;
        Node *p = get_node(x);
        InsertLast(Q, p);
	}
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
/*
Node *Search1(LIST Q , SinhVien k ,Node *&q)
{
    Node *p ;
    q = NULL;
    p = Q.svHead;
    while((p!=NULL) && (p->data.MaSV!=k.MaSV))
    {
        q = p;
        p = p->next;
    }
    return p;
}

Node *Search(LIST Q, string s, Node *&q){
	Node *p = Q.svHead;
	q = NULL;
	while(p != NULL && p->data.MaSV != s){
		q = p;
		p = p->next;
	}
	return p;
}
*/
void them1svsaux(LIST &Q, SinhVien sv, string s){
	Node *a = newNode(sv);
	Node *q = NULL;
	Node *p = Search(Q, s, q);
	if(a != NULL){
		a->next = p->next;
		p->next = a;
		if(a->next == NULL){
			Q.svTail = a;
		}
	}
}

void xoadau(LIST &Q){
	Node *p = Q.svHead;
	if(p != NULL){
		Q.svHead = Q.svHead->next;
		delete p;
		if(Q.svHead == NULL){
			Q.svTail = NULL;
		}
	}
}

void xoacuoi(LIST &Q){
	Node *p = Q.svHead;
	if(p != NULL){
		while(p->next->next != NULL){
			p = p->next;
		}
		delete p->next;
		p->next = NULL;
		Q.svTail = p;
		if(Q.svTail == NULL){
			Q.svHead == NULL;
		}
	}
}

void xoaphantu(LIST &Q, string s){
	Node *q = NULL;
	Node *p = Search(Q, s, q);
	if(p != NULL){
		if(p == Q.svHead){
			xoadau(Q);
		}
		else if(p == Q.svTail){
			xoacuoi(Q);
		}
		else{
			q->next = p->next;
			delete p;
		}
	}
}

void sapxep(LIST &Q)
{
    Node *p,*q,*min ;
    SinhVien tg;
    for(p=Q.svHead;p!=NULL;p=p->next)
    {
    	min=p;
    	for(q=p->next;q!=NULL;q=q->next)
    	{
    		if(min->data.diemTB>q->data.diemTB)
    		   min=q;
		}
		tg=min->data;
		min->data=p->data;
		p->data=tg;
	}
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
// Luu file danh sach
void luuFile(FILE *f, List &Q)
{
	f = fopen("SinhVien.dat", "wb");
	int n = 0;
	Node *p;
	for(p = Q.Head; p != NULL; p = p->next)
	    n = n + 1;
	fwrite(&n, sizeof(int), 1, f);
	for(p = Q.Head; p != NULL; p = p->next)
	  fwrite(&p->info, sizeof(SinhVien), 1, f);
	  fclose(f);
}
// Ghi file danh sach
void docFile(FILE *f, List &Q)
{
	SinhVien x;
	int n, i;
	Node *p;
	f = fopen("SinhVien.dat", "rb");
	fread(&n, sizeof(int), 1, f);
	for(i=0;i<n;i++)
	{
		fread(&x, sizeof(SinhVien), 1, f);
		p = get_node(x);
		InsertFirst(Q, n);
	}
	fclose(f);
}
// Thong ke va in ra man hinh ds thuoc lop x voi x nhap tu ban phim
void xuatSVLopx(List Q)
{
    SinhVien k;
    Node *q, *p;
    cout << " Nhap lop x: ";
    cin >> k.Lop;
    cout << "\n\t DANH SACH SINH VIEN CO MA LOP " << k.Lop << " \t\n";
    cout << setw(6) << "\n MaSV "
         << setw(20) << " Ho ten"
         << setw(14) << " Lop "
         << setw(13) << " Diem LT "
         << setw(12) << " Diem TH "
         << setw(12) << " Diem Thi"
         << setw(13) << " Diem TB " << "\n";
    for(p = Q.Head ; p!=NULL ; p = p->next)
    {
        if(k.Lop == p->info.Lop)
        {
           cout << setw(6)  << p->info.MaSV
                << setw(20) << p->info.HoTen
                << setw(10) << p->info.Lop
                << setw(7)  << p->info.diemLT
                << setw(12) << p->info.diemTH
                << setw(12) << p->info.diemThi
                << setw(14) << p->info.diemTB << "\n";
        }
    }
}

int main()
{
	int n;
	List Q;
	SinhVien x;
	Node *p;
	FILE *f;
	int chon;
	menu:
        cout << "\n\t  MENU";
        cout << "\n 1. Nhap danh sach sinh vien";
        cout << "\n 2. Xuat danh sach ra man hinh";
        cout << "\n 3. Chen 1 sv vao dau danh sach";
        cout << "\n 4. Them 1 sinh vien sau sv co MaSV x";
        cout << "\n 5. Xoa cac SV co diemTB < 3.5";
        cout << "\n 6. Sap xep theo thu tu tang dan cua diem tb";
        cout << "\n 7. Sap xep chon truc tiep DTB";
        cout << "\n 8. Dem so sinh vien dat hoc bong";
        cout << "\n 9. Doc file danh sach";
        cout << "\n 10. Luu file danh sach";
        cout << "\n 11. DS cac sinh vien thuoc lop x";
        cout << "\n 0. Thoat chuong trinh";
        cout << "\n Moi ban chon: "; cin >> chon;
        switch(chon)
        {
            case 1:
                nhapDS(Q, n);
                goto menu;
            case 2:
                cout << "\n\t\t\t\t DANH SACH SINH VIEN\n";
                xuatDS(Q);
                goto menu;
            case 3:
                InsertFirst(Q, n);
                xuatDS(Q);
                goto menu;
            case 4:
                string s;
                cout << " Nhap thong tin sinh vien moi";
                SinhVien sv = Nhap();
                cout << " Nhap ma sinh vien muon chen sau: "; cin.ignore(); getline(cin, s);
                them1SVSaux(Q, sv, s);
                goto menu;
            case 5:
                cout << "\n\t DANH SACH SINH VIEN SAU KHI XOA \n";
                xoa(Q);
                xuatDS(Q);
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
            case 9:
                docFile(f, Q);
                goto menu;
            case 10:
                luuFile(f, Q);
                goto menu;
            case 11:
                xuatSVLopx(Q);
                goto menu;
            case 0:
                exit(0);
            default:
                cout << " Nhap sai! Moi ban nhap lai!" << endl;
                goto menu;
        }
    return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;

struct SinhVien
{
    string MaSV, HoTen, Lop;
    float diemLT, diemTH, diemThi, diemTB;
};

typedef struct Node
{
    SinhVien info;
    struct Node *next;
};

typedef struct List
{
    Node *Head;
    Node *Tail;
};
struct List Q;

int KiemTraRong(List Q)
{
    if (Q.Head == NULL)
    {
        return 1;
    }
    return 0;
}

void init(List &Q)
{
    Q.Head = NULL;
    Q.Tail = NULL;
}

Node *get_node(SinhVien x)
{
    Node *p;
    p = get_node;
    if (p==NULL)
    {
        cout << " Khong du bo nho.";
        exit(1);
    }
    p->info = x;
    p->next = NULL;
    return p;
}

SinhVien Nhap(){
	SinhVien x;
	cin.ignore();
	cout<<"\n Nhap ma sinh vien: "; getline(cin, x.MaSV);
	cout<<" Nhap ho ten sinh vien: "; getline(cin, x.HoTen);
	cout<<" Nhap lop: "; getline(cin, x.Lop);
	cout<<" Nhap diem ly thuyet: "; cin>>x.diemLT;
	cout<<" Nhap diem thuc hanh: "; cin>>x.diemTH;
	cout<<" Nhap diem thi: "; cin>>x.diemThi;
	x.diemTB = x.diemLT*0.1 + x.diemTH*0.2 + x.diemThi*0.7;
	return x;
}

// chen dau
void InsertFirst (List& Q, int n)
{
    SinhVien data = Nhap();
    Node *p = get_node(data);
    if(Q.Head == NULL)
    {
        Q.Head = p;
        Q.Tail = Q.Head;
    }
    else
    {
        p->next = Q.Head;
        Q.Head = p;
    }
    n++;
}
// chen cuoi
void InsertLast (List &Q, Node *p)
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
// chen giua
void InsertAfter (List &Q, Node *q, Node *p)
{
    if (q != NULL)
    {
        p->next = q->next;
        q->next = p;
        if (q == Q.Tail)
            Q.Tail = p;
    }
}

void nhapDS (List &Q, int n)
{
    SinhVien x;
    int i;
	cout << "\n Nhap so luong sinh vien: "; cin >> n;
	for(i = 0; i < n; i++)
	{
		cout << "\n Sinh vien thu " << i+1;
		cout << "\n Nhap ma sinh vien: "; cin.ignore();getline(cin, x.MaSV);
        cout << " Nhap ho va ten: "; getline(cin, x.HoTen);
        cout << " Nhap ten lop: "; getline(cin, x.Lop);
        cout << " Nhap diem ly thuyet: "; cin >> x.diemLT;
        cout << " Nhap diem thuc hanh: "; cin >> x.diemTH;
        cout << " Nhap diem thi: "; cin >> x.diemThi;
        x.diemTB = x.diemLT*0.1 + x.diemTH*0.2 + x.diemThi*0.7;
        Node *p = get_node(x);
        InsertLast(Q, p);
	}
}

void xuatDS (List Q)
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
void chenSV (List &Q, int n)
{
    SinhVien x;
    cout << "\n Nhap thong tin sinh vien";
    cout << "\n Nhap ma sinh vien: "; cin.ignore();getline(cin, x.MaSV);
    cout << " Nhap ho va ten: "; getline(cin, x.HoTen);
    cout << " Nhap ten lop: "; getline(cin, x.Lop);
    cout << " Nhap diem ly thuyet: "; cin >> x.diemLT;
    cout << " Nhap diem thuc hanh: "; cin >> x.diemTH;
    cout << " Nhap diem thi: "; cin >> x.diemThi;
    x.diemTB = x.diemLT*0.1 + x.diemTH*0.2 + x.diemThi*0.7;
    Node *p;
    p = get_node(x);
    InsertFirst(Q, n);
    cout<<"\n\t DANH SACH SINH VIEN SAU KHI THEM\n";
    xuatDS(Q);
}

Node *Searchk (List Q, SinhVien k, Node *&q)
{
    Node *p ;
    q = NULL;
    p = Q.Head;
    while((p!=NULL) && (p->info.MaSV != k.MaSV))
    {
        q = p;
        p = p->next;
    }
    return p;
}

Node *Search (List Q, string s, Node *&q)
{
	Node *p = Q.Head;
	q = NULL;
	while(p != NULL && p->info.MaSV != s)
    {
		q = p;
		p = p->next;
	}
	return p;
}

void them1SVSaux (List &Q, SinhVien sv, string s)
{
	Node *a = get_node(sv);
	Node *q = NULL;
	Node *p = Search(Q, s, q);
	if(a != NULL)
    {
		a->next = p->next;
		p->next = a;
		if(a->next == NULL)
        {
			Q.Tail = a;
		}
	}
}
// xoa dau
void RemoveHead (List &Q)
{
	Node *p;
	if(p != NULL)
    {
        p = Q.Head;
		Q.Head = Q.Head->next;
		delete p;
		if(Q.Head == NULL)
        {
			Q.Tail = NULL;
		}
	}
}
// xoa cuoi
void RemoveTail (List &Q)
{
	Node *p = Q.Head;
	if(p != NULL)
    {
		while(p->next->next != NULL)
		{
			p = p->next;
		}
		delete p->next;
		p->next = NULL;
		Q.Tail = p;
		if(Q.Tail == NULL)
        {
			Q.Head == NULL;
		}
	}
}

void RemoveAfter (List &Q, string s)
{
	Node *q = NULL;
	Node *p = Search(Q, s, q);
	if(p != NULL)
	{
		if(p == Q.Head)
        {
			RemoveHead(Q);
		}
		else if(p == Q.Tail)
        {
			RemoveTail(Q);
		}
		else
        {
			q->next = p->next;
			delete p;
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

// sap xep dtb theo thuat toan chon truc tiep
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
}

/*
//them 1 sv va chen vao dau ds
void chenSV(List &Q, int n)
{
    SinhVien x;
    cout << "\n Nhap thong tin sinh vien";
    cout << "\n Nhap ma sinh vien: "; cin.ignore();getline(cin, x.MaSV);
    cout << " Nhap ho va ten: "; getline(cin, x.HoTen);
    cout << " Nhap ten lop: "; getline(cin, x.Lop);
    cout << " Nhap diem ly thuyet: "; cin >> x.diemLT;
    cout << " Nhap diem thuc hanh: "; cin >> x.diemTH;
    cout << " Nhap diem thi: "; cin >> x.diemThi;
    x.diemTB = x.diemLT*0.1 + x.diemTH*0.2 + x.diemThi*0.7;
    Node *p;
    p = get_node(x);
    InsertFirst(Q, n);
    cout<<"\n\t DANH SACH SINH VIEN SAU KHI THEM\n";
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

// Doc/ ghi file danh sach
// Thong ke va in ra man hinh ds thuoc lop x voi x nhap tu ban phim

int main()
{
	int n;
	List Q;
	SinhVien x;
	SinhVien k;
	Node *p;
	int chon;
	menu:
        cout << "\n\t  MENU";
        cout << "\n 1. Nhap danh sach sinh vien";
        cout << "\n 2. Xuat danh sach ra man hinh";
        cout << "\n 3. Chen 1 sv vao dau danh sach";
        cout << "\n 4. Them 1 sinh vien sau sv co masv x";
        cout << "\n 5. Xoa cac SV co diemTB < 3.5";
        cout << "\n 6. Sap xep theo thu tu tang dan cua diem tb";
        cout << "\n 7. Sap xep chon truc tiep DTB";
        cout << "\n 8. Dem so SV dat hoc bong";
        cout << "\n 9. Doc file danh sach";
        cout << "\n 10. Luu file danh sach";
        cout << "\n 11. DS cac sinh vien thuoc lop x";
        cout << "\n 0. Thoat chuong trinh";
        cout << "\n Moi ban chon: "; cin >> chon;
        switch(chon)
        {
            case 1:
                nhapDS(Q, n);
                goto menu;
            case 2:
                cout << "\n\t\t\t\t DANH SACH SINH VIEN\n";
                xuatDS(Q);
                goto menu;
            case 3:
                InsertFirst(Q, n);
                xuatDS(Q);
                goto menu;
            case 4:
                them1SVSaux(Q, sv, s);
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
                xuatDS(Q);
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
#include <bits/stdc++.h>

using namespace std;

struct SinhVien
{
    string MaSV, HoTen, Lop;
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

int KiemTraRong(List Q)
{
    if (Q.Head == NULL)
    {
        return 1;
    }
    return 0;
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

SinhVien Nhap()
{
	SinhVien x;
	cin.ignore();
	cout << "\n Nhap ma sinh vien: "; getline(cin, x.MaSV);
	cout << " Nhap ho ten sinh vien: "; getline(cin, x.HoTen);
	cout << " Nhap lop: "; getline(cin, x.Lop);
	cout << " Nhap diem ly thuyet: "; cin >> x.diemLT;
	cout << " Nhap diem thuc hanh: "; cin >> x.diemTH;
	cout << " Nhap diem thi: "; cin >> x.diemThi;
	x.diemTB = x.diemLT*0.1 + x.diemTH*0.2 + x.diemThi*0.7;
	return x;
}

// chen dau
void InsertFirst(List& Q, int n)
{
    SinhVien data = Nhap();
    Node *p = get_node(data);
    if(Q.Head == NULL)
    {
        Q.Head = p;
        Q.Tail = Q.Head;
    }
    else
    {
        p->next = Q.Head;
        Q.Head = p;
    }
    n++;
}
// chen cuoi
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
// chen giua
void InsertAfter(List &Q, Node *q, Node *p)
{
    if (q != NULL)
    {
        p->next = q->next;
        q->next = p;
        if (q == Q.Tail)
            Q.Tail = p;
    }
}

void nhapDS(List &Q, int n)
{
    SinhVien x;
    int i;
	cout << "\n Nhap so luong sinh vien: "; cin >> n;
	for(i = 0; i < n; i++)
	{
		cout << "\n Sinh vien thu " << i+1;
		cout << "\n Nhap ma sinh vien: "; cin.ignore();getline(cin, x.MaSV);
        cout << " Nhap ho va ten: "; getline(cin, x.HoTen);
        cout << " Nhap ten lop: "; getline(cin, x.Lop);
        cout << " Nhap diem ly thuyet: "; cin >> x.diemLT;
        cout << " Nhap diem thuc hanh: "; cin >> x.diemTH;
        cout << " Nhap diem thi: "; cin >> x.diemThi;
        x.diemTB = x.diemLT*0.1 + x.diemTH*0.2 + x.diemThi*0.7;
        Node *p = get_node(x);
        InsertLast(Q, p);
	}
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
Node *Searchk(List Q, SinhVien k, Node *&q)
{
    Node *p ;
    q = NULL;       //q la phan tu truoc p
    p = Q.Head;
    while((p != NULL) && (p->info.MaSV != k.MaSV))
    {
        q = p;
        p = p->next;
    }
    return p;
}
Node *Search(List Q, string s, Node *&q)
{
	Node *p;
	q = NULL;
	p = Q.Head;
	while((p != NULL) && (p->info.MaSV != s))
    {
		q = p;
		p = p->next;
	}
	return p;
}
/*
void them1SVSaux(List &Q, SinhVien sv, string s)
{
	Node *a = get_node(sv);
	Node *q = NULL;
	Node *p = Search(Q, s, q);
	if(a != NULL)
    {
		a->next = p->next;
		p->next = a;
		if(a->next == NULL)
        {
			Q.Tail = a;
		}
	}
}

void AddAfter(List &Q)
{
    string s;
    cout << " Nhap thong tin sinh vien moi ";
    SinhVien sv = Nhap();
    cout << " Nhap ma sinh vien muon chen sau: "; cin.ignore(); getline(cin, s);
    them1SVSaux(Q, sv, s);
}

// xoa dau
void RemoveHead (List &Q)
{
	Node *p;
	if(p != NULL)
    {
        p = Q.Head;
		Q.Head = Q.Head->next;
		delete p;
		if(Q.Head == NULL)
        {
			Q.Tail = NULL;
		}
	}
}
// xoa cuoi
void RemoveTail (List &Q)
{
	Node *p = Q.Head;
	if(p != NULL)
    {
		while(p->next->next != NULL)
		{
			p = p->next;
		}
		delete p->next;
		p->next = NULL;
		Q.Tail = p;
		if(Q.Tail == NULL)
        {
			Q.Head == NULL;
		}
	}
}

void RemoveAfter (List &Q, string s)
{
	Node *q = NULL;
	Node *p = Search(Q, s, q);
	if(p != NULL)
	{
		if(p == Q.Head)
        {
			RemoveHead(Q);
		}
		else if(p == Q.Tail)
        {
			RemoveTail(Q);
		}
		else
        {
			q->next = p->next;
			delete p;
		}
	}
}

// xoa cac sinh vien co diemTB < 3.5
void xoa(List &Q)
{
    int dem = 0;
    Node *p = Q.Head;
    while(p != NULL)
    {
        if(p->info.diemTB < 3.5)
        {
            RemoveAfter(Q, p->info.MaSV);
            dem++;
        }
        p = p->next;
    }
    if(dem != 0)
    {
        cout << "\n\t DANH SACH SINH VIEN SAU KHI XOA \n";
        xuatDS(Q);
    }
    else
    {
        cout << " Khong co phan tu nao.";
    }
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
    Node *p, *q, *minNode;
    SinhVien tg;
    for(p = Q.Head; p != NULL; p = p->next)
    {
    	minNode = p;
    	for(q = p->next; q != NULL; q = q->next)
    	{
    		if(minNode->info.diemTB > q->info.diemTB)
    		   minNode = q;
		}
		tg = minNode->info;
		minNode->info = p->info;
		p->info = tg;
	}
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

// Luu file danh sach
void luuFile(FILE *f, List &Q)
{
	f = fopen("SinhVien.dat", "wb");
	int n = 0;
	Node *p;
	for(p = Q.Head; p != NULL; p = p->next)
	    n = n + 1;
	fwrite(&n, sizeof(int), 1, f);
	for(p = Q.Head; p != NULL; p = p->next)
	  fwrite(&p->info, sizeof(SinhVien), 1, f);
	  fclose(f);
}

// Ghi file danh sach
void docFile(FILE *f, List &Q)
{
	SinhVien x;
	int n, i;
	Node *p;
	f = fopen("SinhVien.dat", "rb");
	fread(&n, sizeof(int), 1, f);
	for(i=0;i<n;i++)
	{
		fread(&x, sizeof(SinhVien), 1, f);
		p = get_node(x);
		InsertFirst(Q, n);
	}
	fclose(f);
}

// Thong ke va in ra man hinh ds thuoc lop x voi x nhap tu ban phim
void xuatSVLopx(List Q)
{
    SinhVien k;
    Node *q, *p;
    cout << " Nhap lop x: ";
    cin >> k.Lop;
    cout << "\n\t\t DANH SACH SINH VIEN LOP " << k.Lop << "\n";
    cout << setw(6) << "\n MaSV "
         << setw(20) << " Ho ten"
         << setw(14) << " Lop "
         << setw(13) << " Diem LT "
         << setw(12) << " Diem TH "
         << setw(12) << " Diem Thi"
         << setw(13) << " Diem TB " << "\n";
    for(p = Q.Head ; p!=NULL ; p = p->next)
    {
        if(k.Lop == p->info.Lop)
        {
           cout << setw(6)  << p->info.MaSV
                << setw(20) << p->info.HoTen
                << setw(10) << p->info.Lop
                << setw(7)  << p->info.diemLT
                << setw(12) << p->info.diemTH
                << setw(12) << p->info.diemThi
                << setw(14) << p->info.diemTB << "\n";
        }
    }
}

int main()
{
	int n;
	List Q;
	FILE *f;
	SinhVien x;
	Node *p;
	int d;
	int chon;
	menu:
        cout << "\n\t  MENU";
        cout << "\n 1. Nhap danh sach sinh vien";
        cout << "\n 2. Xuat danh sach ra man hinh";
        cout << "\n 3. Chen 1 sv vao dau danh sach";
        cout << "\n 4. Them 1 sinh vien sau sv co MaSV x";
        cout << "\n 5. Xoa cac SV co diemTB < 3.5";
        cout << "\n 6. Sap xep theo thu tu tang dan cua diem tb";
        cout << "\n 7. Sap xep chon truc tiep DTB";
        cout << "\n 8. Dem so SV dat hoc bong";
        cout << "\n 9. Doc file danh sach";
        cout << "\n 10. Luu file danh sach";
        cout << "\n 11. DS cac sinh vien thuoc lop x";
        cout << "\n 0. Thoat chuong trinh";
        cout << "\n Moi ban chon: "; cin >> chon;
        switch(chon)
        {
            case 1:
                nhapDS(Q, n);
                goto menu;
            case 2:
                cout << "\n\t\t\t\t DANH SACH SINH VIEN\n";
                xuatDS(Q);
                goto menu;
            case 3:
                InsertFirst(Q, n);
                xuatDS(Q);
                goto menu;
            /*case 4:
                AddAfter(Q);
                xuatDS(Q);
                goto menu;*/
            case 5:
                xoa(Q);
                goto menu;
            case 6:
                cout<<"\n\t DANH SACH SINH VIEN SAU KHI SAP XEP \n";
                sapXep(Q);
                goto menu;
            case 7:
                sapXepChon(Q);
                xuatDS(Q);
                goto menu;
            case 8:
                dem(Q);
                goto menu;
            case 9:
                docFile(f, Q);
                goto menu;
            case 10:
                luuFile(f, Q);
                goto menu;
            case 11:
                xuatSVLopx(Q);
                goto menu;
            case 0:
                exit(0);
            default:
                cout << "Nhap sai! Moi ban nhap lai!" << endl;
                goto menu;
        }
    return 0;
}

*/
