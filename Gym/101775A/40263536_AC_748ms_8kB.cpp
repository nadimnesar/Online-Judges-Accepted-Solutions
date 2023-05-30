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
    ll res = (A - B)%M;
    if(res < 0) res = (res+M)%M;
    return res;
}

void nadimnesar() {
    ll n, k;
    cin >> n >> k;

    if(k > n){
        cout << 0 << endl;
        return;
    }

    // nc1 + nc2 + nc3 + .... + nCn = 2^n - 1

    ll res = big_mod(2, n, mod);
    res = minus_mod(res, 1, mod);

    ll nCr_minus_1 = n;
    res = minus_mod(res, nCr_minus_1, mod);

    for (ll r = 2; r <= k-1; r++) {

        ll ncr = (nCr_minus_1 * (((n-r+1) * inverse_mod(r, mod))%mod))%mod;
        res = minus_mod(res%mod, ncr, mod);

        nCr_minus_1 = ncr;
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--) {
        cout << "Case #" << ++cn << ": ";
        nadimnesar();
    }

    return 0;
}