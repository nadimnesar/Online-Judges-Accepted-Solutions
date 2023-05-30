#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define all(y)          y.begin(), y.end()
#define PI              acos(-1.0)
#define MAX             1000001
#define MOD             10000007

int main()
{
    ll int t, cn=0;
    scanf("%lld", &t);
    vector < ll int > x;
    vector < ll int > y;
    while(t--)
    {
        ll int tmp1, tmp2;
        scanf("%lld %lld", &tmp1, &tmp2);
        x.pb(tmp1);
        y.pb(tmp2);
    }
    ll int len=x.size();
    for(int i=0; i < len; i++)
    {
        for(int j=0; j<len; j++)
            if(x[i]==y[j]) cn++;
    }
    printf("%lld", cn);
}