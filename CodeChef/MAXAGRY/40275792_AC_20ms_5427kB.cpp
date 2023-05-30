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

ll sumer(ll n){
    llu x = n;
    x = x*(n+1);
    x /= 2;
    return x;
}

void nadimnesar() {
    ll n, k;
    cin >> n >> k;

    if(n == 1){
        cout << 0 << endl;
        return;
    }

    if(k >= n/2) cout << sumer(n-1) << endl;
    else{

        llu x = sumer(n-1) - sumer((n-k)-1);

        x += ((n-(2*k))*k);

        x += sumer(k-1);

        cout << x << endl;
    }
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