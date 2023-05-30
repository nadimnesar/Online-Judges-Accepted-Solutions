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
#define MAX             1000001
#define MOD             10000007
#define yes             cout << "yes" << '\n'
#define no              cout << "no" << '\n'
#define YES             cout << "YES" << '\n'
#define NO              cout << "NO" << '\n'
#define FASTIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    FASTIO;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        if(n==1)
        {
            cout << "1" << '\n';
            cout << "1 " << "1" << '\n';
        }
        else if(n%2==0)
        {
            cout << n/2 << '\n';
            for(ll i=1; i<n; i+=2)
            {
                cout << "2 " << i << " " << i+1 << '\n';
            }
        }
        else
        {
            cout << n/2 << '\n';
            cout << "3 " << "1 " << "2 " << n << '\n';
            for(ll i=3; i<n-1; i+=2)
            {
                cout << "2 " << i << " " << i+1 << '\n';
            }
        }
    }
}