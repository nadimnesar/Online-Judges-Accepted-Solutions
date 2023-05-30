#include <bits/stdc++.h>
using namespace std;

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
const ll maxx = 1e5 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-7;
const double pi = acos(-1.0);

ll binpow(ll n, ll p){
    if(p == 0) return 1;
    ll res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}

void solve() {
    string s;

    while(getline(cin, s)){
        if(s == "0") break;

        stringstream ss(s);
        ll n, p;
        ll num = 1;
        while(ss >> n >> p) num *= binpow(n, p);

        num--;

        vector < pair < ll, ll > > res;
        for(ll i = 2; i <= num; i++){
            ll cnt = 0;
            while(num%i == 0){
                cnt++;
                num /= i;
            }
            if(cnt) res.pb({i, cnt});
        }

        reverse(full(res));
        for(ll i = 0; i < res.size(); i++){
            if(i == res.size()-1) cout << res[i].first << ' ' << res[i].second << endl;
            else cout << res[i].first << ' ' << res[i].second << ' '; 
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}