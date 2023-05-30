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
    ll n, m;
    cin >> n >> m;

    ll at = 1;
    ll res = 0;


    for(ll i = 0; i < m; i++){
        ll x;
        cin >> x;

        if(x >= at) res += x-at;
        else res += (n-at)+x;

        at = x;
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}