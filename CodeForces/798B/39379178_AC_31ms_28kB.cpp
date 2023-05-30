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
    ll n;
    cin >> n;

    vector < string > v;
    string s;

    for(ll i = 0; i < n; i++){
        cin >> s;
        v.pb(s);
    }

    vector < string > v2;
    v2.pb(s);

    ll limit = s.size()-1;
    while(limit--){
        string s2 = s.substr(1, s.size()-1)+s[0];
        v2.pb(s2);
        s = s2;
    }

    ll res = LLONG_MAX;
    for(ll i = 0; i < v2.size(); i++){
        ll cnt = 0;

        vector < string > v3 = v;
        for(ll j = 0; j < v.size(); j++){

            limit = v[j].size()-1;
            while(limit--){
                if(v[j] == v2[i]) break;

                string s2 = v[j].substr(1, v[j].size()-1)+v[j][0];
                v[j] = s2;
                cnt++;

                if(v[j] == v2[i]) break;
            }

            if(v[j] != v2[i]){
                cout << "-1" << endl;
                return;
            }
        }

        res = min(cnt, res);
        v = v3;
    }

    cout << res << endl;
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