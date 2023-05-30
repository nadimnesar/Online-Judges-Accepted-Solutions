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
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void nadimnesar() {
    ll n, m;
    cin >> n >> m;

    vector < string > v;
    for(ll i = 0; i < n; i++){
        string s;
        cin >> s;
        v.pb(s);
    }

    ll flag[n];
    memset(flag, 0);

    for(ll i = 0; i < m; i++){
        string s;
        cin >> s;

        ll total = 0;
        bool flag = false;

        for(ll j = 0; j < n; j++){
            if(v[j].size() == s.size()){

                ll cnt = 0;
                for(ll k = 0; k < v[j].size(); k++){
                    if(s[k] != v[j][k]){
                        cnt++;
                    }
                    if(cnt >= 2) break;
                }

                if(cnt == 0){
                    cout << "yes" << endl;
                    flag = true;
                    break;
                }
                if(cnt == 1) total++;
            }
        }

        if(flag) continue;
        if(total == 1) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--){
        cout << "Case #" << ++cn << ":" << endl;
        nadimnesar();
    }

    return 0;
}