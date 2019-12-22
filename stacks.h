#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define TRUE 1
#define FALSE 0

struct stack
{
    int TOP;
    char Item[SIZE];
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
void Push(char x)
{
    if(s.TOP==SIZE-1)
        {
        printf("Stack Overflow");
        exit(1);
        }
    s.TOP=s.TOP+1;
    s.Item[s.TOP]=x;
}
char Pop(void)
{
    char x;
    if(Empty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    x=s.Item[s.TOP];
    s.TOP=s.TOP-1;
    return x;
}
char StackTop(void)
{
    char x;
    x=s.Item[s.TOP];
    return x;
}
void reverse(char str[10])
{
//    Initialize();
    int i=0;
    while(str[i]!='\0')
    {
        Push(str[i]);
        i++;
    }
    i=0;
    while(!Empty())
    {
        char x;
        x=Pop();
        str[i]=x;
        i++;
    }
    str[SIZE]='\0';
    //for(i=0;i<6;i++)
    //{
    //printf("%c",str[i]);
    //}
}
/*main()
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

}*/
