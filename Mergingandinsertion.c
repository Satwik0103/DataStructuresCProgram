/*void MergeArray(int a[],int m,int b[],int n)
{
    int c[m+n];
    int i=0;
    int j=0;
    int k=0;
    while((i<=m)&&(j<=n))
    {
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
    int x;
    for(x=0;x<=(m+n);x++)
    {
        printf("%d\t",c[x]);
    }
}*/
void Union(int a[],int m,int b[],int n)
{
int c[m+n];
    int i=0;
    int j=0;
    int k=0;
    while((i<=m)&&(j<=n))
    {
        if(a[i]==b[j])
        {
            c[k]=a[i];
            i++;
            k++;
            j++;
        }
        else if(a[i]<b[j])
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
    int x;
    for(x=0;x<=k-2;x++)
    {
        printf("%d\t",c[x]);
    }
}
void intersection(int a[],int m,int b[],int n)
{
    int c[m+n];
    int i=0;
    int j=0;
    int k=0;
    while((i<=m)&&(j<=n))
    {
        if(a[i]==b[j])
        {
            c[k]=a[i];
            i++;
            k++;
            j++;
        }
        else if(a[i]<b[j])
        {
           i++;
        }
        else
        {
            j++;
        }
    }
    int x;
    for(x=0;x<=1;x++)
    {
        printf("%d\t",c[x]);
    }
}
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
    for(x=0;x<=high;x++)
    {
        printf("%d\t",a[x]);
    }
}
void diff(int a[],int m,int b[],int n)
{
    int c[m+n];
    int i=0;
    int j=0;
    int k=0;
   while(i<=m&&j<=n)
   {
    if(a[i]==b[j])
    {
        i++;
        j++;
    }
    else
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            k++;
            i++;
        }
        else
        {
            j++;
        }
    }
   }
   while(i<=m)
   {
       c[k]=a[i];
       k++;
       i++;
   }
int x;
for(x=0;x<2;x++)
{
    printf("%d\t",c[x]);
}
}
void diff2(int a[],int m,int b[],int n)
{
    int c[m+n];
    int i=0;
    int j=0;
    int k=0;
   while(i<=m&&j<=n)
   {
    if(a[i]==b[j])
    {
        i++;
        j++;
    }
    else
    {
        if(a[i]>b[j])
        {
            c[k]=b[j];
            k++;
            j++;
        }
        else
        {
            i++;
        }
    }
   }
   while(j<=n)
   {
       c[k]=b[j];
       k++;
       j++;
   }
int x;
for(x=0;x<2;x++)
{
    printf("%d\t",c[x]);
}
}
main()
{
    int a[]={20,30,40,50};
    int b[]={10,17,20,30,37};
    diff(a,5,b,6);
    printf("\n");
    diff2(a,5,b,6);
}
