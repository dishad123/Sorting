#include <stdio.h>
void merge(int[],int,int,int);
void mergesort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
    int mid=(lb+ub)/2;    
    mergesort(arr,lb,mid);
    mergesort(arr,mid+1,ub);
    merge(arr,lb,mid,ub);
    }
}


void merge(int arr[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[20];
    while(i<=mid&&j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            b[k]=arr[i];
            i++;
        }
        else
        {
            b[k]=arr[j++];
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=arr[j++];
            k++;
        }
        
    }
    else
    {
        while(i<=mid)
        {
            b[k]=arr[i++];
            k++;
        }
    }
    for(k=lb;k<=ub;k++)
    {
        arr[k]=b[k];
    }
    
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int arr[20];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int lb=0;
    int ub=n-1;
    
    mergesort(arr,lb,ub);
    
    print(arr,n);
    return 0;
}
