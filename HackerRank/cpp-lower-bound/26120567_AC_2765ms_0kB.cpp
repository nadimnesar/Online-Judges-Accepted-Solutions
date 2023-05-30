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
    int n;
    scanf("%d", &n);
    vector < int > x(n);
    for(int i = 0; i < n; i++) scanf("%d", &x[i]);
    int k;
    scanf("%d", &k);
    while(k--)
    {
        int m;
        scanf("%d", &m);
        int j = lower_bound(all(x), m) - x.begin();
        if(x[j] == m) printf("Yes %d\n", j+1);
        else printf("No %d\n", j+1);
    }
}
/*ALHAMDULILLAH*/
