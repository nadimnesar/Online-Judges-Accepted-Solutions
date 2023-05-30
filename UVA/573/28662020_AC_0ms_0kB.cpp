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
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FASTIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    FASTIO;
    while(1)
    {
        float d, high=0;
        int h, u, n, day=1;
        cin >> h >> d >> n >> u;
        if(h==0) break;
        double lost=d*u/100;
        while(1)
        {
            high+=d;
            if(d > 0) d-=lost;
            if(high>h) break;
            high-=n;
            if(high<0) break;
            day++;
        }
        if(high<0) cout << "failure on day " << day << endl;
        else cout << "success on day " << day << endl;
    }
}