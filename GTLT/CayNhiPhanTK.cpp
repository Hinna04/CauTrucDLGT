#include <bits/stdc++.h>
/*
typedef struct tagnode
{
	int data;
	struct tagnode *pleft;// nhánh bên trái
	struct tagnode *pright;//nhánh bên phải
}tNode;

typedef struct tagtree
{
	tNode *root;
}TREE;// khai báo 1 cáy (TREE) có kiểu dữ liệu là tNode

void init(TREE &t)
{
	t.root=NULL;
} // khởi tạo cây NULL

tNode *Createnode(int data)
{
	tNode *p;
	p=new tNode;
	if(p!=NULL)
	{
		p->data=data;
		p->pleft=NULL;
		p->pright=NULL;
	}
	return p;
}// hàm tạo 1 node

void insert(tNode *&r,int data)
{

	if(r==NULL)
		r=Createnode(data);
	else
		if(r->data>data)
			insert(r->pleft,data);
		else
			insert(r->pright,data);
}// thêm 1 node vào cây, nếu nhỏ hơn thì bên trái, lớn hơn thì bên phải, dữ liệu là số nguyên data

void insert1(TREE &t,int data)
{
	insert(t.root,data);
}

void print(tNode *r)
{
	if(r==NULL)
		return;

	print(r->pleft);
	printf("%4d",r->data);
	print(r->pright);
}// hàm in danh sách cây

void print(TREE t)
{
	print(t.root);
}// in cả cây nhị phân
void timthemang(tNode *&p,tNode *&q)
{
	if(q->pleft!=NULL)
		timthemang(p,q->pleft);
	else
	{
		p->data=q->data;

		p=q;
		q=q->pright;
	}
}// hàm tìm 1 node trên cây
/*
int del(tNode *&p,int data)
{
	if(p==NULL)
		return 0;
	if(p->data>data)
		del(p->pleft,data);
	if(p->datapright,data);
	if(p->data==data)
	{
		tNode *p1=p;
		if(p->pleft==NULL)
			p=p->pright;
		else
			if(p->pright==NULL)
				p=p->pleft;
			else
			{
		tNode *q=p->pright;
		timthemang(p1,q);
			}
			delete p1;
	}
	return 0;
}// hàm xóa 1 node trên cây

void demnode(tNode *p,int &dem)
{

	if(p==NULL)
		return ;
	demnode(p->pleft,dem);
	dem++;
	demnode(p->pright,dem);


}// hàm đếm node trên cây, với biến dem là tham biến

int demnode1(tNode *t)
{
	if(t==NULL)
		return 0;
	int x=demnode1(t->pleft);
	int y=demnode1(t->pright);
	/* if(r->pleft==NULL&&r->pright==NULL)
	return 1;
	return(x+y);

	return x+y+1;
}//hàm đếm node trên cây, với kêt quả trả về là số lượng node trên cây

void demla(tNode *t,int &dem)
{
	if(t==NULL)
		return;
	if(t->pleft==NULL)
		if(t->pright==NULL)
			dem++;

	demla(t->pleft,dem);

	demla(t->pright,dem);


}// đếm nút là, và nút cuối cùng ở các nhánh

void docaonode(tNode *t,int data,int &dem)
{
	if(t->data>data)
	{
		docaonode(t->pleft,data,dem);

	}
	else
		if(t->datapright,data,dem);

		}
		else
		{

			return;
		}
			dem++;
}// hàm đếm độ cao của cây, tức là nhánh có nhiều nút nhất

//tim kiem
tNode* timnode(tNode *t,int data)
{
	if(t)
	{
		if(t->data==data)
			return t;
		if(t->data>data)
			return timnode(t->pleft,data);
		else
			return timnode(t->pright,data);
	}
	return NULL;

}// hàm tìm kiếm 1 data cho trước, kêt quả null là không tìm thấy, ngược lại sẽ trả về node đó

int tinhchieucaonut(tNode *r)
{
	if(r==NULL)
		return 0;
	if(r->pleft==NULL&&r->pright==NULL)
		return 0;
	int h1=tinhchieucaonut(r->pleft);
	int h2=tinhchieucaonut(r->pright);
	return 1+(h1>h2?h1:h2);
}// tính chiều cao của cây

// hàm chính để gọi các hàm cần chạy
int main()
{

	TREE t;
	init(t);
	int n,data,dem=0;
	printf("nhap so luong");
	scanf("%d",&n);
	for(int i=0;iscanf("%d",&data);
		insert1(t,data);
	}
	printf("Cay :");
	print(t);
	//printf("Nhap phan tu can xoa");
	//scanf("%d",&data);
	//del(t.root,data);
	//*print*/print(t);
	//demnode(t.root,dem);
	//dem=demnode1(t.root);
	printf("\nco tat ca co: %d",dem);
	dem=0;
	demla(t.root,dem);

	printf("\nnut la %d",dem);*/
	dem=0;
	printf("\nNhap phan tu can dem do cao");
	scanf("%d",&data);
	docaonode(t.root,data,dem);
	printf("\ndo cao cua %d la%d",data,dem);
	dem=0;
	//docaocay(t.root,dem);
	dem=tinhchieucaonut(t.root);
	printf("\ndo cao cay %d",dem);


}
#include<iostream>
*/
using namespace std;

struct node
{
    int data;
    struct node *Left;
    struct node *Right;
};
typedef struct node Node;
typedef Node* Tree;


void KhoiTaoCay(Tree &T)
{
    T = NULL;
}


void ThemNodeVaoCay(Tree &T, int x)
{

    if (T == NULL)
    {
        Node *p = new Node;
        p->data = x;
        p->Left = NULL;
        p->Right = NULL;
        T = p;
    }
    else
    {
        if (T->data > x)
        {
            ThemNodeVaoCay(T->Left, x);
        }
        else if (T->data < x)
        {
            ThemNodeVaoCay(T->Right, x);
        }
    }
}

//DUYET TRUOC
void Duyet_NLR(Tree T)
{

    if (T != NULL)
    {
        cout << T->data << " ";
        Duyet_NLR(T->Left);
        Duyet_NLR(T->Right);
    }
}

//DUYET GIUA
void Duyet_LNR(Tree T)
{
    if (T != NULL)
    {
        Duyet_LNR(T->Left);
        cout << T->data << "  ";
        Duyet_LNR(T->Right);
    }
}

//DUYET SAU
void Duyet_LRN(Tree T)
{
    if (T != NULL)
    {
        Duyet_LRN(T->Left);
        Duyet_LRN(T->Right);
        cout << T->data << "  ";
    }
}

//TIM PHAN TU
Node *SearchTree(Tree T, int y)
{
	if(T==NULL)
	{
		return NULL;
	}
	else
	{
	    if(y<T->data)
	    {
		    SearchTree(T->Left, y);
	    }
		else if(y>T->data)
		{
		    SearchTree(T->Right, y);
	    }
	    else
	    {
	    	return T;
		}
	}
}


void Menu(Tree &T)
{
    while (true)
    {
        cout<<"\n =========== MENU ===========";
        cout<<"\n1. Nhap du lieu cho cay: ";
        cout<<"\n2. Duyet cay NLR";
        cout<<"\n3. Duyet cay LNR";
        cout<<"\n4. Duyet cay LRN";
        cout<<"\n0. Thoat";
        cout<<"\n ============================";

        int luachon;
        cout<<"\nNhap lua chon cua ban ";
        cin>>luachon;
        if (luachon<0 || luachon>5)
        {
            cout << "\n Khong hop ly";
        }
        else if (luachon == 1)
        {
            int x;
            cout << "\n Nhap x: ";
            cin >> x;
            ThemNodeVaoCay(T, x);
        }
        else if (luachon == 2)
        {
            cout << "\n Duyet cay theo NLR \n";
            Duyet_NLR(T);
        }
        else if (luachon == 3)
        {
            cout << "\n Duyet cay theo LNR \n";
            Duyet_LNR(T);
        }
        else if (luachon == 4)
        {
            cout << "\n Duyet cay theo LRN \n";
            Duyet_LRN(T);
        }
        else
        {
            break;
        }
    }
}

int main()
{
    Tree T;
    KhoiTaoCay(T);
    Menu(T);
    cout<<"\n";
}
