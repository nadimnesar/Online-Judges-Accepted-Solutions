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
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define EPS             1e-9
#define INF             (1<<30)
#define MOD             10007
#define SIZ             1005
 
int main()
{
    //************//
 
    ios_base::sync_with_stdio(0);cin.tie(0);
 
    //************//
 
    ll t, c=0;
    cin >> t;
    while(t--)
    {
        double v1, v2, v3, a1, a2, d, t1, t2, t, s;
        cin >> v1 >> v2 >> v3 >> a1 >> a2;
        cout << "Case " << ++c << ": ";
        d=(double)((v1*v1)/(2.0*a1))+((v2*v2)/(2.0*a2));
        t1=(double)(v1/a1);
        t2=(double)(v2/a2);
        t=max(t1, t2);
        s=(double)(v3*t);
        cout << fixed << setprecision(9) << d+EPS << " ";
        cout << fixed << setprecision(9) << s+EPS << endl;
    }
}