#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)23
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void solve() {
    ll n;
    cin >> n;

    ll neg;
    cin >> neg;

    ll total = 0;

    vector < ll > v, pre;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        v.pb(temp);
        total += temp;
    }

    if(n == 1){
        cout << neg << endl;
        return;
    }

    pre.pb(v[0]);
    for(ll i = 1; i < n; i++) pre.pb(pre[i-1]+v[i]);

    for(ll i = 0; i < n; i++){
        ll left;
        if(i == 0) left = 0;
        else left = pre[i-1];

        ll right;
        if(i+1 == n) right = 0;
        else right = total - pre[i];
        
        ll mid = left+right+neg;

        ll res = max({left, right, mid});

        if(i+1 == n) cout << res << endl;
        else cout << res << ' ';
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // int t, cn = 0;
    // cin >> t;
    // while (t--) {
    //     // cout << "Case " << ++cn << ": ";
    //     solve();
    // }
    solve();

    return 0;
}