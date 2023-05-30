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
    vector < ll > v;
    for(ll i = 0; i < 10; i++){
        ll temp;
        cin >> temp;
        v.pb(temp);
    }

    ll k;
    cin >> k;

    vector < ll > v2;
    for(ll i = 0; i < 10; i++){
        v2.pb(i);
    }

    bool flag = true;

    do{
        ll x = 0;
        for(ll i = 0; i < 10; i++){
            x += v[i] * v2[i];
        }

        if(x <= k){
            flag = false;
            for(ll i = 0; i < 10; i++){
                if(i == 9) cout << v2[i] << endl;
                else cout << v2[i] << ' ';
            }
            break;
        }
    }
    while(next_permutation(full(v2)));

    if(flag) cout << "-1" << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    cin.ignore();
    while (t--) {
        // cout << "Case " << ++cn << ": ";
        solve();
    }
    // solve();

    return 0;
}