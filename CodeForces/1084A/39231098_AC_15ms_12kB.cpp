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

    vector < ll > v(n+1);
    for(ll i = 1; i <= n; i++) cin >> v[i];

    ll unit = LLONG_MAX;
    for(ll x = 1; x <= n; x++){

        ll cost = 0;
        for(ll i = 1; i <= n; i++){
            cost += (abs(x-1)+abs(1-i)+abs(i-x)+abs(x-i)+abs(i-1)+abs(x-1))*v[i];
        }

        unit = min(unit, cost);
    }

    cout << unit << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}