#include <bits/stdc++.h>
using namespace std;
struct NhanVien
{
    int MaNV;
    string HoTen;
    string NgaySinh;
    int TongLuong;
};
struct Node
{
    NhanVien info;
    struct Node *next;
    struct Node *prev;
};
struct Queue
{
    Node *Head;
    Node *Tail;
};
Queue Q;
void Nhap(NhanVien &x)
{
    cout << "\nNhap ma nhan vien: "; cin >> x.MaNV;
    cout << "Nhap ho ten: "; cin.ignore(); getline(cin, x.HoTen);
    cout << "Nhap ngay sinh: "; getline(cin, x.NgaySinh);
    cout << "Nhap tong luong: "; cin >> x.TongLuong;
}
void Hien(NhanVien &x)
{
    cout << setw(5)  << x.MaNV
         << setw(22) << x.HoTen
         << setw(14) << x.NgaySinh
         << setw(13) << x.TongLuong << endl;
}
void KhoiTaoRong(Queue Q)
{
    Q.Head = NULL;
    Q.Tail = NULL;
}
Node *Get_node(NhanVien x)
{
    Node *p;
    p = new Node;
    if(p == NULL)
    {
        cout << "Khong du bo nho.";
        exit(1);
    }
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
int KiemTraRong(Queue Q)
{
    if (Q.Head == NULL)
    {
        return 1;
    }
    return 0;
}
void Insert(Queue &Q, NhanVien x)
{
    Node *p;
    p = new Node;
    if(p == NULL)
    {
        cout << "Khong bo sung duoc.";
        exit(1);
    }
    p->info = x;
    if(Q.Tail == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
        Q.Head = p;
        Q.Tail = p;
    }
    else
    {
        p->prev = Q.Tail;
        p->next = NULL;
        Q.Tail->next = p;
        Q.Tail = p;
    }
}
void Remove(Queue &Q, NhanVien &x)
{
    Node *p;
    if(Q.Head == NULL)
    {
        cout << "\nKhong huy bo duoc.";
        exit(1);
    }
    x = Q.Head->info;
    p = Q.Head;
    Q.Head = p->next;
    Q.Head->prev = NULL;
    if(Q.Head == NULL)
        Q.Tail = NULL;
    delete p;
}
void NhapDS(Queue &Q)
{
	int n, i;
	cout << "\nNhap so luong nhan vien: "; cin >> n;
    for(i = 0; i < n; i++)
    {
        NhanVien x;
        cout << "\nNhan vien thu " << i + 1;
        Nhap(x);
        Node *p;
        p = Get_node(x);
        Insert(Q, x);
    }
}
void HienDS(Queue Q)
{
    Node *p;
    cout << setw(6)  << "\n MaNV"
         << setw(20) << "Ho Ten"
         << setw(15) << "Ngay Sinh"
         << setw(15) << "Tong Luong" << endl;
    cout << "---------------------------------------------------------" << endl;
    for(p = Q.Head; p != NULL; p = p->next)
    {
        Hien(p->info);
    }
}
// Them mot nhan vien vao dau danh sach
void ThemDau(Queue &Q, int n)
{
    Node *p;
    NhanVien x;
    Nhap(x);
    p = Get_node(x);
    if(p == NULL)
    {
        cout << "Khong bo sung duoc.";
        exit(1);
    }
    p->info = x;
    if(Q.Head == NULL)
    {
        p->prev = NULL;
        p->next = NULL;
        Q.Tail = p;
        Q.Head = p;
    }
    else
    {
        p->next = Q.Head;
        p->prev = NULL;
        Q.Head->prev = p;
        Q.Head = p;
    }
    n++;
}
// Tong luong cua tat ca cac nhan vien trong danh sach
void TongLuongAll(Queue &Q)
{
    Node *p;
    int sum = 0;
    for(p = Q.Head; p != NULL; p = p->next)
    {
        sum += p->info.TongLuong;
    }
    cout << "\nTong luong cua tat ca cac nhan vien: " << sum << endl;
}
// Huy nhan vien cuoi cung ra khoi danh sach
void HuyNVCuoi(Queue &Q)
{
    Node *p;
    NhanVien x;
    if(Q.Tail == NULL)
    {
        cout << "\nKhong huy bo duoc.";
        exit(1);
    }
    x = Q.Tail->info;
    p = Q.Tail;
    Q.Tail = Q.Tail->prev;
    Q.Tail->next = NULL;
    if(Q.Tail == NULL)
        Q.Head = NULL;
    delete p;
    cout << "\n\t DANH SACH NHAN VIEN SAU KHI XOA\n";
    HienDS(Q);
}
// Tim nhan vien co muc luong cao nhat
void NVLuongMax(Queue &Q)
{
    Node *p;
	int max = 0;
	for(p = Q.Head; p != NULL; p = p->next)
	{
		if(max < p->info.TongLuong)
		{
			max = p->info.TongLuong;
		}
	}
	cout << "\nNhan vien co muc luong cao nhat: ";
    for(p = Q.Head; p != NULL; p = p->next)
    {
        if(max == p->info.TongLuong)
        {
            cout << p->info.HoTen;
        }
    }
    cout << endl;
}
// In ra nhan vien co muc luong > 2000000
void TimNV(Queue &Q)
{
    Node *p;
    cout << setw(6)  << "\n MaNV"
         << setw(20) << "Ho Ten"
         << setw(15) << "Ngay Sinh"
         << setw(15) << "Tong Luong" << endl;
    cout << "---------------------------------------------------------" << endl;
	for(p = Q.Head; p != NULL; p = p->next)
	{
		if(p->info.TongLuong > 2000000)
            cout << "\n" << setw(5)  << p->info.MaNV
                         << setw(22) << p->info.HoTen
                         << setw(14) << p->info.NgaySinh
                         << setw(13) << p->info.TongLuong << "\n";
	}
}
// Sap xep theo thu tu tang dan cua MaNV
void SapXep(Queue &Q)
{
    Node *p, *q;
    NhanVien x;
    p = Q.Head;
    q = p->next;
    while(p != NULL)
    {
        q = p->next;
        while(q != NULL)
        {
            if(p->info.MaNV > q->info.MaNV)
            {
                x = p->info;
                p->info = q->info;
                q->info = x;
            }
            q = q->next;
        }
        p = p->next;
    }
    cout << "\n\t DANH SACH SAU KHI SAP XEP\n";
    HienDS(Q);
}
// Luu file danh sach
void LuuFile(FILE *f, Queue Q)
{
	f = fopen("NhanVien_Queue.dat", "wb");
	int n = 0;
	Node *p;
	for(p = Q.Head; p != NULL; p = p->next)
    {
		n = n + 1;
	}
	fwrite(&n, sizeof(int), 1, f);
	cout << "\nGhi file nhan vien." << endl;
	for(p = Q.Head; p != NULL; p = p->next)
	{
		fwrite(&p->info, sizeof(NhanVien), 1, f);
	}
	fclose(f);
	cout << "\nGhi file thanh cong." << endl;
}
// Doc file danh sach
void DocFile(FILE *f, Queue Q)
{
	NhanVien x;
	int i, n;
	Node *p;
	f = fopen("NhanVien_Queue.dat", "rb");
	fread(&n, sizeof(int), 1, f);
	for(i = 0; i < n; i++)
    {
		fread(&x, sizeof(NhanVien), 1, f);
		p = Get_node(x);
		Insert(Q, x);
	}
	fclose(f);
	cout << "\nDoc file thanh cong" << endl;
	HienDS(Q);
}
int main()
{
    FILE *f;
    Node *p;
    int n, c;
    do
    {
        cout << "\n\t\tMENU";
        cout << "\n1. Nhap danh sach nhan vien";
        cout << "\n2. Hien danh sach nhan vien";
        cout << "\n3. Them nhan vien vao dau";
        cout << "\n4. Tong luong tat ca cac nhan vien";
        cout << "\n5. Lay nhan vien cuoi ra";
        cout << "\n6. Tim nhan vien co muc luong cao nhat";
        cout << "\n7. In ra DSNV co muc luong > 2000000";
        cout << "\n8. Sap xep thu tu tang dan MaNV";
        cout << "\n9. Luu file danh sach";
        cout << "\n10.Doc file danh sach";
        cout << "\n0. Thoat chuong trinh";
        cout << "\nMoi ban chon: "; cin >> c;
        switch(c)
        {
            case 1:
                KhoiTaoRong(Q);
                NhapDS(Q);
                break;
            case 2:
                cout << "\n\t\t DANH SACH NHAN VIEN\n";
                HienDS(Q);
                break;
            case 3:
                ThemDau(Q, n);
                cout << "\n\t\tDANH SACH SAU KHI THEM\n";
                HienDS(Q);
                break;
            case 4:
                TongLuongAll(Q);
                break;
            case 5:
                HuyNVCuoi(Q);
                break;
            case 6:
                NVLuongMax(Q);
                break;
            case 7:
                cout << "\n\tDANH SACH NHAN VIEN CO MUC LUONG > 2000000\n";
                TimNV(Q);
                break;
            case 8:
                SapXep(Q);
                break;
            case 9:
                LuuFile(f, Q);
                break;
            case 10:
                DocFile(f, Q);
                break;
            case 0:
                exit(1);
            default:
                cout << "\nNhap sai! Moi ban nhap lai." << endl;
                break;
        }
    }
    while(c != 0);
    return 0;
}
