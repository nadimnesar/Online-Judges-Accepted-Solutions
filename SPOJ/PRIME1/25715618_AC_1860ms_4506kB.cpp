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

bool ifprime(ll n)
{
    if(n<=1) return false;
    else if(n==2) return true;
    else if(n%2==0) return false;
    else
    {
        ll c=1;
        for(ll i=3; i<=sqrt(n); i+=2)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
}

int main()
{
    FASTIO;
    ll t;
    cin >> t;
    while(t--)
    {
        ll a, b;
        cin >> a >> b;
        for(ll i=a; i<=b; i++)
        {
            if(ifprime(i))
                cout << i << endl;
        }
        cout << endl;
    }
}