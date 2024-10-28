#include <stdio.h>
#include <stdlib.h>
struct Node
{
    //khai bao thanh phan du lieu co kieu int
    int data;
    //khai bao con tro next co kieu Node de chua dia chi phan tu sau
    Node *next;
    //khai bao con tro prev co kieu Node de chua dia chi phan tu truoc
    Node *prev;
};
typedef struct Node NODE;

struct doulist{
    //thanh phan dau danh sach
    NODE *pHead;
    //thanh phan cuoi danh sach
    NODE *pTail;
};
typedef struct doulist DLIST;

void KhoiTao(DLIST &ds){
    //dat dia chi dau danh sach bang NULL
    ds.pHead = NULL;
    //dat dia chi cuoi danh sach bang NULL
    ds.pTail = NULL;
}

NODE* TaoNode(int x) {
    //tao mot node p moi
    NODE *p;
    p = new NODE;
    //neu p==NULL thi khong du bo nho va ket thuc viec tao node
    if (p==NULL) {
        printf ("KHONG DU BO NHO");
        return NULL;
    }
    //gan thanh phan data = x
    p->data=x;
    //gan con tro next = NULL
    p->next=NULL;
    //gan con tro prev = NULL
    p->prev = NULL;
    //tra ve node p da tao
    return p;
}

void ThemDau(DLIST &ds, NODE *p) {
    //neu danh sach rong thi them vao node dau va cuoi
    if (ds.pHead == NULL){
        ds.pHead = ds.pTail = p;
    }else {
        //dat con tro next cua node can them toi node dau danh sach
        p->next = ds.pHead;
        //dat con tro prev cua node dau ve node p
        ds.pHead->prev = p;
        //gan lai node dau cua danh sach bang node p
        ds.pHead = p;
    }
}
void ThemCuoi(DLIST &ds, NODE*p){
    //kiem tra danh sach rong neu rong thi them vao dau va cuoi
    if (ds.pHead == NULL){
        ds.pHead = ds.pTail = p;
    }else{
        //dat con tro next cua pTail hien tai vao p la node can them cuoi
        ds.pTail->next = p;
        //dat con tro prev cua node p ve phan tu cuoi danh sach
        p->prev = ds.pTail;
        //thay doi lai phan tu cuoi danh sach
        ds.pTail = p;
    }
}
void Nhap(DLIST &ds, int n){
    //duyet N lan
    for(int i = 0; i < n; i++){
        //nhap du lieu la so nguyen int x
        int x;
        printf("Nhap vao so %d: ",i);
        scanf("%d",&x);
        //tao node p
        NODE *p = new NODE;
        //dua du lieu vua nhap vao node p
        p = TaoNode(x);
        //dua node p vao ham them cuoi va truyen vao node p vua tao
        ThemCuoi(ds,p);
    }
}
void Xuat(DLIST ds){
    //khoi tao mot node
    NODE *p = new NODE;
    //duyet tu dau danh sach den cuoi danh sach voi dieu kien p!=NULL
    for(p = ds.pHead; p!= NULL; p=p->next){
        //hien thi du lieu cua tung node
        printf("%d\n",p->data);
    }
}
int main(){
    //khai bao mot danh sach lien ket doi
    DLIST ds;
    //nhap n phan tu
    int n;
    printf("NHAP N: ");
    scanf("%d",&n);
    //khoi tao danh sach
    KhoiTao(ds);
    //goi ham nhap tryuyen vao danh sach va N phan tu
    Nhap(ds,n);
    //goi ham xuat cac du lieu co trong danh sach
    printf("DANH SACH VUA NHAP\n");
    Xuat(ds);
}


/*
addAfter
void ChenGiua(DList &DQ, DNode *q, DNode *new_element)
{
    DNode *p = q->prev;
    if(q != NULL)
    {
        new_element->next = q;
        if(p != NULL)
        {
            new_element->prev = p;
            p->next = new_element;
        }
        q->prev = new_element;
        if(q == DQ.Head)
            DQ.Head = new_element;
    }
}
*/
