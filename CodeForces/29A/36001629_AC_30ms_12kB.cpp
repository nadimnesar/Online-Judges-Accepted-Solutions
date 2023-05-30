#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e3+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))


void solve(){

    ll n;
    cin >> n;

    vector < pair < ll, ll > > arr;
    for(ll i = 1; i <= n; i++){

        ll x, y;
        cin >> x >> y;

        arr.pb({x, y});
    }

    bool flag = false;

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){

            if(i == j) continue;

            if(arr[i].first + arr[i].second == arr[j].first and arr[j].first + arr[j].second == arr[i].first){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}