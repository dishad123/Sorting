#include <stdio.h>

void countingsort(int arr[],int n)
{
    //to find the maxium element int the array
    int max=arr[0];
    int output[100];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max){
            max=arr[i];
        }
    }
    //declaring the count array
    int count[10];//assuming the size to be maximum rande 0 to 9
    for(int i=0;i<=max;i++)
    {
        count[i]=0;//initializing all the values in the count array to be zero
    }
    //updating the count value
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    //find the cumulative freuency
    for(int i=1;i<=max;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    //output array
    for(int i=n-1;i>=0;i--)
    {
        output[--count[arr[i]]]=arr[i];
    }
    //copy the elements
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}
    //print the array
    void printing(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
    }


int main()
{
    int arr[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    countingsort(arr,n);
    printing(arr,n);
    return 0;
}
