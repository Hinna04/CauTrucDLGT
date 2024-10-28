#include <bits/stdc++.h>

using namespace std;

// SACH
typedef struct Sach
{
    int maSach;
    string tenSach;
    string tenTacGia;
    string theLoai;
    int soLuong;
    float donG;
    float thanhTien;
};
typedef struct NodeS
{
    Sach info;
    struct NodeS *next;
};
typedef struct ListS
{
    NodeS *Head;
    NodeS *Tail;
};
struct ListS S;
void KhoiTaoSach(ListS &S)
{
    S.Head = NULL;
    S.Tail = NULL;
}
int KiemTraRongS(ListS S)
{
    if(S.Head == NULL)
    {
        return 1;
    }
    return 0;
}
NodeS *Get_node(Sach x)
{
    NodeS *p;
    p = new NodeS;
    if (p == NULL)
    {
        cout << "Khong du bo nho.";
        exit(1);
    }
    p->info = x;
    p->next = NULL;
    return p;
}
void nhapS(Sach &x)
{
    cout << "\nNhap ma sach: "; cin >> x.maSach;
    cout << "Nhap ten sach: "; cin.ignore(); getline(cin, x.tenSach);
    cout << "Nhap ten tac gia: "; getline(cin, x.tenTacGia);
    cout << "Nhap the loai: "; getline(cin, x.theLoai);
    cout << "Nhap so luong: "; cin >> x.soLuong;
    cout << "Nhap don gia: "; cin >> x.donG;
    x.thanhTien = x.soLuong * x.donG;
}
void hienS(Sach x)
{
    /*cout << setw(8)  << left  << x.maSach
         << setw(24) << left  << x.tenSach
         << setw(20) << left  << x.tenTacGia
         << setw(15) << left  << x.theLoai
         << setw(10) << right << x.soLuong
         << setw(10) << right << x.donG
         << setw(12) << right << x.thanhTien << endl;*/
    cout << "\nMa sach: " << x.maSach;
    cout << "\nTen sach: " << x.tenSach;
    cout << "\nTen tac gia: " << x.tenTacGia;
    cout << "\nThe loai: " << x.theLoai;
    cout << "\nSo luong: " << x.soLuong;
    cout << "\nDon gia: " << x.donG;
    cout << "\nThanh tien: " << x.thanhTien << endl;
}
void chendau(ListS &S, NodeS *p)
{
    if (S.Head == NULL)
    {
        S.Head = p;
        S.Tail = S.Head;
    }
    else
    {
        p->next = S.Head;
        S.Head = p;
    }
}
void chencuoi(ListS &S, NodeS *p)
{
    if (S.Head == NULL)
    {
        S.Head = p;
        S.Tail = S.Head;
    }
    else
    {
        S.Tail->next = p;
        S.Tail = p;
    }
}
void xoadau(ListS &S)
{
	NodeS *p;
	if(p != NULL)
    {
        p = S.Head;
		S.Head = S.Head->next;
		delete p;
		if(S.Head == NULL)
		{
			S.Tail = NULL;
		}
	}
}
void xoacuoi(ListS &S)
{
	NodeS *p;
	if(p != NULL)
    {
        p = S.Head;
		while(p->next->next != NULL)
        {
			p = p->next;
		}
		delete p->next;
		p->next = NULL;
		S.Tail = p;
		if(S.Tail == NULL)
        {
			S.Head == NULL;
		}
	}
}
void xoanut(ListS &S, int k)
{
	NodeS *p, *q;
	p = Timkiem(S, k, q);
	if(p == NULL)
        cout << "\nKhong tim thay!" << endl;
    if(q != NULL)
    {
        if(p == S.Tail)
        {
            S.Tail = q; q->next = NULL;
        }
        else
		{
			q->next = p->next;
		}
		delete p;
    }
    else
    {
        S.Head = p->next;
        delete p;
        if(S.Head == NULL)
            S.Tail = NULL;
    }
}
void nhapDSS(ListS &S)
{
	int n, i;
	NodeS *p;
	cout << "\nNhap so luong sach: "; cin >> n;
    for(i = 0; i < n; i++)
    {
        Sach x;
        cout << "\nNhap sach thu " << i + 1;
        nhapS(x);
        p = new NodeS;
        p = Get_node(x);
        chencuoi(S, p);
    }
}
void hienDSS(ListS S)
{
    Sach x;
    NodeS *p = new NodeS;
    cout << endl << setw(8)  << left  << "MaSach"
                 << setw(24) << left  << "TenSach"
                 << setw(20) << left  << "TenTacGia"
                 << setw(15) << left  << "TheLoai"
                 << setw(10) << right << "SoLuong"
                 << setw(10) << right << "DonGia"
                 << setw(12) << right << "ThanhTien" << endl;
    cout << setfill('-');
    cout << setw(87) << "-" << endl;
    cout << setfill(' ');
    for(p = S.Head; p != NULL; p = p->next)
    {
        hienS(p->info);
    }
}
void timTheoTheLoai(ListS S)
{
    string TLoai;
	NodeS *p;
	cout << "\nNhap the loai can tim: "; cin.ignore(); getline(cin, TLoai);
	cout << endl << setw(8)  << left  << "MaSach"
                 << setw(24) << left  << "TenSach"
                 << setw(20) << left  << "TenTacGia"
                 << setw(15) << left  << "TheLoai"
                 << setw(10) << right << "SoLuong"
                 << setw(10) << right << "DonGia"
                 << setw(12) << right << "ThanhTien" << endl;
    cout << setfill('-');
    cout << setw(87) << "-" << endl;
    cout << setfill(' ');
	for(p = S.Head; p != NULL; p = p->next)
    {
		if(p->info.theLoai == TLoai)
			hienS(p->info);
	}
}
void themDauS(ListS S)
{
    Sach x;
    nhapS(x);
    NodeS *p;
    p = Get_node(x);
    chendau(S, p);
    cout << "\n\t\t\t\t\tDANH SACH SAU KHI THEM\n";
    hienDSS(S);
}
void xoaSach(ListS S)
{
    NodeS *p;
    Sach x;
    p = Get_node(x);
    xoaDau(S);
    cout << "\n\t\t\t\tDANH SACH SACH SAU KHI XOA\n";
    hienDSS(S);
}
void sapXepS(ListS S)
{
    NodeS *p, *q;
    Sach x;
    p = S.Head;
    while(p != NULL)
    {
        q = p->next;
        while(q != NULL)
        {
            if(p->info.maSach > q->info.maSach)
            {
                x = p->info;
                p->info = q->info;
                q->info = x;
            }
            q = q->next;
        }
        p = p->next;
    }
    cout << "\n\t\t DANH SACH SACH SAU KHI SAP XEP\n";
    hienDSS(S);
}
void timKiemTheoMaS(ListS S)
{
	int maS;
	NodeS *p;
	cout << "\nNhap ma sach can tim: "; cin >> maS;
	cout << endl << setw(8)  << left  << "MaSach"
                 << setw(24) << left  << "TenSach"
                 << setw(20) << left  << "TenTacGia"
                 << setw(15) << left  << "TheLoai"
                 << setw(10) << right << "SoLuong"
                 << setw(10) << right << "DonGia"
                 << setw(12) << right << "ThanhTien" << endl;
    cout << setfill('-');
    cout << setw(87) << "-" << endl;
    cout << setfill(' ');
	for(p = S.Head; p != NULL; p = p->next)
    {
		if(p->info.maSach == maS)
			hienS(p->info);
	}
}
void demSach(ListS S)
{
    Sach x;
    int dem = 0;
    string theloai;
    NodeS *p;
    cout << "\nNhap ten the loai: "; cin.ignore(); getline(cin, theloai);
    for(p = S.Head; p!= NULL; p = p->next)
    {
        if(p->info.theLoai == theloai)
            dem++;
    }
    cout << "\nSo luong sach cung the loai: " << dem << endl;
}
void luuFileS(FILE *f, ListS &S)
{
	f = fopen("Sach.dat", "wb");
	int n = 0;
	NodeS *p;
	for(p = S.Head; p != NULL; p = p->next)
	    n = n + 1;
	fwrite(&n, sizeof(int), 1, f);
	for(p = S.Head; p != NULL; p = p->next)
    {
        fwrite(&p->info, sizeof(Sach), 1, f);
    }
    fclose(f);
    cout << "\nLuu file Sach thanh cong!" << endl;
}
void docFileS(FILE *f, ListS &S)
{
	Sach x;
	int n, i;
	NodeS *p;
	f = fopen("Sach.dat", "rb");
	fread(&n, sizeof(int), 1, f);
	for(i = 0; i < n; i++)
	{
		fread(&x, sizeof(Sach), 1, f);
		p = Get_node(x);
		chendau(S, p);
	}
	fclose(f);
	cout << "\nDoc file Sach." << endl;
	hienDSS(S);
}

// KHACH HANG
typedef struct KhachHang
{
    int maKH;
    string tenKH;
    int sdt;
    string gioiTinh;
    string diaChi;
    int maHD;
};
typedef struct NodeKH
{
    KhachHang info;
    struct NodeKH *next;
};
typedef struct ListKH
{
    NodeKH *Head;
    NodeKH *Tail;
};
struct ListKH K;
void KhoiTaoKH(ListKH &K)
{
    K.Head = NULL;
    K.Tail = NULL;
}
int KiemTraRongKH(ListKH K)
{
    if(K.Head == NULL)
    {
        return 1;
    }
    return 0;
}
NodeKH *Get_node(KhachHang y)
{
    NodeKH *p;
    p = new NodeKH;
    if (p == NULL)
    {
        cout << "Khong du bo nho.";
        exit(1);
    }
    p->info = y;
    p->next = NULL;
    return p;
}
void nhapKH(KhachHang &y)
{
    cout << "\nNhap ma khach hang: "; cin >> y.maKH;
    cout << "Nhap ma hoa don mua: "; cin >> y.maHD;
    cout << "Nhap ten khach hang: "; cin.ignore(); getline(cin, y.tenKH);
    cout << "Nhap gioi tinh: "; getline(cin, y.gioiTinh);
    cout << "Nhap dia chi: "; getline(cin, y.diaChi);
    cout << "Nhap so dien thoai: "; cin >> y.sdt;
}
void hienKH(KhachHang y)
{
    cout << setw(6)  << left  << y.maKH
         << setw(6)  << left  << y.maHD
         << setw(20) << left  << y.tenKH
         << setw(12) << left  << y.gioiTinh
         << setw(16) << left  << y.diaChi
         << setw(9)  << right << setw(1) << "0" << right << y.sdt << endl;
}
void chenDau(ListKH &K, NodeKH *p)
{
    if(K.Head == NULL)
    {
        K.Head = p;
        K.Tail = K.Head;
    }
    else
    {
        p->next = K.Head;
        K.Head = p;
    }
}
void chenCuoi(ListKH &K, NodeKH *p)
{
    if (K.Head == NULL)
    {
        K.Head = p;
        K.Tail = K.Head;
    }
    else
    {
        K.Tail->next = p;
        K.Tail = p;
    }
}
void nhapDSKH(ListKH &K)
{
	int n, i;
	NodeKH *p;
	cout << "\nNhap so luong khach hang: "; cin >> n;
    for(i = 0; i < n; i++)
    {
        KhachHang y;
        cout << "\nNhap khach hang thu " << i + 1;
        nhapKH(y);
        p = new NodeKH;
        p = Get_node(y);
        chenCuoi(K, p);
    }
}
void hienDSKH(ListKH K)
{
    NodeKH *p = new NodeKH;
    cout << endl << setw(6)  << left  << "MaKH"
                 << setw(6)  << left  << "MaHD"
                 << setw(20) << left  << "TenKH"
                 << setw(12) << left  << "GioiTinh"
                 << setw(16) << left  << "DiaChi"
                 << setw(10) << right << "SDT" << endl;
    cout << setfill('-');
    cout << setw(70) << "-" << endl;
    cout << setfill(' ');
    for(p = K.Head; p != NULL; p = p->next)
    {
        hienKH(p->info);
    }
}
void luuFileKH(FILE *f, ListKH &K)
{
	f = fopen("KhachHang.dat", "wb");
	int n = 0;
	NodeKH *p;
	for(p = K.Head; p != NULL; p = p->next)
	    n = n + 1;
	fwrite(&n, sizeof(int), 1, f);
	for(p = K.Head; p != NULL; p = p->next)
    {
        fwrite(&p->info, sizeof(KhachHang), 1, f);
    }
    fclose(f);
    cout << "\nLuu file Khach Hang thanh cong!" << endl;
}
void docFileKH(FILE *f, ListKH &K)
{
	KhachHang y;
	int n, i;
	NodeKH *p;
	f = fopen("KhachHang.dat", "rb");
	fread(&n, sizeof(int), 1, f);
	for(i = 0; i < n; i++)
	{
		fread(&y, sizeof(KhachHang), 1, f);
		p = Get_node(y);
		chenDau(K, p);
	}
	fclose(f);
	cout << "\nDoc file Khach Hang." << endl;
}

// HOA DON
typedef struct HoaDon
{
    int maHD;
	string tenSach;
	Sach S[100];
	int soL;
	float tongTienHD;
};
typedef struct NodeHD
{
    HoaDon info;
    struct NodeHD *next;
};
typedef struct ListHD
{
    NodeHD *Head;
    NodeHD *Tail;
};
struct ListHD H;
void KhoiTaoHD(ListHD &H)
{
    H.Head = NULL;
    H.Tail = NULL;
}
int KiemTraRongHD(ListHD H)
{
    if(H.Head == NULL)
    {
        return 1;
    }
    return 0;
}
NodeHD *Get_node(HoaDon z)
{
    NodeHD *p;
    p = new NodeHD;
    if (p == NULL)
    {
        cout << "Khong du bo nho.";
        exit(1);
    }
    p->info = z;
    p->next = NULL;
    return p;
}
void nhapHD(HoaDon &z)
{
    int i;
    cout << "\nNhap ma hoa don: "; cin >> z.maHD;
    cout << "Nhap so luong sach duoc mua: "; cin >> z.soL;
    for(i = 0; i < z.soL; i++)
    {
        nhapS(z.S[i]);
    }
    z.tongTienHD = 0;
    for(i = 0; i < z.soL; i++)
    {
        z.tongTienHD = z.tongTienHD + z.S[i].thanhTien;
    }
    cout << "\nTong tien hoa don: " << setprecision(0) << fixed << z.tongTienHD << endl;
}
void hienHD(HoaDon z)
{
    int i;
    //cout << setw(6)  << left  << z.maHD;
    cout << "\nMa hoa don: " << z.maHD << endl;
    for(i = 0; i < z.soL; i++)
    {
        hienS(z.S[i]);
    }
    cout << "\nTong tien hoa don: " << z.tongTienHD << endl;
    //cout << setw(15) << right << z.tongTienHD << endl;
}
void chendau(ListHD &H, NodeHD *p)
{
    if(H.Head == NULL)
    {
        H.Head = p;
        H.Tail = H.Head;
    }
    else
    {
        p->next = H.Head;
        H.Head = p;
    }
}
void chencuoi(ListHD &H, NodeHD *p)
{
    if (H.Head == NULL)
    {
        H.Head = p;
        H.Tail = H.Head;
    }
    else
    {
        H.Tail->next = p;
        H.Tail = p;
    }
}
NodeHD *Tim(ListHD H, int s, NodeHD *&q)
{
	NodeHD *p = H.Head;
	q = NULL;
	while((p != NULL) && (p->info.maHD != s))
    {
		q = p;
		p = p->next;
	}
	return p;
}
void xoaDau(ListHD &H)
{
	NodeHD *p;
	if(p != NULL)
    {
        p = H.Head;
		H.Head = H.Head->next;
		delete p;
		if(H.Head == NULL)
		{
			H.Tail = NULL;
		}
	}
}
void xoaCuoi(ListHD &H)
{
	NodeHD *p;
	if(p != NULL)
    {
        p = H.Head;
		while(p->next->next != NULL)
        {
			p = p->next;
		}
		delete p->next;
		p->next = NULL;
		H.Tail = p;
		if(H.Tail == NULL)
        {
			H.Head == NULL;
		}
	}
}
void xoaPT(ListHD &H, int s)
{
	NodeHD *p, *q;
	q = NULL;
	p = Tim(H, s, q);
	if(p != NULL)
    {
		if(p == H.Head)
		{
			xoaDau(H);
		}
		else if(p == H.Tail)
		{
			xoaCuoi(H);
		}
		else
		{
			q->next = p->next;
			delete p;
		}
	}
}
void nhapDSHD(ListHD &H)
{
	int n, i;
	NodeHD *p;
	cout << "\nNhap so luong hoa don: "; cin >> n;
    for(i = 0; i < n; i++)
    {
        HoaDon z;
        cout << "\nNhap hoa don thu " << i + 1;
        nhapHD(z);
        p = new NodeHD;
        p = Get_node(z);
        chencuoi(H, p);
    }
}
void hienDSHD(ListHD H)
{
    HoaDon z;
    int i;
    NodeHD *p = new NodeHD;
    /*cout << endl << setw(6)  << left  << "MaHD"
                 << setw(8)  << left  << "MaSach"
                 << setw(24) << left  << "TenSach"
                 << setw(10) << right << "SoLuong"
                 << setw(10) << right << "DonGia"
                 << setw(12) << right << "ThanhTien"
                 << setw(15) << right << "TongTienHD" << endl;
    cout << setfill('-');
    cout << setw(65) << "-" << endl;
    cout << setfill(' ');*/
    for(p = H.Head; p != NULL; p = p->next)
    {
        hienHD(p->info);
    }
}
/*
void thanhTLonHonx(ListHD H)
{
    HoaDon z;
    NodeHD *p;
    float ttien;
    cout << "\nNhap thanh tien x: "; cin >> ttien;
    cout << "\n\t\t DANH SACH THANH TIEN LON HON " << ttien << endl;
    cout << endl << setw(6)  << left  << "MaHD"
                 << setw(24) << left  << "TenSach"
                 << setw(10) << right << "SoLuong"
                 << setw(10) << right << "DonGia"
                 << setw(15) << right << "ThanhTien" << endl;
    cout << setfill('-');
    cout << setw(65) << "-" << endl;
    cout << setfill(' ');
    for(p = H.Head; p != NULL; p = p->next)
    {
		if(p->info.tongTienHD > ttien)
			hienHD(p->info);
	}
}*/
void themCuoiHD(ListHD H)
{
    HoaDon z;
    nhapHD(z);
    NodeHD *p;
    p = Get_node(z);
    chencuoi(H, p);
    cout << "\n\t\t\tDANH SACH SAU KHI THEM\n";
    hienDSHD(H);
}
void xoaHD(ListHD &H)
{
    int s, dem = 0;
    NodeHD *p, *q;
    cout << "\nNhap ma hoa don can xoa: "; cin >> s;
    for(p = H.Head; p != NULL; p = p->next)
    {
        if(p->info.maHD == s)
        {
            xoaPT(H, s);
            dem++;
        }
    }
    if(dem != 0)
    {
        cout << "\n\t\tDANH SACH HOA DON SAU KHI XOA\n";
        hienDSHD(H);
    }
    else
    {
        cout << "\nKhong co sinh vien nao." << endl;
    }
}
void sapXepHD(ListHD H)
{
    NodeHD *p, *q;
    HoaDon z;
    p = H.Head;
    while(p != NULL)
    {
        q = p->next;
        while(q != NULL)
        {
            if(p->info.tongTienHD > q->info.tongTienHD)
            {
                z = p->info;
                p->info = q->info;
                q->info = z;
            }
            q = q->next;
        }
        p = p->next;
    }
    cout << "\n\t\t DANH SACH SACH SAU KHI SAP XEP\n";
    hienDSHD(H);
}
/*
void timKiemThanhTien(ListHD H)
{
    NodeHD *p;
	float x;
	cout << "\nNhap thanh tien x: "; cin >> x;
	cout << "\n\t\tThong tin hoa don co thanh tien bang " << x << endl;
	cout << endl << setw(6)  << left  << "MaHD"
                 << setw(24) << left  << "TenSach"
                 << setw(10) << right << "SoLuong"
                 << setw(10) << right << "DonGia"
                 << setw(15) << right << "ThanhTien" << endl;
    cout << setfill('-');
    cout << setw(65) << "-" << endl;
    cout << setfill(' ');
	for(p = H.Head; p != NULL; p = p->next)
    {
		if(p->info.tongTienHD == x)
			hienHD(p->info);
	}
}*/
void thanhTienSach(ListHD H)
{
    NodeHD *p;

}
void tongTienCacHD(ListHD H)
{
    NodeHD *p;
    float sum = 0;
    for(p = H.Head; p != NULL; p = p->next)
    {
        sum = sum + p->info.tongTienHD;
    }
    cout << "\nTong so tien cua toan bo cac hoa don: " << sum << endl;
}
void luuFileHD(FILE *f, ListHD &H)
{
	f = fopen("HoaDon.dat", "wb");
	int n = 0;
	NodeHD *p;
	for(p = H.Head; p != NULL; p = p->next)
	    n = n + 1;
	fwrite(&n, sizeof(int), 1, f);
	for(p = H.Head; p != NULL; p = p->next)
    {
        fwrite(&p->info, sizeof(HoaDon), 1, f);
    }
    fclose(f);
    cout << "\nLuu file Hoa Don thanh cong!" << endl;
}
void docFileHD(FILE *f, ListHD &H)
{
	HoaDon z;
	int n, i;
	NodeHD *p;
	f = fopen("HoaDon.dat", "rb");
	fread(&n, sizeof(int), 1, f);
	for(i = 0; i < n; i++)
	{
		fread(&z, sizeof(HoaDon), 1, f);
		p = Get_node(z);
		chendau(H, p);
	}
	fclose(f);
	cout << "\nDoc file Hoa Don." << endl;
	hienDSHD(H);
}

int main()
{
	int n, a, b, c;
    FILE *f;
	MENU:
    {
		cout << "\n========== MENU ==========";
		cout << "\n1. Menu Sach";
		cout << "\n2. Menu Khach Hang";
		cout << "\n3. Menu Hoa Don";
		cout << "\n0. Thoat chuong trinh";
		cout << "\nMoi ban chon: "; cin >> n;
		switch(n)
		{
		    case 1:
                menuS:
                {
                    cout << "\n================= MENU SACH =================";
                    cout << "\n1. Nhap danh sach Sach";
                    cout << "\n2. Hien thi danh sach Sach";
                    cout << "\n3. In ra danh sach Sach theo the loai";
                    cout << "\n4. Them 1 quyen sach vao dau danh sach";
                    cout << "\n5. Xoa 1 quyen sach dau tien khoi danh sach";
                    cout << "\n6. Sap xep theo thu tu tang dan cua ma sach";
                    cout << "\n7. Tim thong tin sach theo ma sach";
                    cout << "\n8. Dem so sach co cung the loai";
                    cout << "\n9. Luu file danh sach";
                    cout << "\n10.Doc file danh sach";
                    cout << "\n11.Tro lai menu chinh";
                    cout << "\n0. Thoat chuong trinh";
                    cout << "\nMoi ban chon: "; cin >> a;
                    switch(a)
                    {
                        case 1:
                            KhoiTaoSach(S);
                            nhapDSS(S);
                            goto menuS;
                        case 2:
                            cout << "\n\t\t\t\t\tDANH SACH SACH\n";
                            hienDSS(S);
                            goto menuS;
                        case 3:
                            timTheoTheLoai(S);
                            goto menuS;
                        case 4:
                            themDauS(S);
                            goto menuS;
                        case 5:
                            xoaSach(S);
                            goto menuS;
                        case 6:
                            sapXepS(S);
                            goto menuS;
                        case 7:
                            timKiemTheoMaS(S);
                            goto menuS;
                        case 8:
                            demSach(S);
                            goto menuS;
                        case 9:
                            luuFileS(f, S);
                            goto menuS;
                        case 10:
                            docFileS(f, S);
                            goto menuS;
                        case 11:
                            cout << endl;
                            goto MENU;
                        case 0:
                            exit(0);
                            goto menuS;
                        default:
                            cout << "\nNhap sai! Moi ban nhap lai!" << endl;
                            goto menuS;
                    }
                }
				goto MENU;
			case 2:
                menuKH:
                {
                    cout << "\n======== MENU KHACH HANG ========";
                    cout << "\n1. Nhap danh sach khach hang";
                    cout << "\n2. Hien thi danh sach khach hang";
                    cout << "\n3. Luu file danh sach";
                    cout << "\n4. Doc file danh sach";
                    cout << "\n5. Tro lai menu chinh";
                    cout << "\n0. Thoat chuong trinh";
                    cout << "\nMoi ban chon: "; cin >> b;
                    switch(b)
                    {
                        case 1:
                            KhoiTaoKH(K);
                            nhapDSKH(K);
                            goto menuKH;
                        case 2:
                            cout << "\n\t\t\t DANH SACH KHACH HANG \n";
                            hienDSKH(K);
                            goto menuKH;
                        case 3:
                            luuFileKH(f, K);
                            goto menuKH;
                        case 4:
                            docFileKH(f, K);
                            goto menuKH;
                        case 5:
                            cout << endl;
                            goto MENU;
                        case 0:
                            exit(0);
                            goto menuKH;
                        default:
                            cout << "\nNhap sai! Moi ban nhap lai!" << endl;
                            goto menuKH;
                    }
                }
				goto MENU;
			case 3:
                menuHD:
                {
                    cout << "\n================ MENU HOA DON ================";
                    cout << "\n1. Nhap danh sach hoa don";
                    cout << "\n2. Hien thi danh sach hoa don";
                    cout << "\n3. Hien thi danh sach co thanh tien lon hon x";
                    cout << "\n4. Them 1 hoa don vao cuoi danh sach";
                    cout << "\n5. Xoa 1 hoa don co ma bat ki khoi danh sach";
                    cout << "\n6. Sap xep thu tu tang dan cua thanh tien";
                    cout << "\n7. Tim hoa don co thanh tien bang x";
                    cout << "\n8. Tinh thanh tien cua sach trong 1 hoa don";
                    cout << "\n9. Tong tien cac hoa don da nhap";
                    cout << "\n10.Luu file danh sach";
                    cout << "\n11.Doc file danh sach";
                    cout << "\n12.Tro lai menu chinh";
                    cout << "\n0. Thoat chuong trinh";
                    cout << "\nMoi ban chon: "; cin >> c;
                    switch(c)
                    {
                        case 1:
                            KhoiTaoHD(H);
                            nhapDSHD(H);
                            goto menuHD;
                        case 2:
                            cout << "\n\t\t\tDANH SACH HOA DON\n";
                            hienDSHD(H);
                            goto menuHD;
                        /*case 3:
                            thanhTLonHonx(H);
                            goto menuHD;*/
                        case 4:
                            themCuoiHD(H);
                            goto menuHD;
                        case 5:
                            xoaHD(H);
                            goto menuHD;
                        case 6:
                            sapXepHD(H);
                            goto menuHD;
                        /*case 7:
                            timKiemThanhTien(H);
                            goto menuHD;*/
                        case 8:
                            thanhTienSach(H);
                            goto menuHD;
                        case 9:
                            tongTienCacHD(H);
                            goto menuHD;
                        case 10:
                            luuFileHD(f, H);
                            goto menuHD;
                        case 11:
                            docFileHD(f, H);
                            goto menuHD;
                        case 12:
                            cout << endl;
                            goto MENU;
                        case 0:
                            exit(0);
                            goto menuHD;
                        default:
                            cout << "\nNhap sai! Moi ban nhap lai!" << endl;
                            goto menuHD;
                    }
                }
                goto MENU;
			case 0:
			    exit(0);
				goto MENU;
            default:
                cout << "\nNhap sai! Moi ban nhap lai!" << endl;
                goto MENU;
		}
	}
	return 0;
}
