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

ll binpow(ll n, ll p){
    if(p == 0) return 1;
    ll res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}

void solve() {
    ll n;
    cin >> n;

    ll res = 0;
    vector < bitset < 60 > > arr;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        arr.pb(temp);
    }

    for(ll i = 0; i < 60; i++){
        ll cnt = 0;
        for(ll j = 0; j < n; j++){
            cnt += arr[j][i];
        }

        ll c = (((cnt * abs(cnt - n))%mod) * (binpow(2, i)%mod))%mod;
        res = ((res%mod) + (c%mod))%mod;
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