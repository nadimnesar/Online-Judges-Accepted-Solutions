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

ll binpow(ll n, ll p){
    if(p == 0) return 1;
    ll res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}

void nadimnesar() {
    ll n;
    cin >> n;

    ll k;
    cin >> k;

    vector < ll > a;
    ll mx = 0;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        a.pb(temp);
        mx = max(mx, temp);
    }

    sort(full(a));

    ll allpower[54];
    ll mxpow;
    for(ll i = 0; i < 54; i++){
        ll now = binpow(k, i);
        if(now > mx) break;
        else{
            allpower[i] = now;
            mxpow = i;
        }
    }

    ll i = 0;
    ll at = mxpow;
    map < ll , bool > mp;

    for(; i < n; i++){

        while(a[i] and at >= 0){
            if(a[i] >= allpower[at] and !mp[at]){
                a[i] -= allpower[at];
                mp[at] = true;
            }
            at--;
        }

        at = mxpow;
        if(a[i]) break;
    }

    if(i == n) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--){
        // cout << "Case #" << ++cn << ": ";
        nadimnesar();
    }

    return 0;
}