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
    ll n, k, t=0;
    cin >> n >> k;
    vll v(n);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    for(int i=0; i<n; i++)
    {
        if(v[i]==0)
            continue;
        else if(v[i]>=v[k-1])
            t++;
    }
    cout << t << endl;
}