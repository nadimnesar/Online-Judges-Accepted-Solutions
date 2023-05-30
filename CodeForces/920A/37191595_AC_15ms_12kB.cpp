#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define ppb                 pop_back
#define ppf                 pop_front
#define pb                  push_back
#define pf                  push_front

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
    ll n, k;
    cin >> n >> k;

    vector < ll > v;
    for(ll i = 0; i < k; i++){
        ll temp;
        cin >> temp;
        v.pb(temp);
    }

    ll left = 1;
    ll right = n;
    ll res = -1;
    while(right >= left){
        ll mid = left + (right-left)/2;

        bool flag[n+7];
        memset(flag, false);

        for(ll i = 0; i < k; i++){
            
            ll l = max((ll)1, v[i]-(mid-1));
            ll r = min(n, v[i]+(mid-1));

            for(ll j = l; j <= r; j++) flag[j] = true;
        }

        bool alldone = true;
        for(ll i = 1; i <= n; i++){
            if(flag[i] == false) alldone = false;
        }

        if (alldone){
            res = mid;
            right = mid -1;
        }
        else left = mid+1;
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--) {
        // cout << "Case " << ++cn << ": ";
        solve();
    }
    // solve();

    return 0;
}