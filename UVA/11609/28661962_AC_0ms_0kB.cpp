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
int BIGMOD(ull B, ull P, ull M)
{
    if(P==0) return 1;
    if(P%2==0)
    {
        ull p1=(BIGMOD(B,P/2,M))%M;
        return (p1*p1)%M;
    }
    else if(P%2!=0)
    {
        ull p1=B%M;
        ull p2=(BIGMOD(B,P-1,M))%M;
        return (p1*p2)%M;
    }
}
int main()
{
    ull t, cn=0, m=1000000007;
    cin >> t;
    while(t--)
    {
        ull n;
        cin >> n;
        cout << "Case #" << ++cn << ": " << ((BIGMOD(2, n-1, m))*(n%m))%m << endl;
    }
}
