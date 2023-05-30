#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

struct customHash {
    static uint64_t nadimnesar(uint64_t x) { x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31); }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return nadimnesar(x+FIXED_RANDOM);
    }
};

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
#define maxx                (ll)(2e5+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

ll fact[maxx];

ll big_mod(ll B, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll p1=(big_mod(B,P/2,M))%M;
        return (p1*p1)%M;
    }
    else{
        ll p1=B%M;
        ll p2=(big_mod(B,P-1,M))%M;
        return (p1*p2)%M;
    }
}

ll inverse_mod(ll B, ll M){
    return big_mod(B, M-2, M);
}

ll minus_mod(ll A, ll B, ll M){
    ll res = (A - B)%mod;
    if(res < 0) res += mod;
    return (res%mod);
}

void nadimnesar() {
    ll n;
    cin >> n;

    gp_hash_table < ll, ll, customHash> table;
    ll mn = 1e9+7;
    ll mn_cnt = 0;

    vector < ll > v;

    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;

        table[temp]++;

        if(temp <= mn){
            mn = temp;
            mn_cnt = table[temp];
        }
        v.pb(temp);
    }

    if(mn_cnt > 1){
        ll cnt = 0;
        for(ll i = 0; i < n; i++){
            if((v[i]&mn) == mn) cnt++;
        }

        if(cnt == n){
            ll x = (mn_cnt * (mn_cnt-1))%mod;
            x = (x * inverse_mod(2, mod))%mod;
            cout << (((fact[cnt-2] * x)%mod)*2)%mod << endl;
        }
        else cout << '0' << endl;
    }
    else cout << '0' << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    fact[0] = 1;
    for(ll i = 1; i < maxx; i++) fact[i] = (fact[i-1] * i)%mod;
    
    ll t;
    cin >> t;
    while(t--) nadimnesar();

    return 0;
}