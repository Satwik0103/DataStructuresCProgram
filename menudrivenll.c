#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
int main()
{
    struct node *ptr;
    struct node*START;
    int t;
    int ch;
    int cha,cha1;
    START=NULL;
    do
    {

            printf("\n\nWelcome to link list\n");
            printf("Enter your choice\n");
            printf("1-Insert Beg\n");
            printf("2-Insert End\n");
            printf("3-Insert After\n");
            printf("4-Delete Beg\n");
            printf("5-Delete End\n");
            printf("6-Delete After\n");
            printf("7-Delete Specific\n");
            printf("8-Traverse\n");
            printf("9-Exit\n");

            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                {
                    printf("Enter element\n");
                    scanf("%d",&cha);
                     InsBeg(&START,cha);
                     Traverse(START);
                     break;
                }
                //break;
            case 2:
                {
                     printf("Enter element");
                    scanf("%d",&cha);
                     InsEnd(&START,cha);
                     Traverse(START);
                     break;
                }

            case 3:
                {
                     printf("Enter element  to insert after the element you want");
                     scanf("%d%d",&cha,&cha1);
                     ptr=search(START,cha1);
                     InsAfter(&ptr,cha);
                     Traverse(START);
                     break;
                }

            case 4:
                {
                    t=DelBeg(&START);
                    printf("Deleted Element is",t);
                    Traverse(START);
                    break;
                }
            case 5:
                {
                     t=DelEnd(&START);
                    printf("Deleted Element is",t);
                    Traverse(START);
                    break;
                }
            case 6:
                {
                    printf("Enter element to delete after\n");
                    scanf("%d",&cha1);
                    ptr=search(START,cha1);
                    t=DelAfter(&ptr);
                    Traverse(START);
                    break;
                }
            case 7:
                {
                    printf("Enter element to delete after\n");
                    scanf("%d",&cha1);
                    t=DelSpecific(&START,cha1);
                    Traverse(START);
                    break;
                }
            default:
                {
                    Traverse(START);
                    break;
                }
            }
     }while(ch>=1&&ch<=8);

}
