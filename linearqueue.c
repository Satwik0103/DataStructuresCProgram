#include<stdio.h>
#include<stdlib.h>
#define SIZE 8
#define TRUE 1
#define FALSE 0
struct queue
{
    int rear;
    int front;
    char item[SIZE];

};
struct queue q;
void Initialize()
{
    q.front=0;
    q.rear=-1;
}
int emptyq(void)
{
    if(q.rear-q.front+1==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
void enqueue(int x)
{
    if(q.rear==SIZE-1)
    {
        printf("Queue Overflow");
        exit(1);
    }
    else
    {
        q.rear=q.rear+1;
        q.item[q.rear]=x;
    }
}
int dequeue()
{
    int x;
    if(emptyq())
    {
        printf("Queue Underflow");
        exit(1);
    }
    else
    {
        x=q.item[q.front];
        q.front=q.front+1;
    }
    return x;
}
void traverse()
{
    int i;
    i=q.front;
    for(i=q.front;i<=q.rear;i++)
    {
        printf("%d\t",q.item[i]);
    }
}
int main()
{
    int x;
    Initialize();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    x=dequeue();
   // printf("\nDeleted element is%d",x);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    x=dequeue();
    //printf("\nDeleted element is%d",x);
    x=dequeue();
    //printf("\nDeleted element is%d",x);
    enqueue(70);
    enqueue(80);
   // enqueue(90);
    traverse();
    return 0;

}
