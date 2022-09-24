/*
题目：给出二叉树自下而上，自右而左的层次遍历算法
实现：
    1.把根结点入队列
    2.把一个元素出队列，并入栈，遍历这个元素。
    3.依次把这个元素的左孩子右孩子入队列。
    4.若队列不空，则跳到2），否则结束。
*/

#include <stdio.h>
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
void InitStack(SqStack &S);
bool StackEmpty(SqStack S);
bool Push(SqStack S, BiTNode *p);
bool Pop(SqStack S, BiTNode *&p);
bool GetPop(SqStack S, BiTNode *&p);
typedef SqQueue;
void InitQueue(SqQueue &Q);
bool QueueEmpty(SqQueue Q);
bool EnQueue(SqQueue &Q, BiTNode *p);
bool DeQueue(SqQueue &Q, BiTNode *&p);
bool GetHead(SqQueue &Q, BiTNode *&p);

void InvetLevel(BiTree bt)
{
    SqStack s;
    SqQueue q;
    BiTNode *p = NULL;
    if (bt != NULL)
    {
        InitQueue(q);
        InitStack(s);
        EnQueue(q, bt);
        while (QueueEmpty(q) == false)
        {
            DeQueue(q, p);
            Push(s, p);
            if (p->lchild)
                EnQueue(q, p->lchild);
            if (p->rchild)
                EnQueue(q, p->rchild);
        }
        while (!StackEmpty(s))
        {
            Pop(s, p);
            visit(p);
        }
    }
}