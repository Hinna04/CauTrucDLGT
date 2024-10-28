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
};
Node *sp;
void KhoiTaoRong()
{
    sp = NULL;
}
int KiemTraRong(Node *sp)
{
    if (sp == NULL)
        return 1;
    return 0;
}
int ThemPhanTu(Node *&sp, NhanVien info)
{
    Node *p;
    p = new Node;
    if(p == NULL)
        return 0;
    p->info = info;
    p->next = sp;
    sp = p;
    return 1;
}
int LayPhanTuDau(Node *&sp, NhanVien &x)
{
    Node *p;
    if(sp == NULL)
        return 0;
    else
    {
        x = sp->info;
        p = sp;
        sp = sp->next;
        delete p;
        return 1;
    }
}
int main()
{
    Node *p;
    int c;
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
        cout << "\n9. Luu file danh sach queue";
        cout << "\n10.Doc file danh sach queue";
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
            default:
                cout << "\nNhap sai! Moi ban nhap lai." << endl;
                break;
        }
    }
    while(c != 0);
    return 0;
}
