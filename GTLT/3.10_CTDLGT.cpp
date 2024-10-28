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

void KhoiTao(List &Q)
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
	cout << " Nhap ten lop: "; getline(cin, x.Lop);
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

void nhapDS(List &Q, int n)
{
    SinhVien x;
    int i;
	for(i = 0; i < n; i++)
	{
		cout << "\n Sinh vien thu " << i+1;
		cout << "\n Nhap ma sinh vien: "; cin.ignore(); getline(cin, x.MaSV);
        cout << " Nhap ho va ten: "; getline(cin, x.HoTen);
        cout << " Nhap ten lop: "; getline(cin, x.Lop);
        cout << " Nhap diem ly thuyet: "; cin >> x.diemLT;
        cout << " Nhap diem thuc hanh: "; cin >> x.diemTH;
        cout << " Nhap diem thi: "; cin >> x.diemThi;
        x.diemTB = x.diemLT*0.1 + x.diemTH*0.2 + x.diemThi*0.7;
        Node *p = new Node;
        p = get_node(x);
        InsertLast(Q, p);
	}
}

void xuatDS(List Q)
{
    Node *p = new Node;
    cout << setw(6)  << "\n  MaSV "
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
    cout << "\n Nhap ten lop x: ";
    cin >> k.Lop;
    cout << "\n\t DANH SACH SINH VIEN LOP " << k.Lop << "\n";
    cout << setw(6) << "\n  MaSV "
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
	int chon;
	menu:
        cout << "\n\t  MENU";
        cout << "\n 1. Nhap danh sach sinh vien";
        cout << "\n 2. Xuat danh sach ra man hinh";
        cout << "\n 3. Chen 1 sv vao dau danh sach";
        cout << "\n 4. Xoa cac SV co diemTB < 3.5";
        cout << "\n 5. Sap xep theo thu tu tang dan cua diem tb";
        cout << "\n 6. Sap xep chon truc tiep DTB";
        cout << "\n 7. Dem so SV dat hoc bong";
        cout << "\n 8. Doc file danh sach";
        cout << "\n 9. Luu file danh sach";
        cout << "\n 10. DS cac sinh vien thuoc lop x";
        cout << "\n 0. Thoat chuong trinh";
        cout << "\n Moi ban chon: "; cin >> chon;
        switch(chon)
        {
            case 1:
                cout << "\n Nhap so luong sinh vien: "; cin >> n;
                KhoiTao(Q);
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
                cout << "\n\t DANH SACH SINH VIEN SAU KHI XOA \n";
                xoa(Q);
                goto menu;
            case 5:
                cout<<"\n\t DANH SACH SINH VIEN SAU KHI SAP XEP \n";
                sapXep(Q);
                goto menu;
            case 6:
                sapXepChon(Q);
                goto menu;
            case 7:
                dem(Q);
                goto menu;
            case 8:
                docFile(f, Q);
                goto menu;
            case 9:
                luuFile(f, Q);
                goto menu;
            case 10:
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