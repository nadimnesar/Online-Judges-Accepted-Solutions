#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define ppb                 pop_back
#define ppf                 pop_front
#define pb                  push_back
#define pf                  push_front

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)23
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

bool cmp1(pair < ll, ll > x, pair < ll, ll > y){
    ll d1 = abs(x.first-1) + abs(x.second-1);
    ll d2 = abs(y.first-1) + abs(y.second-1);

    return (d1 < d2);
}

bool cmp2(pair < ll, ll > x, pair < ll, ll > y){
    ll d1 = abs(x.first-1) + abs(x.second-1e9);
    ll d2 = abs(y.first-1) + abs(y.second-1e9);

    return (d1 < d2);   
}

bool cmp3(pair < ll, ll > x, pair < ll, ll > y){
    ll d1 = abs(x.first-1e9) + abs(x.second-1e9);
    ll d2 = abs(y.first-1e9) + abs(y.second-1e9);

    return (d1 < d2);
}

bool cmp4(pair < ll, ll > x, pair < ll, ll > y){
    ll d1 = abs(x.first-1e9) + abs(x.second-1);
    ll d2 = abs(y.first-1e9) + abs(y.second-1);

    return (d1 < d2);
}

void solve() {
    ll n;
    cin >> n;

    vector < pair < ll, ll > > v1, v2;
    for(ll i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        v1.pb({x, y});
    }

    sort(full(v1), cmp1);
    v2.pb(v1[0]);

    sort(full(v1), cmp2);
    v2.pb(v1[0]);

    sort(full(v1), cmp3);
    v2.pb(v1[0]);

    sort(full(v1), cmp4);
    v2.pb(v1[0]);

    ll res = 0;

    for(ll i = 0; i < 4; i++){
        for(ll j = 0; j < 4; j++){
            ll d = abs(v2[i].first - v2[j].first) + abs(v2[i].second - v2[j].second);
            res = max(res, d);
        }        
    }

    cout << res << endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // int t, cn = 0;
    // cin >> t;
    // while (t--) {
    //     // cout << "Case " << ++cn << ": ";
    //     solve();
    // }
    solve();

    return 0;
}