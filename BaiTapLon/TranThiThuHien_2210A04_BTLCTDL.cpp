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
}
void hienS(Sach x)
{
    NodeS *p;
    cout << setw(8)  << left  << x.maSach
         << setw(24) << left  << x.tenSach
         << setw(20) << left  << x.tenTacGia
         << setw(15) << left  << x.theLoai
         << setw(10) << right << x.soLuong
         << setw(10) << right << x.donG << endl;
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
	else
        cout << "\nDanh sach rong. Khong xoa duoc!" << endl;
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
void tieuDe(ListS S)
{
    cout << endl << setw(8)  << left  << "MaSach"
                 << setw(24) << left  << "TenSach"
                 << setw(20) << left  << "TenTacGia"
                 << setw(15) << left  << "TheLoai"
                 << setw(10) << right << "SoLuong"
                 << setw(10) << right << "DonGia" << endl;
    cout << setfill('-');
    cout << setw(87) << "-" << endl;
    cout << setfill(' ');
}
void hienDSS(ListS S)
{
    Sach x;
    NodeS *p = new NodeS;
    tieuDe(S);
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
    tieuDe(S);
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
    cout << "\n\t\t\t\t DANH SACH SAU KHI THEM\n";
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
    cout << "\n\t\t\t DANH SACH SACH SAU KHI SAP XEP\n";
    hienDSS(S);
}
void xoaSachCuoi(ListS &S)
{
    NodeS *p;
    for(p = S.Head; p != NULL; p = p->next)
    {
        p = new NodeS;
        xoacuoi(S);
    }
    cout << "\n\t\t\t\tDANH SACH SACH SAU KHI XOA\n";
    hienDSS(S);
}
void timKiemTheoMaS(ListS S)
{
	int maS;
	NodeS *p;
	cout << "\nNhap ma sach can tim: "; cin >> maS;
	tieuDe(S);
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
//DOC - GHI FILE SACH
int soLuongSach(ListS &S)
{
    int sl;
    NodeS *p;
    for(p = S.Head; p != NULL; p = p->next)
    {
        sl= sl+1;
    }
    return sl;
}
FILE *f;
void luuFileS(ListS &S)
{
    NodeS *p = S.Head;
    ofstream fileout;
    Sach x;
    fileout.open("Sach.txt", ios::out);
    int sl = soLuongSach(S);
    fileout << sl << endl;
    while (p != NULL)
    {
        x = p->info;
        fileout << x.maSach << "\n"
                << x.tenSach << "\n"
                << x.tenTacGia << "\n"
                << x.donG << "\n"
                << x.soLuong << "\n"
                << x.theLoai << endl;
        p = p->next;
    }
    cout << "\nLuu file Sach thanh cong!" << endl;
    fileout.close();
}
void docFileS(ListS &S)
{
    int i, sl = 0;
    KhoiTaoSach(S);
    NodeS *p;
    ifstream filein;
    filein.open("Sach.txt", ios::in);
    filein >> sl;
    for(i = 0; i < sl; i++)
    {
        Sach x;
        filein >> x.maSach;
        filein.ignore();
        getline(filein, x.tenSach);
        getline(filein, x.tenTacGia);
        filein >> x.donG;
        filein >> x.soLuong;
        filein.ignore();
        getline(filein, x.theLoai);
        p = Get_node(x);
        chendau(S, p);
    }
    cout << "\nDoc file Sach!" << endl;
    hienDSS(S);
    filein.close();
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
void deMuc(ListKH K)
{
    cout << endl << setw(6)  << left  << "MaKH"
                 << setw(6)  << left  << "MaHD"
                 << setw(20) << left  << "TenKH"
                 << setw(12) << left  << "GioiTinh"
                 << setw(16) << left  << "DiaChi"
                 << setw(10) << right << "SDT" << endl;
    cout << setfill('-');
    cout << setw(70) << "-" << endl;
    cout << setfill(' ');
}
void hienDSKH(ListKH K)
{
    NodeKH *p = new NodeKH;
    deMuc(K);
    for(p = K.Head; p != NULL; p = p->next)
    {
        hienKH(p->info);
    }
}
int soLuongKH(ListKH &K)
{
    int sol;
    NodeKH *p;
    for(p = K.Head; p != NULL; p = p->next)
    {
        sol= sol + 1;
    }
    return sol;
}
void luuFileKH(ListKH &K)
{
    NodeKH *p = K.Head;
    ofstream fileout;
    KhachHang y;
    fileout.open("KhachHang.txt", ios::out);
    int sol = soLuongKH(K);
    fileout << sol << endl;
    while (p != NULL)
    {
        y = p->info;
        fileout << y.maKH << "\n"
                << y.maHD << "\n"
                << y.tenKH << "\n"
                << y.gioiTinh << "\n"
                << y.diaChi << "\n"
                << y.sdt << endl;
        p = p->next;
    }
    cout << "\nLuu file Khach Hang thanh cong!" << endl;
    fileout.close();
}
void docFileKH(ListKH &K)
{
    int i, sl = 0;
    KhoiTaoKH(K);
    NodeKH *p;
    ifstream filein;
    filein.open("KhachHang.txt", ios::in);
    filein >> sl;
    for(i = 0; i < sl; i++)
    {
        KhachHang y;
        filein >> y.maKH;
        filein >> y.maHD;
        filein.ignore();
        getline(filein, y.tenKH);
        getline(filein, y.gioiTinh);
        getline(filein, y.diaChi);
        filein >> y.sdt;
        p = Get_node(y);
        chenDau(K, p);
    }
    cout << "\nDoc file Khach Hang!" << endl;
    hienDSKH(K);
    filein.close();
}

// HOA DON
typedef struct HoaDon
{
    int maHD;
	string tenSach;
	int soL;
	float donG;
	float thanhTien;
	float giamGia;
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
    cout << "\nNhap ma hoa don: "; cin >> z.maHD;
    cout << "Nhap ten sach: "; cin.ignore(); getline(cin, z.tenSach);
    cout << "Nhap so luong sach khach hang mua: "; cin >> z.soL;
    cout << "Nhap don gia: "; cin >> z.donG;
    z.thanhTien = z.soL * z.donG;
}
void hienHD(HoaDon z)
{
    cout << setw(6)  << left  << z.maHD
         << setw(24) << left  << z.tenSach
         << setw(10) << right << z.soL
         << setw(10) << right << z.donG
         << setw(15) << right << z.thanhTien
         << setw(15) << right << z.giamGia << endl;
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
			H.Head = NULL;
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
void demuc(ListHD H)
{
    cout << endl << setw(6)  << left  << "MaHD"
                 << setw(24) << left  << "TenSach"
                 << setw(10) << right << "SoLuong"
                 << setw(10) << right << "DonGia"
                 << setw(15) << right << "ThanhTien"
                 << setw(15) << right << "GiamGia" << endl;
    cout << setfill('-');
    cout << setw(80) << "-" << endl;
    cout << setfill(' ');
}
void hienDSHD(ListHD H)
{
    HoaDon z;
    NodeHD *p = new NodeHD;
    demuc(H);
    for(p = H.Head; p != NULL; p = p->next)
    {
        hienHD(p->info);
    }
}
void thanhTLonHonx(ListHD H)
{
    HoaDon z;
    NodeHD *p;
    float ttien;
    cout << "\nNhap thanh tien x: "; cin >> ttien;
    cout << "\n\t\t DANH SACH THANH TIEN LON HON " << ttien << endl;
    demuc(H);
    for(p = H.Head; p != NULL; p = p->next)
    {
		if(p->info.thanhTien > ttien)
			hienHD(p->info);
	}
}
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
        cout << "\nHoa don khong ton tai!" << endl;
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
            if(p->info.thanhTien > q->info.thanhTien)
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
void timKiemThanhTien(ListHD H)
{
    NodeHD *p;
	float x;
	cout << "\nNhap thanh tien x: "; cin >> x;
	cout << "\n\t\tThong tin hoa don co thanh tien bang " << x << endl;
	demuc(H);
	for(p = H.Head; p != NULL; p = p->next)
    {
		if(p->info.thanhTien == x)
			hienHD(p->info);
	}
}
void thanhTienMax(ListHD H)
{
    NodeHD *p;
    float max = 0;
    for(p = H.Head; p != NULL; p = p->next)
	{
		if(max < p->info.thanhTien)
		{
			max = p->info.thanhTien;
		}
	}
	cout << "\nMa hoa don co thanh tien lon nhat: ";
    for(p = H.Head; p != NULL; p = p->next)
    {
        if(max == p->info.thanhTien)
        {
            cout << p->info.maHD;
        }
    }
    cout << endl;
}
void tongTienCacHD(ListHD H)
{
    NodeHD *p;
    float sum = 0;
    for(p = H.Head; p != NULL; p = p->next)
    {
        sum = sum + p->info.thanhTien;
    }
    cout << "\nTong so tien cua toan bo cac hoa don: " << sum << endl;
}
int soLuongHD(ListHD &H)
{
    int SL;
    NodeHD *p;
    for(p = H.Head; p != NULL; p = p->next)
    {
        SL= SL + 1;
    }
    return SL;
}
void luuFileHD(ListHD &H)
{
    NodeHD *p = H.Head;
    ofstream fileout;
    HoaDon z;
    fileout.open("HoaDon.txt", ios::out);
    int SL = soLuongHD(H);
    fileout << SL << endl;
    while (p != NULL)
    {
        z = p->info;
        fileout << z.maHD << "\n"
                << z.tenSach << "\n"
                << z.soL << "\n"
                << z.donG << "\n"
                << z.thanhTien << endl;
        p = p->next;
    }
    cout << "\nLuu file Hoa Don thanh cong!" << endl;
    fileout.close();
}
void docFileHD(ListHD &H)
{
    int i, SL = 0;
    KhoiTaoHD(H);
    NodeHD *p;
    ifstream filein;
    filein.open("HoaDon.txt", ios::in);
    filein >> SL;
    for(i = 0; i < SL; i++)
    {
        HoaDon z;
        filein >> z.maHD;
        filein.ignore();
        getline(filein, z.tenSach);
        filein >> z.soL;
        filein >> z.donG;
        filein >> z.thanhTien;
        p = Get_node(z);
        chendau(H, p);
    }
    cout << "\nDoc file Hoa Don!" << endl;
    hienDSHD(H);
    filein.close();
}
// bai 1
void giamGia(ListHD H)
{
    float n;
    NodeHD *p;
    cout << "\nNhap vao so phan tram de giam gia: "; cin >> n;
    for(p = H.Head; p != NULL; p = p->next)
    {
        p->info.giamGia = p->info.thanhTien - p->info.thanhTien * (n/100);
        p->info.giamGia = p->info.thanhTien - p->info.giamGia;
    }
    cout << "\n\t\t\t DANH SACH KHI DUOC GIAM GIA " << n << "%\n";
    hienDSHD(H);
}
// bai 2
void luuFileGG(ListHD &H)
{
    float y;
    NodeHD *p;
    cout << "\nNhap so tien duoc giam: "; cin >> y;
    int dem = 0, sol = 0;
    for(p = H.Head; p != NULL; p = p->next)
    {
        if(p->info.giamGia == y)
        {
            dem++;
            sol++;
            if(dem = 1)
            {
                demuc(H);
            }
            hienHD(p->info);
        }
    }
    for(p = H.Head; p != NULL; p = p->next)
    {
        if(p->info.giamGia == y)
        {
            ofstream fileout;
            HoaDon z;
            fileout.open("GiamGia.txt", ios::out);
            fileout << sol << endl;
            z = p->info;
            fileout << z.maHD << "\n"
                    << z.tenSach << "\n"
                    << z.soL << "\n"
                    << z.donG << "\n"
                    << z.thanhTien << "\n"
                    << z.giamGia << endl;
            fileout.close();
        }
    }
    cout << "\nLuu file giam gia thanh cong!" << endl;
}
void docFileGG(ListHD &H)
{
    int i, sol = 0;
    KhoiTaoHD(H);
    NodeHD *p;
    ifstream filein;
    filein.open("GiamGia.txt", ios::in);
    filein >> sol;
    for(i = 0; i < sol; i++)
    {
        HoaDon z;
        filein >> z.maHD;
        filein.ignore();
        getline(filein, z.tenSach);
        filein >> z.soL;
        filein >> z.donG;
        filein >> z.thanhTien;
        filein >> z.giamGia;
        p = Get_node(z);
        chendau(H, p);
    }
    cout << "\nDoc file hoa don duoc giam gia!" << endl;
    hienDSHD(H);
    filein.close();
}

int main()
{
	int n, a, b, c;
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
                    cout << "\n5. Sap xep theo thu tu tang dan cua ma sach";
                    cout << "\n6. Xoa 1 quyen sach cuoi cung khoi danh sach";
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
                            sapXepS(S);
                            goto menuS;
                        case 6:
                            xoaSachCuoi(S);
                            goto menuS;
                        case 7:
                            timKiemTheoMaS(S);
                            goto menuS;
                        case 8:
                            demSach(S);
                            goto menuS;
                        case 9:
                            luuFileS(S);
                            goto menuS;
                        case 10:
                            docFileS(S);
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
                            luuFileKH(K);
                            goto menuKH;
                        case 4:
                            docFileKH(K);
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
                    cout << "\n5. Xoa 1 hoa don co ma nhap tu ban phim";
                    cout << "\n6. Sap xep thu tu tang dan cua thanh tien";
                    cout << "\n7. Tim hoa don co thanh tien bang x";
                    cout << "\n8. Tim hoa don co thanh tien lon nhat";
                    cout << "\n9. Tong tien cac hoa don da nhap";
                    cout << "\n10.Luu file danh sach";
                    cout << "\n11.Doc file danh sach";
                    cout << "\n12.Danh sach hoa don duoc giam gia";
                    cout << "\n13.Luu file hoa don duoc giam gia";
                    cout << "\n14.Doc file hoa don duoc giam gia";
                    cout << "\n15.Tro lai menu chinh";
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
                        case 3:
                            thanhTLonHonx(H);
                            goto menuHD;
                        case 4:
                            themCuoiHD(H);
                            goto menuHD;
                        case 5:
                            xoaHD(H);
                            goto menuHD;
                        case 6:
                            sapXepHD(H);
                            goto menuHD;
                        case 7:
                            timKiemThanhTien(H);
                            goto menuHD;
                        case 8:
                            thanhTienMax(H);
                            goto menuHD;
                        case 9:
                            tongTienCacHD(H);
                            goto menuHD;
                        case 10:
                            luuFileHD(H);
                            goto menuHD;
                        case 11:
                            docFileHD(H);
                            goto menuHD;
                        case 12:
                            giamGia(H);
                            goto menuHD;
                        case 13:
                            luuFileGG(H);
                            goto menuHD;
                        case 14:
                            docFileGG(H);
                            goto menuHD;
                        case 15:
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
