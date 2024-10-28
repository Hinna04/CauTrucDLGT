//De so 02

#include <bits/stdc++.h>

using namespace std;

struct SanPham{
    string maSP, tenSP, NSX;
    float donGia, thanhTien;
    int soLuong;
};

void nhap(SanPham &s)
{
    cout << "\n Nhap ma san pham: "; cin.ignore(); getline(cin, s.maSP);
    cout << " Nhap ten san pham: "; getline(cin, s.tenSP);
    cout << " Nhap nha san suat: "; getline(cin, s.NSX);
    cout << " Nhap don gia: "; cin >> s.donGia;
    cout << " Nhap so luong: "; cin >> s.soLuong;
    s.thanhTien = s.soLuong*s.donGia;
}

void xuat(SanPham s)
{
    cout << "\n" << setw(5) << s.maSP
         << setw(20) << s.tenSP
         << setw(20) << s.NSX
         << setw(15) << s.donGia
         << setw(15) << s.soLuong
         << setw(15) << s.thanhTien << "\n";
}

void nhapDSSP(int &n, SanPham ds[])
{
    int i;
    cout << "\n Nhap so luong san pham: "; cin >> n;
    for(i = 0; i < n; i++)
        nhap(ds[i]);
}

void xuatDSSP(int n, SanPham ds[])
{
    int i;
    cout << "\n DANH SACH SAN PHAM \n";
    cout << setw(6) << " \n MaSP ";
    cout << setw(20) << " Ten SP";
    cout << setw(22) << " Nha San Xuat ";
    cout << setw(15) << " Don Gia ";
    cout << setw(15) << " So Luong ";
    cout << setw(15) << " Thanh Tien" << "\n";
    for(i = 0; i < n; i++)
        xuat(ds[i]);
}

void trungBinhCong(SanPham ds[], int &n)
{
	int dem = 0, i, sum = 0;
	float tbc;
	string x;
	cout << "\n Nhap ten nha san xuat: "; cin.ignore(); getline(cin, x);
	for(i = 0; i < n; i++){
		if(ds[i].NSX == x){
            sum+=ds[i].soLuong;
            dem++;
        }
	}
	if(dem!=0)
        tbc = (float)sum/dem;
	cout << " Gia tri TBC so luong SP co NSX: " << tbc << endl;
}

void sapXepChon(int n, SanPham ds[])
{
    int min, i, j;
    SanPham tg;
    for(i = 0; i < n - 1; i++)
    {
        min = i;    //tim vi tri cua gia tri nho nhat
        for(j = i + 1; j < n; j++)
            if(ds[j].thanhTien < ds[min].thanhTien)
                min = j;
        if(min!=i)
        {
            tg = ds[min];
            ds[min] = ds[i];
            ds[i] = tg;
        }
    }
    cout << "\n DANH SACH SAN PHAM SAU KHI SAP XEP \n";
    cout << setw(6) << " \n MaSP ";
    cout << setw(210) << " TenSP";
    cout << setw(22) << " Nha San Xuat ";
    cout << setw(15) << " Don Gia ";
    cout << setw(15) << " So Luong ";
    cout << setw(15) << " Thanh Tien " << "\n";
    for(i = 0; i < n; i++)
        xuat(ds[i]);
}

int main()
{
    int n;
    SanPham ds[50];
    nhapDSSP(n, ds);
    xuatDSSP(n, ds);
    trungBinhCong(ds, n);
    sapXepChon(n, ds);
}
