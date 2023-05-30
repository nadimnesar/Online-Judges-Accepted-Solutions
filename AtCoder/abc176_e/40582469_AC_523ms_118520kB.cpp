#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

struct customHash {
    static uint64_t nadimnesar(uint64_t x) {
        x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return nadimnesar(x + FIXED_RANDOM);
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
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void nadimnesar() {
    ll n, m, t;
    cin >> n >> m >> t;

    gp_hash_table < ll, ll, customHash> r, c;
    map < pair < ll, ll >, bool > mp;

    for (ll i = 0; i < t; i++) {
        ll x, y;
        cin >> x >> y;
        r[x]++;
        c[y]++;
        mp[ {x, y}] = true;
    }

    ll mx_r = 0, r_idx;
    ll mx_c = 0, c_idx;

    for (auto it : r) {
        if (it.second > mx_r) {
            mx_r = it.second;
            r_idx = it.first;
        }
    }

    for (auto it : c) {
        if (it.second > mx_c) {
            mx_c = it.second;
            c_idx = it.first;
        }
    }

    if (!mp[ {r_idx, c_idx}]) cout << mx_r + mx_c << endl;
    else {
        ll res = (mx_r + mx_c) - 1;
        for (ll j = 1; j <= m; j++) {
            if (!mp[ {r_idx, j}]) res = max(res, mx_r + c[j] );
        }
        for (ll i = 1; i <= n; i++) {
            if (!mp[ {i, c_idx}]) res = max(res, mx_c + r[i] );
        }

        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}