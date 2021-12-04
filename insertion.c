#include <stdio.h>
void insertion(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    
}
void printing(int arr[],int n)
{
for(int i=0;i<n;i++)
{
    printf("%d ",arr[i]);
}
}
int main() {
    int n,arr[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    insertion(arr,n);
    printing(arr,n);
    return 0;
}
