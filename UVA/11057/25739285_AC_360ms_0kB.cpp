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

int main()
{
    FASTIO;
    ll n;
    while(cin >> n)
    {
        vll x(n);
        for(ll i=0; i<n; i++)
        {
            cin >> x[i];
        }
        ll m;
        cin >> m;
        ll b1, b2, dif=m;
        for(ll i=0; i<n; i++)
        {
            if(x[i]>=m) continue;
            for(ll j=i+1; j<n; j++)
            {
                if(x[j]>=m) continue;
                if(x[i]+x[j]==m)
                {
                    if(abs(x[i]-x[j])<dif)
                    {
                        dif=abs(x[i]-x[j]);
                        b1=x[i];
                        b2=x[j];
                    }
                }
            }
        }
        if(b1>b2)
            cout << "Peter should buy books whose prices are " << b2 << " and " << b1 << "." << endl << endl;
        else if(b1<b2)
            cout << "Peter should buy books whose prices are " << b1 << " and " << b2 << "." << endl << endl;
    }
}