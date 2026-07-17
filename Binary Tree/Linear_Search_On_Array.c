#include<stdio.h>

int main()
{
    int a[] = {2, 6, 30, 15, 50};
    int n = 5;
    int key, i;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            printf("Element found at index %d\n", i);
            return 0;
        }
    }

    printf("Element not found!\n");

    return 0;
}


