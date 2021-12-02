#include <stdio.h>
void quicksort(int arr[],int lb,int ub)
{
    if(lb<ub){
        int loc=partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}
int partition(int arr[],int lb,int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    int temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;
    return end;
    
    
}
void printing(int arr[],int n)
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
    quicksort(arr,lb,ub);
    printing(arr,n);

    return 0;
}
