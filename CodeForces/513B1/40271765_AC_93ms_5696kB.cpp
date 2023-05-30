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

bool cmp(pair < ll, vector < ll > > x, pair < ll, vector < ll > > y){
    if(x.first != y.first) return x.first > y.first;
    for(ll i = 0; i < x.second.size(); i++){
        if(x.second[i] < y.second[i]) return true;
        if(x.second[i] > y.second[i]) return false;
    }
    return true;
}

void nadimnesar() {
    ll n, m;
    cin >> n >> m;

    vector < ll > v;
    for (ll i = 1; i <= n; i++) {
        v.pb(i);
    }

    vector < pair < ll, vector < ll > > > final;

    do {
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = i; j < n; j++) {
                sum += *min_element(v.begin() + i, v.begin() + j + 1);
            }
        }
        final.pb({sum, v});
    }
    while (next_permutation(full(v)));

    sort(full(final), cmp);

    for(auto it: final[m-1].second){
        cout << it << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}