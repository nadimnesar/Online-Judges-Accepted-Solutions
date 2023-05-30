#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

ll valoLageNa(ll i, ll j){
    ll z = abs(i-j);
    z = min(z, 24-z);
    return z;
}

void solve(){
    ll n;
    while(cin >> n){
        vector < ll > arr;
        for(ll i = 0; i < n; i++){
            ll temp;
            cin >> temp;
            arr.pb(temp);
        }

        sort(full(arr));

        ll ans1 = 0;
        ll ans2 = 0;

        for(ll i = 0; i < n-1; i+=2){
            ans1 += valoLageNa(arr[i], arr[i+1]);
        }

        for(ll i = 0; i < n-1; i+=2){
            if(i == 0) ans2 += valoLageNa(arr[0], arr[n-1]);
            else ans2 += valoLageNa(arr[i], arr[i-1]);
        }

        cout << min(ans1, ans2) << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}