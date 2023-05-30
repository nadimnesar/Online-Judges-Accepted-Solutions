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
    while(t--)
    {
        int r, c;
        scanf("%d %d", &r, &c);
        r = r - 2;
        c = c - 2;
        if(r % 3 == 0) r = r/3;
        else r = (r/3) + 1;
        if(c % 3 == 0) c = c/3;
        else c = (c/3) + 1;
        printf("%d\n", r*c);
    }
}
/*ALHAMDULILLAH*/
