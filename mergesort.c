#include<stdio.h>
void merge(int a[],int low,int mid,int high)
{
    int c[11];
    int i=low;
    int j=mid+1;
    int k=low;
    while((i<=mid)&&(j<=high))
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
            k++;
            i++;
        }
        else
        {
            c[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        c[k]=a[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++)
        a[i]=c[i];
    int x;

}
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
main()
{
     int a[]={10,40,30,90,50,35,17,80,30,37,79};
    int low=0,x;
    int mid=4;
    int high=10;
    mergesort(a,low,high);
     for(x=0;x<=high;x++)
    {
        printf("%d\t",a[x]);
    }
}
