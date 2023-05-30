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
//#define lend            '\n'
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FASTIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    FASTIO;
    string a;
    while(cin >> a)
    {
        if(a[0]=='0' && a.size()==1) break;
        a.erase(remove(a.begin(), a.end(), '-'), a.end());
        ll i=0, n=0;
        while(a[i])
        {
            n=n*10+(a[i]-48);
            n=n%17;
            i++;
        }
        if(n==0) cout << "1" << endl;
        else cout << "0" << endl;
    }
}
