#ifndef Stack_H
#define Stack_H

typedef char Item[20];
typedef struct node * PNode;
//定義棧節點：類型
typedef struct node
{
    Item data;
    PNode down;
}Node;

//定義棧：類型
typedef struct stack
{
    PNode top;
    int size;
}Stack;

//構造一個空棧
Stack *InitStack();

//銷毀一個棧
void DestroyStack(Stack *ps);

//把棧清空
void ClearStack(Stack *ps);

//判斷是否為空棧
int IsEmpty(Stack *ps);

//返回棧大小
int GetSize(Stack *ps);

//返回棧頂元素
PNode GetTop(Stack *ps,Item *pitem);

//元素入棧
PNode Push(Stack *ps,Item item);

//元素出棧
PNode Pop(Stack *ps,Item *pitem);

//掃過棧並訪問visit函數
void StackTraverse(Stack *ps,void (*visit)());

#endif

