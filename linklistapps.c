//1-SWAP Pairwise elements
#include<stdio.h>
#include"linklist.h"
#include"stacks.h"
void SwapPairwise(struct node**START)
{
    struct node*p,*q;
    p=*START;
    q=NULL;
    int i=1,t;
    while(p!=NULL)
    {
        if(i%2==0)
        {
            t=p->info;
            p->info=q->info;
            q->info=t;
        }
        q=p;
        p=p->next;
        i++;
    }
}
void RevTraverse(struct node*START)
{
    if(START!=NULL)
        Traverse(START->next);
    printf("%d",START->info);
}
int main()
{

    struct node *ptr;
    struct node*START;
    int t;
    int ch;
  //  char cha,cha1;
    START=NULL;
    InsBeg(&START,70);
    InsBeg(&START,60);
    InsBeg(&START,50);
    InsBeg(&START,40);
    InsBeg(&START,20);
    InsBeg(&START,10);
    InsEnd(&START,80);
    InsEnd(&START,90);
    InsEnd(&START,100);
    InsEnd(&START,110);
    InsEnd(&START,125);
    ptr=search(START,20);
    InsAfter(&ptr,35);
    Traverse(START);
    printf("\n\n");
    //SwapPairwise(&START);
    RevTraverse(&START);
    Traverse(START);
    return 0;
}
