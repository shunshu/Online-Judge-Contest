#include <stdio.h>
#include <stdlib.h>


long long int func(int n, int* str)
{
    if (n == 1)
    {
        return *(str+ 0+ 0);
    }
    else if (n == 2) // This is calculation for the 2x2 matrix
    {
        return (*(str+ 0+ 0))* (*(str+ 1* 2+ 1))- (*(str+ 1* 2+ 0))*(*(str+ 0* 2+ 1));
    }
    else if (n == 3) // This is calculation for the 3x3 matrix
    {
        return (*(str+ 0* n+ 0))*(*(str+ 1* n+ 1))* (*(str+ 2* n+ 2))+ (*(str+ 0* n+ 1))* (*(str+ 1* n+ 2))* (*(str+ 2* n+ 0))+ (*(str+ 0* n+ 2))* (*(str+ 1* n+ 0))* (*(str+ 2* n+ 1))
        - (*(str+ 0* n+ 2))*(*(str+ 1* n+ 1))* (*(str+ 2* n+ 0))- (*(str+ 0* n+ 1))*(*(str+ 1* n+ 0))* (*(str+ 2* n+ 2))- (*(str+ 0* n+ 0))*(*(str+ 1* n+ 2))* (*(str+ 2* n+ 1));
    }
    else // This is calculation for the 4th order determinant or higher order determinant, the determinant is needed to reduce order
    {
        int i;
        long long int cul= 0; // the accumulation of all minors in the same order
        for(i= 0;i< n;i++)
        {
            int* ptr = (int*)malloc(sizeof(int)* (n- 1)* (n- 1)); // arrange the factors in the minor to the consecutive memory for N x N matrix to easily calculate
            int j, k, l= 0;
            for(j= 1;j< n;j++)
            {
                for(k= 0;k< n;k++)
                {
                    if (k != i)
                    {
                        *(ptr+ l) = *(str+ j* n+ k);
                        l++;
                    }
                }
            }
            if ((0+ i)%2 == 0) // determine the minor is either positive or negative
            {
                cul = cul+ *(str+0* n+ i)* func(n- 1, ptr);
            }
            else if ((0+ i)%2 == 1)
            {
                cul = cul- *(str+0* n+ i)* func(n- 1, ptr);
            }
            free(ptr);
        }
        return cul;
    }
}

int main()
{
    int n;
    int* s;
    int i, j;
    long long ans;
    scanf("%d", &n);
    s = (int*) malloc(sizeof(int)* n* n);
    for(i= 0;i< n;i++)
    {
        for(j= 0;j< n;j++)
        {
            scanf("%d", (s+ i* n+ j));
        }
    }
    ans = func(n,s);
    printf("%lld", ans);
}
