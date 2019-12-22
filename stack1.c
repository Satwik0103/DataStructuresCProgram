#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define TRUE 1
#define FALSE 0

struct stack
{
    int TOP;
    int Item[SIZE];
};

struct stack s;

void Initialize(void)
{

    s.TOP=-1;
}

int Empty(void)
{
    if(s.TOP==-1)
        return TRUE;
    else
        return FALSE;
}
void Push(int x)
{
    if(s.TOP==SIZE-1)
        {
        printf("Stack Overflow");
        exit(1);
        }
    s.TOP=s.TOP+1;
    s.Item[s.TOP]=x;
}
int Pop(void)
{
    int x;
    if(Empty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    x=s.Item[s.TOP];
    s.TOP=s.TOP-1;
    return x;
}
main()
{
    int x;
    Initialize();
    Push(100);
    Push(200);
    Push(400);
    Push(600);
    x=Pop();
    printf("Popped element is%d",x);
    x=Pop();
    printf("Popped element is%d",x);
    x=Pop();
    printf("Popped element is%d",x);x=Pop();

}
