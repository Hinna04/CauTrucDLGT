/*
Thuat toan sap xep:
- Selection Sort: sap xep chon truc tiep
- Insertion Sort: sap xep chen truc tiep
- Bubble Sort: sap xep noi bot
- Quick Sort: sap xep nhanh
*/

#include <bits/stdc++.h>

using namespace std;

void SelectionSort(int a[], int n)      //Sap xep chon truc tiep
{
    int min, i, j, t;
    cout << "\nNhap so phan tu cua mang: ";
    cin >> n;

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
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        if(min != i)
            t = a[min]; a[min] = a[i]; a[i] = t;
    }
    for(i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
}

void InsertionSort(int a[], int n)      //Sap xep chen truc tiep
{
    int pos, i , x;
    cout << "\nNhap so phan tu cua mang: ";
    cin >> n;

    for(i = 1; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    for(i = 1; i < n; i++)
    {
        x = a[i];
        pos = i - 1;
        while((pos >= 0) && (a[pos] > x)) //tim vi tri chen a[i]
        {
            a[pos + 1]=a[pos];
            pos--;
        }
        a[pos + 1] = x;     //chen x vao day
    }
    /*cout << "\nMang sau khi da sap xep: \n";
    for(i = 1; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;*/
}

void BubbleSort(int a[], int n)     //Sap xep noi bot
{
    int i, j, t;
    cout << "\nNhap so phan tu cua mang: ";
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }
    for (i = 0; i <= n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
    cout << "\nMang sau khi da sap xep: \n";
    for(i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
}

void Partition(int A[], int left, int right)    //Sap xep nhanh
{
    // Kiểm tra xem nếu mảng có 1 phần tử thì không cần sắp xếp
    if (left >= right)
        return;

    int pivot = A[(left + right) / 2]; // Chọn phần tử chính giữa dãy làm chốt

    // i là vị trí đầu và j là cuối đoạn
    int i = left, j = right;
    while (i < j)
    {
        while (A[i] < pivot) // Nếu phần tử bên trái nhỏ hơn pivot thì ok, bỏ qua
            i++;
        while (A[j] > pivot) // Nếu phần tử bên phải nhỏ hơn pivot thì ok, bỏ qua
            j--;

        // Sau khi kết thúc hai vòng while ở trên thì chắc chắn
        // vị trí A[i] phải lớn hơn pivot và A[j] phải nhỏ hơn pivot
        // nếu i < j
        if (i <= j)
        {
            if (i < j) // nếu i != j (tức không trùng thì mới cần hoán đổi)
                swap(A[i], A[j]); // Thực hiện đổi chổ ta được A[i] < pivot và A[j] > pivot
            i++;
            j--;
        }
    }

    // Gọi đệ quy sắp xếp dãy bên trái pivot
    Partition(A, left, j);
    // Gọi đệ quy sắp xếp dãy bên phải pivot
    Partition(A, i, right);
}

int main()
{
    int n;
    int a[n];
    SelectionSort(a, n);
    InsertionSort(a, n);
    BubbleSort(a, n);
}
