#include<stdio.h>
void adjust(int a[],int i,int n)
{
    int t,j;
    while(2*i<=n)
    {
        j=2*i;
        if(j+1<=n)
        {
            if(a[j+1]>a[j])
                j=j+1;
        }
        if(a[j]>a[i])
        {
            t=a[j];
            a[j]=a[i];
            a[i]=t;
        }
        else
            break;
        i=j;
    }
}
void maxheapify(int a[],int n)
{
    int i;
    for(i=n/2;i>=1;i--)
    {
        adjust(a,i,n);
    }
}
void heapsort(int a[],int n)
{
    int t,i,j;
    maxheapify(a,n);
    for(j=n;j>=2;j--)
    {
        t=a[1];
        a[1]=a[j];
        a[j]=t;
    adjust(a,1,j-1);
    }

}
 main()
{
    int a[]={-1,12,56,21,89,34,56};
    int i;
    heapsort(a,6);
    for(i=1;i<=6;i++)
    {
        printf("%d\t",a[i]);
    }
}
