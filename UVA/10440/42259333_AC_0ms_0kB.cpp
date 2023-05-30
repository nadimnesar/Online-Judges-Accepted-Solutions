#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
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
    ll n, t, m;
    cin >> n >> t >> m;

    vector < ll > v;
    for(ll i = 0; i < m; i++){
        ll temp;
        cin >> temp;
        v.pb(temp);
    }
    sort(full(v));

    if(m%n == 0){

        ll at = 0;
        ll trip = 0;
        ll now = 0;

        for(ll i = 0; i < m; i++){
            now++;
            ll wait = v[i]-at;
            if(wait > 0) at += wait;

            if(now == n){
                trip++;
                at += t+t;
                now = 0;
            }
        }

        cout << at-t << ' ' << trip << endl; 
    }
    else{

        ll x = m%n;
        ll at = 0;
        for(ll i = 0; i < x; i++){
            ll wait = v[i]-at;
            if(wait > 0) at += wait;
        }

        ll trip = 1;
        at += t+t;
        ll now = 0;

        for(ll i = x; i < m; i++){
            now++;
            ll wait = v[i]-at;
            if(wait > 0) at += wait;

            if(now == n){
                trip++;
                at += t+t;
                now = 0;
            }
        }

        cout << at-t << ' ' << trip << endl;
    }   
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t, cn = 0;
    cin >> t;
    while (t--){
        // cout << "Case " << ++cn << ": ";
        solve();
    }

    return 0;
}