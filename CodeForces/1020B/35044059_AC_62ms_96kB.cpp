#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(2e7+7)
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

unordered_map < int, bool > um;

void solve(){
    ll n;
    cin >> n;
    
    vector < ll > arr(n+7);
    for(ll i = 1; i <= n; i++) cin >> arr[i];
    
    vector < ll > res;
    
    for(ll i = 1; i <= n; i++){
        um.clear();
        ll x = i;
        while(true){
            if(um[x]){
                res.pb(x);
                break;
            }
            else{
                um[x] = true;
                x = arr[x];
            }
        }
    }
    
    for(ll i = 0; i < n; i++){
        if(i+1 == n) cout << res[i] << endl;
        else cout << res[i] << ' ';
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}
