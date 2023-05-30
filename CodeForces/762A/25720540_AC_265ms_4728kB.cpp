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
#define MAX             15000
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FASTIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

ll p=0;

void div(vll &x, ll d)
{
    for(ll i=1; i*i<=d; i++)
    {
        if(d%i==0)
        {
            p++;
            x.pb(i);
            if(i*i!=d)
            {
                p++;
                x.pb(d/i);
            }
        }
    }
}

int main()
{
    FASTIO;
    ll n, k;
    cin >> n >> k;
    vll x;
    div(x, n);
    sort(all(x));
    if(p>=k)
        cout << x[k-1] << endl;
    else cout << "-1" << endl;
}