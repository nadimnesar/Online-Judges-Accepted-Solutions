/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define all(y)          y.begin(), y.end()
#define all(z)          z.begin(), z.end()
#define pi              acos(-1.0)

int main()
{
    int t;
    scanf("%d", &t);
    bool br = false;
    while(t--)
    {
        int amp, frec;
        scanf("%d", &amp);
        scanf("%d", &frec);
        bool br2 = false;
        if(br) printf("\n");
        while(frec--)
        {
            if(br2) printf("\n");
            for(int i = 1, j = 1; i <= amp; i++, j++)
            {
                for(int k = 0; k < j; k++)
                {
                    printf("%d", i);
                }
                printf("\n");
            }
            for(int i = amp-1, j = amp-1; i >= 1; i--, j--)
            {
                for(int k = 0; k < j; k++)
                {
                    printf("%d", i);
                }
                printf("\n");
            }
            br2 = true;
        }
        br = true;
    }
}
/*ALHAMDULILLAH*/