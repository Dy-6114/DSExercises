/*
��Ŀ���������������¶��ϣ����Ҷ���Ĳ�α����㷨
ʵ�֣�
    1.�Ѹ���������
    2.��һ��Ԫ�س����У�����ջ���������Ԫ�ء�
    3.���ΰ����Ԫ�ص������Һ�������С�
    4.�����в��գ�������2�������������
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