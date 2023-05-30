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
    while(t--)
    {
        double R;
        int n;
        scanf("%lf %d", &R, &n);
        double thita=(360.0/n)/2.0;
        double r=(sin(thita*PI/180.0)*R)/(1+sin(thita*PI/180.0));
        printf("Case %d: %.10lf\n", ++cn, r);
    }
}