/*
��д��������������ķǵݹ��㷨
*/
/*
�㷨˼�룺
    1.���Ÿ������ӣ�������ջ��ֱ������Ϊ�ա�
    2.��ջ��Ԫ�أ������Һ��Ӳ�����δ�����ʹ�����������תִ��1����Ϊ�գ�ջ��Ԫ�س�ջ�����ʡ�
    ע�⣺�ڵڶ����У�������巵��ʱ�����������صĻ��Ǵ����������صģ�����趨һ������ָ��r��ָ��������ʵĽ�㡣
    Ҳ���ڽ��������һ����־�򣬼�¼�Ƿ��ѱ����ʡ�
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


//��������ǵݹ�
void PostOrder2(BiTree T){
    SqStack S;
    InitStack(S);
    BiTNode* p = T;
    BiTNode* r=NULL;
    while (p || !StackEmpty(S))
    {
        if(p){//�ߵ������
            Push(S,p);
            p=p->lchild;
        }
        else{//����
            GetPop(S,p); //��ջ��Ԫ��
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

//����Ϊ�������������ķǵݹ��㷨 ��Ϊ�Ƚ�
//��������ǵݹ�
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

//��������ǵݹ�
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