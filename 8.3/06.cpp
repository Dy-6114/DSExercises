/*设仅有一个仅由红白蓝三种颜色的条块组成的条块序列，请编写一个时间复杂度为O(n)的算法，使得这些条块按红白蓝的顺序排好*/
/*
分析：
    1.算法的复杂度要求为O(n)，符合条件的排序方法：最好情况下的直接插入，最好情况下的冒泡，其他排序均不满足。
    2.没有任何一个排序算法直接满足要求，则要自行考虑解决方法。
    3.能想到O(n)代表只有一个循环，优先考虑指针操作，双指针一前一后。
*/

#include <stdio.h>
typedef enum
{
    red,
    white,
    blue
} color;

void swap(color &x, color &y)
{
    color tmp;
    tmp = x;
    x = y;
    y = tmp;
}

void flag_arrage(color a[], int n)
{
    int i = 0, k = n - 1, j = 0;
    while (j <= k)
    {
        switch (a[j])
        {
        case red:
            swap(a[i], a[j]);
            j++;
            i++;
            break;
        case blue:
            swap(a[k], a[j]);
            k--;
            break; // j不进行自加，防止蓝蓝交换的情况
        case white:
            j++;
            break;
        }
    }
}

int main(){
    int b;
    color a[]={white,white,blue,red,red,white,red,blue,blue};
    flag_arrage(a,9);
    for (int i = 0; i < 9; i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}