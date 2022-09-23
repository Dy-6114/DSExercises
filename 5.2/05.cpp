/*已知一棵二叉树按顺序存储结构进行存储?，设计一个算法，求编号分别为i和j的两个节点的最近的公共祖先节点的值?*/
/*分析：?
    1.任意节点必有公共祖先，最差为根节点?
    2.顺序存储，父节点与子节点的关系，父节点=孩子节点/2
    3.i>j
            若i/2 == j，则i/2是最近的公共祖先
            若i/2 != j，则令i=i/2 递归查找?
      i<j
            若j/2 == i，则j/2是最近的公共祖先
            否则 同3的情况二
*/

#include<stdio.h>

int comm_ancestor(int T[],int i,int j){
    if(T[i]!= -1&&T[j]!=-1){
        while(i!=j){
            if(i>j) i=i/2;
            else j=j/2;
        }
    }
    else
    printf("两个结点中存在空结点\n");
    return T[i];
}

int main(){
    int t[]={-1,1,2,3,-1,4,5,-1,-1,-1,7,9,8,-1,15};
    int a =comm_ancestor(t,10,14);
    printf("公共结点的值为%d",a);
    return 0;
}
