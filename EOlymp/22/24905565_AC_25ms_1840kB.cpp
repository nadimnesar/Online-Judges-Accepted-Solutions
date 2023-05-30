#include <iostream>
#include <stdio.h>
using namespace std;
int mir(int n)
{
    int re=0;
    while(n>0)
    {
        re*=10;
        re+=n%10;
        n/=10;
    }
    n=re;
    return n;
}
int check_prime(int a)
{
    int c;
    for (c=2 ; c<=a-1; c++)
    {
        if ( a%c==0)
            return 0;
    }
    return 1;
}
int main()
{
    int n1, n2, c=0;
    int i, n, j, result=0;
    scanf("%d %d", &n1, &n2);
    if(n1==1)
    {
        n1++;
    }
    for(i=n1; i<=n2; i++)
    {
        n=check_prime(i);
        if(n==1)
        {
            n=mir(i);
            result=check_prime(n);
            if(result==1)
            {
                c++;
            }
        }
    }
    printf("%d\n", c);
}