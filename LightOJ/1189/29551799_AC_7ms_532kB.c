#include <stdio.h>

int main()
{
    int t, cn = 0;
    scanf("%d", &t);
    while(t--)
    {
        long long m;
        scanf("%lld", &m);
        int y[20];
        int j = 0;
        if(121645100408832000 <= m)
        {
            y[j++] = 19;
            m -= 121645100408832000;
        }
        if(6402373705728000 <= m)
        {
            y[j++] = 18;
            m -= 6402373705728000;
        }
        if(355687428096000 <= m)
        {
            y[j++] = 17;
            m -= 355687428096000;
        }
        if(20922789888000 <= m)
        {
            y[j++] = 16;
            m -= 20922789888000;
        }
        if(1307674368000 <= m)
        {
            y[j++] = 15;
            m -= 1307674368000;
        }
        if(87178291200 <= m)
        {
            y[j++] = 14;
            m -= 87178291200;
        }
        if(6227020800 <= m)
        {
            y[j++] = 13;
            m -= 6227020800;
        }
        if(479001600 <= m)
        {
            y[j++] = 12;
            m -= 479001600;
        }
        if(39916800 <= m)
        {
            y[j++] = 11;
            m -= 39916800;
        }
        if(3628800 <= m)
        {
            y[j++] = 10;
            m -= 3628800;
        }
        if(362880 <= m)
        {
            y[j++] = 9;
            m -= 362880;
        }
        if(40320 <= m)
        {
            y[j++] = 8;
            m -= 40320;
        }
        if(5040 <= m)
        {
            y[j++] = 7;
            m -= 5040;
        }
        if(720 <= m)
        {
            y[j++] = 6;
            m -= 720;
        }
        if(120 <= m)
        {
            y[j++] = 5;
            m -= 120;
        }
        if(24 <= m)
        {
            y[j++] = 4;
            m -= 24;
        }
        if(6 <= m)
        {
            y[j++] = 3;
            m -= 6;
        }
        if(2 <= m)
        {
            y[j++] = 2;
            m -= 2;
        }
        if(1 <= m)
        {
            y[j++] = 1;
            m -= 1;
        }
        if(1 <= m)
        {
            y[j++] = 0;
            m -= 1;
        }
        printf("Case %d: ", ++cn);
        if(m > 0) printf("impossible\n");
        else
        {
            for(int i = j-1; i >= 0; i--)
            {
                if(i == 0) printf("%d!", y[i]);
                else printf("%d!+", y[i]);
            }
            printf("\n");
        }
    }
}
