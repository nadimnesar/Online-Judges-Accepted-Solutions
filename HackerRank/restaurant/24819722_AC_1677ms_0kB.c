#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int l, b, big, small, x, p;
        scanf("%d %d", &l, &b);
        if(l>b)
        {
            big=l;
            small=b;
        }
        else
        {
            big=b;
            small=l;
        }
        again:
        if(l%small==0 && b%small==0)
        {
            x=small;
        }
        else
        {
            small--;
            goto again;
        }
        p=l*b;
        p=p/pow(x, 2);
        printf("%d\n", p);
    }
}