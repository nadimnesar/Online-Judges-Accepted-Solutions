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
        double l, w, r;
        scanf("%lf", &l);
        w = (l * 6.0)/10.0;
        r = l / 5.0;
        printf("%.2lf %.2lf\n", (pi*(r*r)), (l*w)-(pi*(r*r)));
    }
}
/*ALHAMDULILLAH*/
