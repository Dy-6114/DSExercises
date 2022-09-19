/*重新编写快排的划分算法，随机选择一个值作为枢值*/
/*
基本思想：将随机选择的枢值与第一个值进行交换，之后划分算法不变
*/
#include<stdio.h>
#include<stdlib.h>

void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int Partition2(int A[],int low,int high){
    int rand_index = low + rand()%(high-low+1);
    swap(A[low],A[rand_index]);
    int pivot = A[low];  //枢值
    int i = low;  //记录枢值的位置
    for(int j = low+1;j<=high;j++){
        if (A[j]<pivot)
            swap(A[++i],A[j]);    
    }
    swap(A[i],A[low]); 
    return i;
}

void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition2(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}

int main()
{
    int a[] = {1, 7, 5, 4, 9, 11, 14, 10, 15, 3};
    QuickSort(a,0, 9);
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
        {
            printf("%d", a[i]);
            break;
        }
        printf("%d,", a[i]);
    }
    return 0;
}