/*
Viet 1 chuong trinh hoan thien co 2 menu la tim kiem tuyen tinh va tim kiem nhi phan.
*/

#include <bits/stdc++.h>

using namespace std;

int TimKiemTuyenTinh (int a[], int n, int x)
{
    cout << "\nNhap so phan tu cua mang: ";
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;

    cout << "\nNhap x: "; cin >> x;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == x)
            cout << "Da tim thay tai vi tri " << i << endl;
    }
    return -1;
}

int TimKiemNhiPhan(int a[], int n, int x)
{
    cout << "\nNhap so phan tu cua mang: ";
    cin >> n;
    cout << "Nhap day tang dan (hoac giam dan)!\n";

    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;

    cout << "\nNhap x: "; cin >> x;
    int left = 0;
    int right = n - 1;
    int middle;
    do
    {
        middle = (left + right)/2;
        if(x == a[middle])
            break;
        else
            if(x < a[middle])
                right = middle - 1;
            else
                left = middle + 1;
    }
    while(left <= right);
    if(left <= right)
        cout << "Da tim thay tai vi tri " << middle << endl;
    else
        return -1;
}

int main()
{
    int n;
    int a[n];
    int x;
    int chon;
    do
    {
        cout << "\n\t MENU";
        cout << "\n 1. Tim kiem tuyen tinh";
        cout << "\n 2. Tim kiem nhi phan";
        cout << "\n 0. Thoat chuong trinh";
        cout << "\n Moi ban chon: "; cin >> chon;
        switch(chon)
        {
            case 1:
                TimKiemTuyenTinh(a, n, x);
                break;
            case 2:
                TimKiemNhiPhan(a, n, x);
                break;
            case 0:
                exit(0);
            default:
                cout << "Nhap sai! Moi ban nhap lai!" << endl;
                break;
        }
    }
    while(chon != 0);
    return 0;
}
