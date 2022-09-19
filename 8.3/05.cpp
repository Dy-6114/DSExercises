/*编写算法，使之能够从L[1..n]中找出第k小的元素（即从小到大排序后处于第k个位置的元素）*/
/*
分析：
    方法一：先进行排序，然后取出第k个元素。时间复杂度在nlog2n以上
    方法二：利用小根堆，输出第k个元素，时间复杂度为n+klog2n
    方法三：基于快排。一趟排序过后讨论A[m]=pivot中m与k的大小，从而判断k落在那个划分中
            在递归查找k，时间复杂度可以达到O(n)
*/
#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= pivot)
            --high; //两个while循环判断条件有等号
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            ++low;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void quicksort(int a[], int low, int high)
{
    while (low < high)
    {
        int i = partition(a, low, high);
        quicksort(a, low, i - 1);
        quicksort(a, i + 1, high);
    }
}

// void heapadjust(int a[], int k, int len){
//     a[0] = a[k];
//     for (int i = 2*k; i < len; i = 2*i)
//     {
//         if(a[i+1] < a[i] && i<len) i++; //i<len保证该结点有右孩子
//         if(a[0]<=a[i]) break; //构建小根堆
//         else{
//             a[0] = a[i];
//             k = i;
//         }
//     }
//     a[k] = a[0];

// }

// void buidminheap(int a[],int len){
//     for (int i = len/2; i > 0; i--) //此处没有等于吗，a[0]用来暂时存放元素
//     {
//         heapadjust(a,i,len);
//     }

// }

// void heapsort(int a[],int len){
//     buidminheap(a,len);
//     for (int i = len; i > 1; i--)
//     {
//         int tmp = a[i];
//         a[i] = a[1];
//         a[1] = tmp;
//         heapadjust(a,1,i-1);
//     }

// }

int main()
{
    int a[] = {1, 7, 5, 4, 9, 11, 14, 10, 15, 3};
    int b[] = {0, 1, 7, 5, 4, 9, 11, 14, 10, 15, 3};
    int c[] = {1, 7, 5, 4, 9, 11, 14, 10, 15, 3};
    quicksort(a, 0, 9);
    printf("算法一：第四个元素为%d\n,", a[3]);
    // heapsort(b,10);
    // printf("算法二：第四个元素为%d\n,", b[3]);
    // printf("算法三：第四个元素为%d\n,", c[3]);
    return 0;
}