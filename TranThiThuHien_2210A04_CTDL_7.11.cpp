/*
Input: 30, 10, 20, 50, 40, 45, 25, 15, 60, 55
Output:
- Duyet thu tu truoc NLR: 30  10  20  15  25  50  40  45  60  55
- Duyet thu tu giua LNR: 10  15  20  25  30  40  45  50  55  60
- Duyet thu tu sau LRN: 15  25  20  10  45  40  55  60  50  30
*/

#include <iostream>

using namespace std;

typedef struct Node
{
    int info;
    struct Node *Left;
    struct Node *Right;
};

typedef struct Tree
{
    Node *Root;
};
struct Tree T;

void KhoiTao(Tree &T)
{
    T.Root = NULL;
}

// Xay dung cay nhi phan tim kiem, du lieu la so nguyen x
void insertTree(Node *&Root, int x)
{
    Node *p;
    if(Root == NULL)
    {
        p = new Node;
        p->info = x;
        p->Left = NULL;
        p->Right = NULL;
        Root = p;
    }
    else
        if(Root->info != x)
        {
            if(Root->info < x)
            {
                insertTree(Root->Right, x);      // goi lai chinh ham do: la de quy
            }
            else
                insertTree(Root->Left, x);
        }
}

void Insert(Tree &T, int x)
{
    insertTree(T.Root, x);
}

void hien(Node *Root)
{
    int info;
	if(Root == NULL)
		return;
	hien(Root->Left);
    cout << ' '<< Root->info << ' ';
	hien(Root->Right);
}

void hienCay(Tree T)
{
	hien(T.Root);
}

// Duyet thu tu truoc
void NLR(Node *&Root)
{
    if (Root != NULL)
    {
        cout << ' ' << Root->info << ' ';
        NLR(Root->Left);
        NLR(Root->Right);
    }
}
void duyetNLR(Tree T)
{
    NLR(T.Root);
}

// Duyet thu tu giua
void LNR(Node *&Root)
{
    if(Root != NULL)
    {
        LNR(Root->Left);
        cout << ' ' << Root->info << ' ';
        LNR(Root->Right);
    }
}
void duyetLNR(Tree T)
{
    LNR(T.Root);
}

// Duyet thu tu sau
void LRN(Node *&Root)
{
    if(Root != NULL)
    {
        LRN(Root->Left);
        LRN(Root->Right);
        cout << ' ' << Root->info << ' ';
    }
}
void duyetLRN(Tree T)
{
    LRN(T.Root);
}

// Tim kiem phan tu khoa la 42 vao cay NPTK
Node *SearchTree(Node *&Root, int k)
{
    if(Root == NULL)
        cout << "\n Phan tu khong ton tai." << endl;
    else
        if(Root->info == k)
            return Root;
        else
            if(Root->info < k)
                return SearchTree(Root->Right, k);
            else
                return SearchTree(Root->Left, k);
}

void Search(Tree T)
{
    int k;
    Node *p;
    p = new Node;
    cout << "\n Nhap khoa k: "; cin >> k;
    p = SearchTree(T.Root, k);
}

int main()
{
    int x, chon;
    Tree T;
    KhoiTao(T);
    do
    {
        cout << "\n ========== MENU ==========";
        cout << "\n 1. Nhap du lieu cho cay";
        cout << "\n 2. Hien thi cay nhi phan";
        cout << "\n 3. Duyet thu tu truoc";
        cout << "\n 4. Duyet thu tu giua";
        cout << "\n 5. Duyet thu tu sau";
        cout << "\n 6. Tim phan tu co khoa 42";
        cout << "\n 0. Thoat chuong trinh";
        cout << "\n Moi ban chon: "; cin >> chon;
        switch(chon)
        {
            case 1:
                cout << "\n Nhap x: "; cin >> x;
                Insert(T, x);
                break;
            case 2:
                cout << "\n\t ======= CAY NHI PHAN ======= \n";
                hienCay(T);
                break;
            case 3:
                cout << "\n\t === DUYET THU TU TRUOC ===\n";
                duyetNLR(T);
                break;
            case 4:
                cout << "\n\t ==== DUYET THU TU GIUA ====\n";
                duyetLNR(T);
                break;
            case 5:
                cout << "\n\t ==== DUYET THU TU SAU ====\n";
                duyetLRN(T);
                break;
            case 6:
                Search(T);
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
