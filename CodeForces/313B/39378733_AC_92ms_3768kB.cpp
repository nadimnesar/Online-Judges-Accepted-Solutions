#include "bits/stdc++.h"
using namespace std;

#define ll                  long long
#define llu                 unsigned long long

#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)(10)
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void nadimnesar() {
    string s;
    cin >> s;

    vector < ll > v;
    for(ll i = 0; i < s.size(); i++){
        if(i == s.size()-1){
            v.pb(0);
            break;
        }

        if(s[i] == s[i+1]) v.pb(1);
        else v.pb(0);
    }

    vector < ll > pre;
    pre.pb(v[0]);
    for(ll i = 1; i < v.size(); i++) pre.pb(pre[i-1]+v[i]);

    ll m;
    cin >> m;
    while(m--){
        ll x, y;
        cin >> x >> y;
        y -=2;
        x--;

        if(x == 0) cout << pre[y] << endl;
        else cout << pre[y] - pre[x-1] << endl;
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    /*int t, cn = 0;
    cin >> t;
    while (t--) */nadimnesar();

    return 0;
}