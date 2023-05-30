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
    ll a, b;
    cin >> a >> b;

    if(a > b) swap(a, b);

    vector < ll > v;
    for(ll i = 1; i*i <= a; i++){
        if(a%i == 0){
            if(b%i == 0) v.pb(i);
            if(i*i != a and b%(a/i) == 0) v.pb(a/i);
        }
    }
    sort(full(v));

    ll q;
    cin >> q;

    while(q--){
        ll x, y;
        cin >> x >> y;

        ll left = lower_bound(full(v), x) - v.begin();
        if(left == v.size()){
            cout << "-1" << endl;
            continue;
        }
        ll right = upper_bound(full(v), y) - v.begin();

        ll z = (right - left);

        if(z > 0) cout << v[right-1] << endl;
        else cout << "-1" << endl;
    }
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