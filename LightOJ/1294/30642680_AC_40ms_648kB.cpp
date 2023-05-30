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
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FastIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    FastIO;
    ll t, cn=0;
    cin >> t;
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        cout << "Case " << ++cn << ": ";
        cout << (n*m)/2 << endl;
    }
}