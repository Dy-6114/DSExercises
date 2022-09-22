/*已知由n个正整数构成的集合A，将其划分为两个不相交的子集A1和A2。
元素个数为n1和n2，元素之和为S1和S2，要求算法高效，且满足|n1-n2|最小，|S1-S2|最大*/
/*
分析：
    1.基于快排将集合划分成两个部分。
    2.一次快排后若枢值正好在n/2的位置上，排序完成
    3.若< n/2,则其之前元素均属于A1，之后元素继续进行划分
    4.若> n/2,与3同理
    时间复杂度为O(n)，空间复杂度为O(1)
*/
#include<stdio.h>

int setpartition(int a[], int n)
{
    int pivot, s1 = 0, s2 = 0;
    int low = 0, low0 = 0, high = n - 1, high0 = n - 1, flag = 1, k = n / 2, i;
    while (flag)
    {
        pivot = a[low];
        while (low < high)
        {
            while (low < high && a[high] >= pivot)
                high--;
            a[low] = a[high];
            while (low < high && a[low] <= pivot)
                low++;
            a[high] = a[low];
        }
        a[low] = pivot;
        if (low == k - 1)
        {
            flag = 0;
        }
        else if (low < k - 1)
        {
            low0 = ++low;
            high = high0;
        }
        else{
            low = low0;
            high0 = --high;
        }
    }
    for (i = 0; i < k; i++)
    {
        s1+=a[i];
    }
    for (i = k; i < n; i++)
    {
        s2+=a[i];
    }
    return s2-s1;
}

int main()
{
    int a[] = {1, 7, 5, 4, 9, 11, 14, 10, 15, 3};
    printf("%d\n",setpartition(a, 10));
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