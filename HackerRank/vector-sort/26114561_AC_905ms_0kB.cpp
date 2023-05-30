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
    sort(all(x));
    for(int i = 0; i < n; i++){
        if(i == n-1) printf("%d\n", x[i]);
        else printf("%d ", x[i]);
    }
}
/*ALHAMDULILLAH*/
