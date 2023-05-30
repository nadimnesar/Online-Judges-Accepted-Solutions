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
    int q;
    scanf("%d", &q);
    x.erase(x.begin()+(q-1));
    int k, m;
    scanf("%d %d", &k, &m);
    x.erase(x.begin()+(k-1),x.begin()+(m-1));
    int sizex = x.size();
    printf("%d\n", sizex);
    for(int i = 0; i < sizex; i++)
    {
        if(i == sizex) printf("%d\n", x[i]);
        else printf("%d ", x[i]);
    }
}
/*ALHAMDULILLAH*/
