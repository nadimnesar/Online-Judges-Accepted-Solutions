#include <bits/stdc++.h>
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
    ll n, k;
    cin >> n >> k;
 
    ll pre[n+7];
    pre[0] = 0;
    for(ll i = 1; i <= n; i++){
        ll temp;
        cin >> temp;
        pre[i] = pre[i-1]+temp;
    }

    ll cnt_subarry = 0;

    gp_hash_table < ll, ll, customHash> table;
    table[0] = 1;
    for(ll i = 1; i <= n; i++){
        cnt_subarry += table[pre[i]-k];
        table[pre[i]]++;
    }

    cout << cnt_subarry << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}