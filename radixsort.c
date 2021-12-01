#include <stdio.h>

int getMax(int arr[],int n)
{
    int max=arr[0];
    for(int i =0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}
void countingsort(int arr[],int n,int pos)
{
    int output[20];
    //to find the maximum
    
    int count[10]={0};
    //count array
   for(int i=0;i<n;i++)
   {
       count[(arr[i]/pos)%10]++;
   }
    //cumulative frequency
    for(int i=1;i<=9;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    //output array
    for(int i=n-1;i>=0;i--)
    {
        output[--count[(arr[i]/pos)%10]]=arr[i];
    }
    //copy the elements
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
    
}
void radixsort(int arr[],int n)
{
    int max=getMax(arr,n);
    for(int pos=1;(max/pos)>0;pos=pos*10){
        countingsort(arr,n,pos);
    }
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
    int arr[30];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    radixsort(arr,n);
    printing(arr,n);

return 0;
}
