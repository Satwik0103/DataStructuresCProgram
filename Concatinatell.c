//1-SWAP Pairwise elements
#include<stdio.h>
#include"linklist.h"
struct node*concatinate(struct node**START1,struct node**START2)
{
    struct node*p;
    if((*START1)==NULL)
        return (*START2);
    else{
        p=START1;
        while((p->next)!=NULL)
        {
            p=p->next;
        }
        p->next=(*START2);
        return (*START1);
        }
}
int main()
{

    struct node *ptr;
    struct node *p;
    struct node*START1;
    struct node*START2;
    int t;
    int ch;
  //  char cha,cha1;
    START1=NULL;
    START2=NULL;
    InsBeg(&START1,70);
    InsBeg(&START1,60);
    InsBeg(&START1,50);
    InsBeg(&START1,40);
    InsBeg(&START1,20);
    InsBeg(&START1,10);
    InsEnd(&START2,80);
    InsEnd(&START2,90);
    InsEnd(&START2,100);
    InsEnd(&START2,110);
    InsEnd(&START2,125);
    ptr=search(START1,20);
    InsAfter(&ptr,35);
    printf("Link list1-\t");
    Traverse(START1);
    printf("\n");
    printf("Link list 2-\t");
    Traverse(START2);
    printf("\n\n");
    p=concatinate(&START1,&START2);
    //SwapPairwise(&START);
    //RevTraverse(&START);
    printf("After concatinate-\t");
    Traverse(START1);
    return 0;
}
