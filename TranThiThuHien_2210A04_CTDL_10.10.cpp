#include <bits/stdc++.h>
using namespace std;
typedef struct NhanVien
{
    int MaNV;
    string HoTen;
    string NgaySinh;
    int TongLuong;
};
typedef struct DNode
{
    NhanVien info;
    struct DNode *next;
    struct DNode *prev;
};
typedef struct DList
{
    DNode *Head;
    DNode *Tail;
};
struct DList DQ;
void KhoiTaoRong(DList &DQ)
{
    DQ.Head = NULL;
    DQ.Tail = NULL;
}
int KiemTraRong(DList DQ)
{
    if (DQ.Head == NULL)
    {
        return 1;
    }
    return 0;
}
DNode *Get_node(NhanVien x)
{
    DNode *p;
    p = new DNode;
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
NhanVien Nhap()
{
    NhanVien x;
    cout << "\nNhap ma nhan vien: "; cin >> x.MaNV;
    cout << "Nhap ho ten: "; cin.ignore(); getline(cin, x.HoTen);
    cout << "Nhap ngay sinh: "; getline(cin, x.NgaySinh);
    cout << "Nhap tong luong: "; cin >> x.TongLuong;
    return x;
}
void AddFirst(DList &DQ, DNode *p)
{
    if(DQ.Head == NULL)
    {
        DQ.Head = p;
        DQ.Tail = DQ.Head;
    }
    else
    {
        p->next = DQ.Head;
        DQ.Head->prev = p;
        DQ.Head = p;
    }
}
void AddLast(DList &DQ, DNode *p)
{
    if(DQ.Head == NULL)
    {
        DQ.Head = p;
        DQ.Tail = DQ.Head;
    }
    else
    {
        DQ.Tail->next = p;
        p->prev = DQ.Tail;
        DQ.Tail = p;
    }
}
void NhapDS(DList &DQ, int n)
{
    int i;
    DNode *p;
    NhanVien x;
    for(i = 0; i < n; i++)
    {
        cout << "\nNhap ma nhan vien: "; cin >> x.MaNV;
        cout << "Nhap ho ten: "; cin.ignore(); getline(cin, x.HoTen);
        cout << "Nhap ngay sinh: "; getline(cin, x.NgaySinh);
        cout << "Nhap tong luong: "; cin >> x.TongLuong;
        p = new DNode;
        p = Get_node(x);
        AddLast(DQ, p);
    }
}
void XuatDS(DList &DQ)
{
    DNode *p;
    NhanVien x;
    p = new DNode;
    cout << setw(6)  << "\n MaNV"
         << setw(20) << "Ho Ten"
         << setw(15) << "Ngay Sinh"
         << setw(15) << "Tong Luong" << "\n";
    for(p = DQ.Head; p!= NULL; p = p->next)
    {
        cout << "\n" << setw(5)  << p->info.MaNV
                     << setw(22) << p->info.HoTen
                     << setw(14) << p->info.NgaySinh
                     << setw(13) << p->info.TongLuong << "\n";
    }
}
// Them mot nhan vien vao dau danh sach
void ThemDau(DList &DQ, int n)
{
    NhanVien info = Nhap();
    DNode *p;
    p = Get_node(info);
    if(DQ.Head == NULL)
    {
        DQ.Head = p;
        DQ.Tail = DQ.Head;
    }
    else
    {
        p->next = DQ.Head;
        DQ.Head->prev = p;
        DQ.Head = p;
    }
    n++;
}
// Tong luong cua tat ca cac nhan vien trong danh sach
void TongLuongAll(DList &DQ)
{
    DNode *p;
    int sum = 0;
    for(p = DQ.Head; p!= NULL; p = p->next)
    {
        sum += p->info.TongLuong;
    }
    cout << "\nTong luong cua tat ca cac nhan vien: " << sum << endl;
}
// Huy nhan vien cuoi cung ra khoi danh sach
void HuyNVCuoi(DList &DQ)
{
	DNode *p;
	p = DQ.Tail;
    DQ.Tail = DQ.Tail->prev;
    DQ.Tail->next = NULL;
    if (DQ.Tail == NULL)
	{
        DQ.Head = NULL;
    }
    p->prev = NULL;
    delete p;
    cout << "\n\t DANH SACH NHAN VIEN SAU KHI XOA\n";
    XuatDS(DQ);
}
// Tim nhan vien co muc luong cao nhat
int Max(DList DQ)
{
	DNode *p;
	int max = DQ.Head->info.TongLuong;
	p = DQ.Head;
	while(p != NULL)
	{
		if(max < p->info.TongLuong)
        {
            max = p->info.TongLuong;
        }
		p = p->next;
	}
}

void NVLuongMax(DList &DQ)
{
	DNode *p;
	int max = DQ.Head->info.TongLuong;
	for(p = DQ.Head; p != NULL; p = p->next)
	{
		if(max < p->info.TongLuong)
            cout << "\nNhan vien co muc luong cao nhat la " << p->info.HoTen << " voi muc luong " << p->info.TongLuong << endl;
	}
}
// In ra nhan vien co muc luong > 2000000
void TimNV(DList &DQ)
{
    DNode *p;
    cout << setw(6)  << "\n MaNV"
         << setw(20) << "Ho Ten"
         << setw(15) << "Ngay Sinh"
         << setw(15) << "Tong Luong" << "\n";
	for(p = DQ.Head; p != NULL; p = p->next)
	{
		if(p->info.TongLuong > 2000000)
            cout << "\n" << setw(5)  << p->info.MaNV
                         << setw(22) << p->info.HoTen
                         << setw(14) << p->info.NgaySinh
                         << setw(13) << p->info.TongLuong << "\n";
	}
}
// Sap xep theo thu tu tang dan cua MaNV
void SapXep(DList &DQ)
{
    DNode *p, *q;
    NhanVien x;
    p = DQ.Head;
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
    XuatDS(DQ);
}
// Ghi file danh sach
void GhiFile(FILE *f, DList &DQ)
{
	f = fopen("NhanVien.dat","wb");
	int n = 0;
	DNode *p;
	for(p = DQ.Head; p != NULL; p = p->next)
	{
	    n = n + 1;
	}
	fwrite(&n, sizeof(int), 1, f);
	for(p = DQ.Head; p != NULL; p = p->next)
	{
	  fwrite(&p->info, sizeof(NhanVien), 1, f);
    }
	fclose(f);
	cout<<"\nGhi file thanh cong.\n";

}
// Doc file danh sach
void DocFile(FILE *f, DList &DQ)
{
	NhanVien x;
	int i,n;
	DNode *p;
	f = fopen("NhanVien.dat", "rb");
	fread(&n, sizeof(int), 1, f);
	for(i = 0; i < n; i++)
	{
		fread(&x, sizeof(NhanVien), 1, f);
		p = Get_node(x);
		AddFirst(DQ, p);
	}
	fclose(f);
	XuatDS(DQ);
}
int main()
{
    DList DQ;
    DNode *p;
    FILE *f;
    int n, chon;
    do
    {
        cout << "\n\t\t MENU";
        cout << "\n1. Nhap danh sach nhan vien";
        cout << "\n2. Xuat danh sach nhan vien";
        cout << "\n3. Them 1 nhan vien vao dau danh sach";
        cout << "\n4. Tong luong cua tat ca nhan vien";
        cout << "\n5. Huy nhan vien cuoi cung";
        cout << "\n6. Tim nhan vien co muc luong cao nhat";
        cout << "\n7. Nhan vien co muc luong > 2000000";
        cout << "\n8. Sap xep thu tu tang dan MaNV";
        cout << "\n9. Ghi file danh sach";
        cout << "\n10.Doc file danh sach";
        cout << "\n0. Thoat chuong trinh";
        cout << "\nMoi ban chon: "; cin >> chon;
        switch(chon)
        {
            case 1:
                cout << "\nNhap so luong nhan vien: "; cin >> n;
                KhoiTaoRong(DQ);
                NhapDS(DQ, n);
                break;
            case 2:
                cout << "\n\t\t DANH SACH NHAN VIEN\n";
                XuatDS(DQ);
                break;
            case 3:
                ThemDau(DQ, n);
                cout << "\n\t\tDANH SACH SAU KHI THEM\n";
                XuatDS(DQ);
                break;
            case 4:
                TongLuongAll(DQ);
                break;
            case 5:
                HuyNVCuoi(DQ);
                break;
            case 6:
                Max(DQ);
                NVLuongMax(DQ);
                break;
            case 7:
                cout << "\n\tDANH SACH NHAN VIEN CO MUC LUONG > 2TR\n";
                TimNV(DQ);
                break;
            case 8:
                SapXep(DQ);
                break;
            case 9:
                GhiFile(f, DQ);
                break;
            case 10:
                DocFile(f, DQ);
                break;
        }
    }
    while(chon!=0);
    return 0;
}
