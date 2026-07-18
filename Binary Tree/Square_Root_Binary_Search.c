#include <stdio.h>

long long binarySqrt(long long n)
{
    long long low = 0, high = n, ans = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (mid <= n / mid)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    long long n;

    printf("Enter a number: ");
    scanf("%lld", &n);

    printf("Square root = %lld\n", binarySqrt(n));

    return 0;
}
