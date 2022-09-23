/*
编写后序遍历二叉树的非递归算法
*/
/*
算法思想：
    1.沿着根的左孩子，依次入栈，直到左孩子为空。
    2.读栈顶元素：若其右孩子不空且未被访问过，将右子树转执行1；若为空，栈顶元素出栈并访问。
    注意：在第二步中，必须分清返回时是左子树返回的还是从右子树返回的，因此设定一个辅助指针r，指向最近访问的结点。
    也可在结点中增加一个标志域，记录是否已被访问。
*/
#include<stdio.h>
typedef int ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void visit(BiTree T)
{
    printf("%d", T->data);
}

typedef SqStack;
void InitStack(SqStack S);
bool StackEmpty(SqStack S);
void Push(SqStack S, BiTNode* p);
BiTree Pop(SqStack S,BiTNode* p);
BiTree GetPop(SqStack S,BiTNode* p);


//后序遍历非递归
void PostOrder2(BiTree T){
    SqStack S;
    InitStack(S);
    BiTNode* p = T;
    BiTNode* r=NULL;
    while (p || !StackEmpty(S))
    {
        if(p){//走到最左边
            Push(S,p);
            p=p->lchild;
        }
        else{//向右
            GetPop(S,p); //读栈顶元素
            if (p->rchild!=NULL && p->rchild !=r)
            {
                p=p->rchild;
            }
            else{
                Pop(S,p);
                visit(p);
                r = p;
                p = NULL;
            }
            
        }
    }
    

}

//以下为先序和中序遍历的非递归算法 作为比较
//先序遍历非递归
void PreOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTree p = T;
    while (p || !StackEmpty(S))
    {
        if (p)
        {
            visit(p);
            Push(S, p);
            p = p->lchild;
        }
        else
        {
            Pop(S, p);
            p = p->rchild;
        }
    }
}

//中序遍历非递归
void InOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTree p = T;
    while (p || !StackEmpty(S))
    {
        if (p)
        {
            Push(S, p);
            p = p->lchild;
        }
        else
        {
            Pop(S, p);
            visit(p);
            p = p->rchild;
        }
    }
}