/*编写双向冒泡算法，在正反两个方向交替进行扫描，
即第一趟把关键字最大的元素放在序列的最后面，第二趟把关键字最小的元素放在序列的最前面，如此反复进行*/
#include<stdio.h>

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
} //交换元素位置

void BubbleSort(int A[],int n){
    int low=0, high = n-1;
    bool flag = true;
    while(low<high&&flag){
        flag = false; //每趟初始设置flag为false，当不再交换时，程序停止
        for (int i = low; i < high; i++)
        {
            if (A[i] > A[i+1])
            {
                swap(A[i],A[i+1]);
                flag = true;
            }    
        }
        high--;
        for (int i = high; i > low; i--)
        {
            if (A[i] < A[i-1])
            {
                swap(A[i],A[i-1]);
                flag = true;
            }
        }
        low++;
        
    }
}

int main(){
    int a[]={1,7,5,4,9,11,14,10,15,3};
    BubbleSort(a,10);
    for (int i = 0; i < 10; i++)
    {
        if (i==9)
        {
            printf("%d",a[i]);
            break;
        }
        printf("%d,",a[i]);
    }
    return 0;
}
