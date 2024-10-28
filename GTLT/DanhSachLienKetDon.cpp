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
void chenGiuaDS(List &Q, Node *q, Node *p)       //chen phan tu vao giua ds tai vi tri da biet
{
    if (q != NULL)
    {
        p -> next = q -> next;
        q -> next = p;
        if (q == Q.Tail)
            Q.Tail = p;
    }
}
// xoa ptu p sau ptu q
void xoaSauPTq(ListS &S, NodeS *q)
{
    NodeS *p;
    if(q != NULL)
    {
        p = q->next;
        if(p != NULL)
        {
            if(p == Q.Tail)
            {
                q->next = NULL;
                Q.Tail = q;
            }
            else
                q->next = p->next;
            delete p;
        }
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
// xoa phan tu co khoa k
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
void chenVaoSaux(List Q)
{
    SinhVien x;
    string s;
    cout << "\n NHAP THONG TIN SINH VIEN MOI";
    Nhap();
    cout << "\n Nhap ma sinh vien muon chen sau: "; cin.ignore(); getline(cin, s);
    Node *a = get_node(x);
	Node *q = NULL;
	Node *p = Search(Q, s, q);
	if(a != NULL)
    {
		a->next = p->next;
		p->next = a;
		if(a->next == NULL)
        {
			Q.Tail = a;
		}
	}
    cout << "\n\t DANH SACH SINH VIEN SAU KHI THEM \n";
    xuatDS(Q);
}
void huyCuoi(ListS S)
{
    NodeS *p;
    for(p = S.Head; p != NULL; p = p->next)
    {
        if(p->next == S.Tail)
        {
            delete S.Tail;
            p->next = NULL;
            S.Tail = p;
        }
    }
}
void xoa(List &Q)
{
	int dem = 0;
    Node *p = Q.Head;
    while(p != NULL)
    {
        if(p->info.diemTB < 3.5)
        {
            RemoveAfter(Q, p->info.MaSV);
            dem++;
        }
        p = p->next;
    }
    if(dem != 0)
    {
        cout << "\n\t DANH SACH SINH VIEN SAU KHI XOA \n";
        xuatDS(Q);
    }
    else
    {
        cout << "\n KHONG CO SINH VIEN NAO!\n";
    }
}
void sapXepChon(List Q)
{
    Node *p, *q, *minNode;
    SinhVien tg;
    for(p = Q.Head; p != NULL; p = p->next)
    {
    	minNode = p;
    	for(q = p->next; q != NULL; q = q->next)
    	{
    		if(minNode->info.diemTB > q->info.diemTB)
    		   minNode = q;
		}
		tg = minNode->info;
		minNode->info = p->info;
		p->info = tg;
	}
	xuatDS(Q);
}
void them1svsaux(LIST &Q, SinhVien sv, string s){
	Node *a = newNode(sv);
	Node *q = NULL;
	Node *p = Search(Q, s, q);
	if(a != NULL){
		a->next = p->next;
		p->next = a;
		if(a->next == NULL){
			Q.svTail = a;
		}
	}
}
