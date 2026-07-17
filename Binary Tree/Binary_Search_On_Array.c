#include<stdio.h>
int main()
{
    int a[] = {10,20,30,40,50};
    int n = 5;
    int key;

    printf("Enter the element to search :");
    scanf("%d",&key);

    int low = 0, high = n-1, mid;

    while(high >= low)
    {
        mid = (high+low)/2;
        if(a[mid] == key)
        {
            printf("Element found at index %d \n",mid);
            return 0;
        }
        else if(a[mid] > key)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    printf("Element not found!\n");
    return 0;
}
