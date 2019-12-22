
int partition(int a[],int low,int high)
{
    int t,x;
    int i=low;
    int j=high+1;
  /*  int mid=(low+high)/2;
    t=a[low];
    a[low]=a[mid];
    a[mid]=t;*/
    t=rand()%(high-low)+low;
    x=a[low];
    a[low]=a[t];
    a[t]=x;

    int pivot=a[low];
    do
    {
        do
        {
            i++;
        }
        while(a[i]<pivot);

        do
        {
            j--;
            }
            while(a[j]>pivot);
        int t;
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    while(i<=j);
    int d;
        d=a[low];
        a[low]=a[j];
        a[j]=d;
        return j;
}
void quicksort(int a[],int low,int high)
{
    int j;
    if(low<high)
    {
        j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }


}
main()
{

    int a[]={12,9,15,6,20,8,10,60,7};
    //int a[]={6,8,9,12,45,67,89,90};
    a[9]=12345678;
    int low=0;
    int c;
    int high=9;
    quicksort(a,low,high);
    int i;
    for(i=0;i<9;i++)
    {
        printf("%d\t",a[i]);
    }
}
