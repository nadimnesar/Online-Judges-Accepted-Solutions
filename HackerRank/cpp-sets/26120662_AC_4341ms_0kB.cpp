/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define all(y)          y.begin(), y.end()
#define all(z)          z.begin(), z.end()
#define pi              acos(-1.0)

set < int > x;
set < int >::iterator it;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int q, k;
        scanf("%d %d", &q, &k);
        if(q == 1) x.insert(k);
        else if(q == 2) x.erase(k);
        else
        {
            it = x.find(k);
            if(it == x.end()) printf("No\n");
            else printf("Yes\n");
        }
    }
}
/*ALHAMDULILLAH*/
