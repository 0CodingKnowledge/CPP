#include <stdio.h>
#include <stdlib.h>
long long tribonacci(int n)
{
    if(n < 0)
    {
        exit(-1);
    }

    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 2;
    }

    if (n > 2)
    {
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
}

int main()
{
    int n;

    if (scanf("%d", &n) != 1|| n < 0)
    {
        printf("valor invalido\n");
        return 0;
    }
    printf("%lld\n", tribonacci(n));
    return 0;
}