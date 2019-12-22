#include<stdio.h>
void bublesort(int ch[]);
void bublesort(int ch[])
{
    int i,j,b;
    for(i=0;i<4;i++)
    {
        for(j=0;j<(5-i);j++)
        {
            if(ch[j]>ch[j+1])
            {
            b=ch[j];
            ch[j]=ch[j+1];
            ch[j+1]=b;
            }
        }
    }
    for(i=0;i<5;i++)
    {
        printf("%d\t",ch[i]);
    }
}
void selectionsort(int ch[]);
void selectionsort(int ch[])
{
    int i,j,b,min;
    for(i=0;i<4;i++)
    {
        min=i;
        for(j=i+1;j<5;j++)
        {
            if(ch[j]<ch[min])
            {
            min=j;
            }
            b=ch[min];
            ch[min]=ch[i];
            ch[i]=b;
        }
    }
    for(i=0;i<=4;i++)
    {
        printf("%d\t",ch[i]);
    }
}
void insertionsort(int ch[])
{
    int i,j,k;
    for(i=2;i<5;i++)
    {
        k=ch[i];
        j=i-1;
        while(j>=1&&ch[j]>k)
        {
            ch[j+1]=ch[j];
            j=j-1;
        }
        ch[j+1]=k;
    }
    for(i=0;i<=4;i++)
    {
        printf("%d\t",ch[i]);
    }
}
main()
{
    int ch[]={10,78,95,56,39};
    insertionsort(ch);
}
