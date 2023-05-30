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


int digit(int x)
{
    ll d=0;
    while(x)
    {
        d++;
        x/=10;
    }
    return d;
}
int main()
{
    FastIO;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, i=1, p=0;
        cin >> n;
        ll c=digit(n);
        vll v;
        while(c--)
        {
            if((n%10)!=0)
            {
                ll temp=n%10;
                p++;
                v.pb(temp*i);
            }
            i*=10;
            n/=10;
        }
        cout << p << endl;
        for(int j=0; j<v.size(); j++)
        {
            if(j==(v.size()-1))
                cout << v[j] << endl;
            else cout << v[j] << " ";
        }
    }
}