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

ll fact[20];

void nadimnesar() {
    ll n;
    cin >> n;

    vector < ll > res;

    for(ll i = 19; i >= 0; i--){
        // cout << fact[i] << "-" << n;
        if(n >= fact[i]) n -= fact[i], res.pb(i);
        // cout << "=" << n << endl;
    }

    if(n) cout << "impossible" << endl;
    else{
        reverse(full(res));
        for(ll i = 0; i < res.size(); i++){
            if(i == 0) cout << res[i] << "!";
            else cout << "+"<< res[i] << "!";
        }
        cout << endl;
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    fact[0] = 1;
    for(ll i = 1; i <= 19; i++) fact[i] = fact[i-1]*i;

    int t, cn = 0;
    cin >> t;
    while (t--){
        cout << "Case " << ++cn << ": ";
        nadimnesar();
    }

    return 0;
}