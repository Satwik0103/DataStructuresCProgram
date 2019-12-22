#include<stdio.h>
void unionarr(int a[], int m,int b[],int n)
{
    int c[m+n];
    int i=0,j=0,k=0;
    while(i<=m&&j<=n)
    {
       if(a[i]==b[j])
        {
            c[k]=a[i];
            i++;
            j++;
            k++;
        }
        if(a[i]<b[j])
        {
            c[k]=a[i];
            k++;
            i++;
        }
        else
        {
            c[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<=m)
    {
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<=n)
    {
        c[k]=b[j];
        k++;
        j++;
    }
    for(i=0;i<m+n;i++)
    {
        printf("%d\t",c[i]);
    }
}
main()
{
    int a[]={12,14,17,69,89};
    int b[]={30,45,56,67,89};
    unionarr(a,4,b,5);
}
