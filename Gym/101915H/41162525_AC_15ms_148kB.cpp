#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

const ll mod = 1e9 + 7;
const ll maxx = 1e6 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-7; 
const double pi = acos(-1.0);

void solve() {
    ll n, k;
    cin >> n >> k;

    vector < pair < ll, ll > > v;
    for(ll i = 1; i <= n; i++){
        ll a, b, c; cin >> a >> b >> c;
        v.pb({a, i});
        v.pb({b, i});
        v.pb({c, i});
    }
    sort(full(v));

    ll feq[n+1];
    memset(feq, 0);
    ll res = 0;
    for(ll i = 0; i < v.size(); i++){
        if(k and feq[v[i].second] < 2){
            res += v[i].first;
            feq[v[i].second]++;
            k--;
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}