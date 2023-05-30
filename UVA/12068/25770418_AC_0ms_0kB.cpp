#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define ull             long long unsigned int
#define vll             vector< ll >
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define point(x)        fixed << setprecision(x)
#define PI              acos(-1.0) //3.1415926535897932
#define EPS             1e-9
#define MAX             10001
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FASTIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll arr[], ll n)
{
    ll ans = arr[0];
    for (ll i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
               (gcd(arr[i], ans)));
    return ans;
}

int main()
{
    FASTIO;
    ll t, cn=0;
    cin >> t;
    while(t--)
    {
        ll N;
        cin >> N;
        ll arr[N];
        for(ll i=0; i<N; i++)
            cin >> arr[i];
        ll LCM=lcm(arr, N);
        ll lob=LCM*N, hor=0;
        for(ll i=0; i<N; i++)
            hor+=LCM/arr[i];
        ll GCD=gcd(lob, hor);
        cout << "Case " << ++cn << ": ";
        if(GCD==1) cout << lob << '/' << hor << endl;
        else
        {
            lob/=GCD;
            hor/=GCD;
            cout << lob << '/' << hor << endl;
        }
    }
}