#include <bits/stdc++.h>
#define max 100
using namespace std;
typedef string kytu;
typedef struct Node
{
    int id;
    Node *next;
};
typedef struct PhanTu
{
    kytu info;
    Node *ptcon;
};
typedef struct Tree
{
    PhanTu elems[max];
    int size;
} Tree;
void nhap(Tree &T)
{
    int n, i;
    cout << " Nhap so luong đinh: "; cin >> n;
    T.size = n;
    cout << "\n Nhap danh sach cac dinh:\n";
    for(i = 1; i <= n; i++)
    {
        cout << " Dinh thu " << i << ": "; cin.ignore(); getline(cin, &T.elems[i].info);
        T.elems[i].ptcon = (Node *) malloc (sizeof(Node));
        T.elems[i].ptcon->next = NULL;
        T.elems[i].ptcon->id = i;
    }
}
void chen_ptcon(Node *ptcon, int i)
{
    Node *p, *q;
    p = (Node *) malloc (sizeof(Node));
    p->id = i;
    p->next = NULL;
    if(ptcon->next == NULL)
        ptcon->next = p;
    else
    {
        q = ptcon->next;
        while(q->next != NULL)
            q = q->next;
        q->next = p;
    }
}
void nhapPTCon(Node *ptcon)
{
    int i, k = 0;
    do
    {
        cout << "\n Nhap chi so con thu " << k + 1 << ": "; fflush(stdin); cin >> &i;
        if(i != 0)
        {
            chen_ptcon(ptcon, i);
            k++;
        }
    }
    while (i != 0);
}
void taoCay(Tree &T)
{
    int i;
    nhap(T);
    for(i = 1; i <= T.size; i++)
    {
        cout << "\n Nhap cac con cua dinh thu " << i; cin >> T.elems[i].info;
        fflush(stdin);
        nhapPTCon(T.elems[i].ptcon);
    }
}
void dsptcon(Node *ptcon)
{
    Node *q = ptcon->next;
    while(q != NULL)
    {
        cout << q->id;
        q = q->next;
    }
    cout << "\n";
}
void display(Tree T)
{
    int i;
    for(i = 1; i <= T.size; i++)
    {
        cout << "\n Dinh thu " << i << T.elems[i].info;
        dsptcon(T.elems[i].ptcon);
    }
}
// Dem so nut tren cay
void dem_pt(Node *Root, int dem)
{
    if(Root != NULL)
    {
        dem++;
        dem_pt(Root->Left, dem);
        dem_pt(Root->Right, dem);
    }
}
void demPT(Tree T)
{
    int dem = 0;
    dem_pt(T.Root, dem);
    cout << "\n So nut tren cay: " << dem << endl;
}

// Do cao cua cay
void doCaoCay(Node *Root)
{

}

// Duyet thu tu truoc cay tong quat
void NLR(Node *&Root)
{
    if (Root != NULL)
    {
        cout << ' ' << Root->info << ' ';
        NLR(Root->Left);
        NLR(Root->Right);
    }
}
void duyetNLRTQ(Tree T)
{
    NLR(T.Root);
}

// Duyet thu tu giua cay tong quat
void LNR(Node *&Root)
{
    if(Root != NULL)
    {
        LNR(Root->Left);
        cout << ' ' << Root->info << ' ';
        LNR(Root->Right);
    }
}
void duyetLNRTQ(Tree T)
{
    LNR(T.Root);
}

// Duyet thu tu sau cay tong quat
void LRN(Node *&Root)
{
    if(Root != NULL)
    {
        LRN(Root->Left);
        LRN(Root->Right);
        cout << ' ' << Root->info << ' ';
    }
}
void duyetLRNTQ(Tree T)
{
    LRN(T.Root);
}

int main()
{
    int chon;
    Tree T;
    do
    {
        cout << "\n ================ MENU ================";
        cout << "\n 1. Nhap du lieu cho cay";
        cout << "\n 2. Hien thi cay duoi dang dslk";
        cout << "\n 3. Dem so nut tren cay";
        cout << "\n 4. Do cao cua cay va in nut o muc k";
        cout << "\n 5. Bac cao nhat cua cac nut tren cay";
        cout << "\n 6. Cay nhi phan tuong ung";
        cout << "\n 7. Duyet thu tu truoc cay NP tong quat";
        cout << "\n 8. Duyet thu tu giua cay NP tong quat";
        cout << "\n 9. Duyet thu tu sau cay NP tong quat";
        cout << "\n 10.Duyet thu tu truoc cay NP tuong ung";
        cout << "\n 11.Duyet thu tu giua cay NP tuong ung";
        cout << "\n 12.Duyet thu tu sau cay NP tuong ung";
        cout << "\n 0. Thoat chuong trinh";
        cout << "\n Moi ban chon: "; cin >> chon;
        switch(chon)
        {
            case 1:
                taoCay(T);
                display(T);
                break;
            case 2:
                cout << "\n\t ========== CAY TONG QUAT ========== \n";
                display(T);
                break;
            case 3:
                demPT(T);
                break;
            case 4:
                doCaoCay(T);

                break;
            case 6:
                cout << "\n\t ======= CAY NHI PHAN TUONG UNG ======= \n";
                hienCayTU(T);
                break;
            case 7:
                cout << "\n\t ==== DUYET THU TU TRUOC NPTQ ====\n";
                duyetNLRTQ(T);
                break;
            case 8:
                cout << "\n\t ==== DUYET THU TU GIUA NPTQ ====\n";
                duyetLNRTQ(T);
                break;
            case 9:
                cout << "\n\t ==== DUYET THU TU SAU NPTQ ====\n";
                duyetLRNTQ(T);
                break;
            case 10:
                cout << "\n\t ==== DUYET THU TU TRUOC NPTU ====\n";
                duyetNLRTU(T);
                break;
            case 11:
                cout << "\n\t ==== DUYET THU TU GIUA NPTU ====\n";
                duyetLNRTU(T);
                break;
            case 12:
                cout << "\n\t ==== DUYET THU TU SAU NPTU ====\n";
                duyetLRNTU(T);
                break;
            case 0:
                exit(0);
                break;
            default:
                cout << "\n Khong hop le! Moi ban nhap lai..." << endl;
                break;
        }
    }
    while(chon != 0);
    return 0;
}
