#include<stdio.h>
#include<stdlib.h>
#define SIZE 8
#define TRUE 1
#define FALSE 0
struct cqueue
{
    int rear;
    int front;
    char item[SIZE];

};
struct cqueue cq;
void Initialize()
{
    cq.front=SIZE-1;
    cq.rear=SIZE-1;
}
int emptyq(void)
{
    if(cq.rear==cq.front)
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
    if((cq.rear+1)%SIZE==cq.front)
    {
        printf("Queue Overflow");
        exit(1);
    }
    else
    {
        cq.rear=(cq.rear+1)%SIZE;
        cq.item[cq.rear]=x;
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

        cq.front=(cq.front+1)%SIZE;
        x=cq.item[cq.front];
    }
    return x;
}
void traverse()
{
    int i;
    i=(cq.front+1)%SIZE;
   while (i%SIZE!=cq.rear)
   {
       printf("%d\t",cq.item[i]);
       i++;
   }
   printf("%d\t",cq.item[i%SIZE]);
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
   // printf("\nDeleted element is%d",x);
    x=dequeue();
   // printf("\nDeleted element is%d",x);
    enqueue(70);
    enqueue(80);
    //enqueue(90);
    enqueue(100);
    x=dequeue();
    traverse();
    return 0;
}
