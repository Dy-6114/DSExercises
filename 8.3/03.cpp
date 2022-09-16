/*
已知线性表按顺序存储，且每个元素都是不相同的整数型元素，设计把所有奇数移动到所有偶数前边的算法
审题：顺序存储，不要求有序，只要求奇在偶前
*/
/*
基本思想：
    1.肯定是交换类算法。（冒泡，快排）
    2.时间复杂度最优： 快排
*/

#include <stdio.h>

void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void move(int A[], int len)
{
    int low = 0, high = len - 1;
    while (low < high)
    {
        while (low < high && A[high] % 2 == 0)
            high--;
        while (low < high && A[low] % 2 == 1)
            low++;
        if (low < high)
        {
            swap(A[low], A[high]);
            low++;
            high--;
        }
    }
}

int main()
{
    int a[] = {1, 7, 5, 4, 9, 11, 14, 10, 15, 3};
    move(a, 10);
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