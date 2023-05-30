#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define vi              vector< int >
#define vll             vector< ll >
#define vc              vector< char >
#define vs              vector< string >
#define pb              push_back
#define all(v)          v.begin(), v.end()
#define PI              acos(-1.0)  // 3.1415926535897932

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll x, y, a, b;
        cin >> x >> y;
        a=(x+y);
        b=(x-y);
        if(a<0 || b<0)
        {
            cout << "impossible" << endl;
        }
        else if(a%2!=0 || b%2!=0)
        {
            cout << "impossible" << endl;
        }
        else cout << a/2 << " " << b/2 << endl;
    }
}