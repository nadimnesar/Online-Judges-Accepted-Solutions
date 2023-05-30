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

void solve() {
    ll n;
    cin >> n;

    vector < ll > v;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        v.pb(temp);
    }

    bool flag = false;
    ll res = 0;
    while(!flag){
        bool allpos = true;

        for(ll i = 0; i < n; i++){
            if(v[i] < 0){
                allpos = false;
                res++;
                v[i] = abs(v[i]);

                ll p = i-1;
                ll q = i+1;
                if(p == -1) p = n-1;
                if(q == n) q = 0;

                v[p] -= v[i];
                v[q] -= v[i];
            }
        }
        flag = allpos;
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}