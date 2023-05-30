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
        vll x;
        ll c=0;
        for(ll i=0; i<n; i++)
        {
            ll temp;
            cin >> temp;
            x.pb(temp);
        }
        for(ll i=1; i<n; i++)
        {
            for(ll j=0; j<n-i; j++)
            {
                if(x[j]>x[j+1])
                {
                    c++;
                    swap(x[j], x[j+1]);
                }
            }
        }
        cout << "Minimum exchange operations : " << c << endl;
    }
}