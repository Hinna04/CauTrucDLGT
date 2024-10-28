typedef struct SinhVien

{

       int MSSV;

       char HoTen[30];

       float DTB;

} SV;

Tạo cấu trúc danh sách liên kết đơn

struct node

{

       SV info;

       node* next;

};

typedef struct node NODE;

struct list

{

       node* pHead;

       node* pTail;

};

typedef struct list LIST;

1. Các thao tác cơ bản trên danh sách liên kết đơn

Khởi tạo danh sách liên kết đơn

void init(list& l)

{

       l.pHead = NULL;

       l.pTail = NULL;

}

Tạo node mới

node* makenode(SV s)

{

       node* p = new node;

       if (p == NULL)

       {

             cout << “\nKhong du bo nho.”;

             return NULL;

       }

       p->info.MSSV = s.MSSV;

       strcpy_s(p->info.HoTen, s.HoTen);

       p->info.DTB = s.DTB;

       p->next = NULL;

       return p;

}

Thêm node vào đầu danh sách

void AddFirst(list& l, node* p)

{

       if (l.pHead == NULL)

             l.pHead = l.pTail = p;

       else

       {

             p->next = l.pHead;

             l.pHead = p;

       }

}

//Thêm node vào cuối danh sách

void AddLast(list& l, node* p)

{

       if (l.pHead == NULL)

             l.pHead = l.pTail = p;

       else

       {

             l.pTail->next = p;

             l.pTail = p;

       }

}

Xóa node đầu danh sách

void RemoveFirst(list& l)

{

       node* p = l.pHead;

       if (l.pHead == NULL)

             cout << “\nDanh sach rong.”;

       else

       {

             l.pHead = p->next;

             delete p;

       }

}

Xóa node cuối danh sách

void RemoveLast(list& l)

{

       node* p = l.pHead;

       node* r = new node;

       if (l.pHead == NULL)

             cout << “\nDanh sach rong”;

       else

       {

             while (p != l.pTail)

             {

                    r = p;

                    p = p->next;

             }

             l.pTail = r;

             r->next = NULL;

             delete p;

       }

}

2. Nhập, xuất danh sách sinh viên

Hàm nhập thông tin của một sinh viên

void Nhap(SV& s)

{

       cout << “Ma so sinh vien: “;

       cin >> s.MSSV;

       while (getchar() != ‘\n’);

       cout << “Ho va ten: “;

       gets_s(s.HoTen);

       cout << “Diem trung binh: “;

       cin >> s.DTB;

}

Hàm nhập danh sách sinh viên

void InputList(list& l)

{

       int n;

       SV s;

       do

       {

             cout << “\nNhap so luong sinh vien: “;

             cin >> n;

             if (n <= 0)

                    cout << “So luong sinh vien phai lon hon 0. Vui long nhap lai.”;

       } while (n <= 0);

       for (int i = 1; i <= n; i++)

       {

             node* p;

             cout << “\nNhap thong tin sinh vien thu ” << i << endl;

             Nhap(s);

             p = makenode(s);

             AddLast(l, p);

       }

}

Hàm xuất thông tin của một sinh viên

void Xuat(SV s)

{

       cout << s.MSSV << “\t” << s.HoTen << “\t\t” << s.DTB << endl;

}

Hàm xuất danh sách sinh viên
*/
void OutputList(list l)

{

       cout << endl << “MSSV\tHo va ten\tDiem trung binh” << endl;

       for (node* i = l.pHead; i != NULL; i = i->next)

             Xuat(i->info);

}

3. Tìm kiếm sinh viên theo MSSV

void TimKiem(list l)

{

       int x;

       cout << “\nNhap MSSV can tim: “;

       cin >> x;

       for (node* i = l.pHead; i != NULL; i = i->next)

       {

             if (i->info.MSSV == x)

             {

                    cout << endl << “MSSV\tHo va ten\t\tDiem trung binh” << endl;

                    Xuat(i->info);

                    return;

             }

       }

       cout << “Khong ton tai sinh vien co MSSV ” << x << endl;

}

4. Thêm sinh viên vào danh sách đã sắp xếp

void Them(list& l)

{

       node* p, * r, * q;

       SV x;

       cout << “Nhap thong tin sinh vien can them:\n”;

       Nhap(x);

       cout << “\nThem thanh cong.\n”;

       p = makenode(x);

       if (l.pHead->info.MSSV > x.MSSV)

       {

             AddFirst(l, p);

             OutputList(l);

             return;

       }

       if (l.pTail->info.MSSV < x.MSSV)

       {

             AddLast(l, p);

             OutputList(l);

             return;

       }

       r = l.pHead;

       q = l.pHead->next;

       while (q != NULL)

       {

             if (q->info.MSSV < x.MSSV)

             {

                    r = q;

                    q = q->next;

             }

             else

             {

                    r->next = p;

                    p->next = q;

                    OutputList(l);

                    return;

             }

       }

}

5. Xóa sinh viên khỏi danh sách theo MSSV

void Xoa(list& l)

{

       int x;

       cout << “\nNhap MSSV can xoa: “;

       cin >> x;

       if (l.pHead == NULL)

       {

             cout << “\nDanh sach rong.”;

             return;

       }

       if (l.pHead->info.MSSV == x)

       {

             cout << “Xoa thanh cong.\n”;

             RemoveFirst(l);

             OutputList(l);

             return;

       }

       if (l.pTail->info.MSSV == x)

       {

             cout << “Xoa thanh cong.\n”;

             RemoveLast(l);

             OutputList(l);

             return;

       }

       node* q = l.pHead->next;

       node* r = l.pHead;

       while (q != NULL)

       {

             if (q->info.MSSV == x)

             {

                    r->next = q->next;

                    delete q;

                    cout << “Xoa thanh cong.\n”;

                    OutputList(l);

                    return;

             }

             r = q;

             q = q->next;

       }

       cout << “Khong ton tai MSSV can xoa.\n”;

}

6. Sắp xếp danh sách sinh viên

Sắp xếp Solection Sort
void SolectionSort(list l)

{

       node* min;

       for (node* i = l.pHead; i != l.pTail; i = i->next)

       {

             min = i;

             for (node* j = i->next; j != NULL; j = j->next)

                    if (j->info.MSSV < min->info.MSSV)

                           min = j;

             swap(i->info, min->info);

       }

}

Sắp xếp Interchange Sort
void InterchangeSort(list l)

{

       for (node* i = l.pHead; i != l.pTail; i = i->next)

             for (node* j = i->next; j != NULL; j = j->next)

                    if (i->info.MSSV > j->info.MSSV)

                           swap(i->info, j->info);

}

Sắp xếp Bubble
void Bubble(list l)

{

       node* pTail2 = l.pTail, * r = l.pHead;

       for (node* i = l.pHead; i != pTail2; pTail2 = r)

             for (node* j = l.pHead; j != pTail2; j = j->next)

             {

                    if (j->info.MSSV > j->next->info.MSSV)

                           swap(j->info, j->next->info);

                    r = j;

             }

}
