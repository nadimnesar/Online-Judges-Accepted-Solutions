#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(5e4+7)                           
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

ll n, q;
ll arr[maxx];
ll sTable[17][maxx];

void build_sTable(){
    ll limit = log(10, n)/log(10, 2);
    for(ll i = 0; i <= limit; i++){
        ll l = 1 << i;
        for(ll j = 0; j+l <= n; j++){
            if(l == 1) sTable[i][j] = arr[j];
            else sTable[i][j] = max(sTable[i-1][j], sTable[i-1][j+ l/2]);
        }
    }
}

ll serarch_MAX(ll lll, ll rr){
    ll x = (rr - lll)+1;
    ll limit = log(10, x)/log(10, 2);
    ll l = 1 << limit;
    return max(sTable[limit][lll], sTable[limit][(rr-l)+1]);
}

void solve(){
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build_sTable();

    ll cnt = 0;
    while(q--){
        ll l, r;
        cin >> l >> r;
        l--; r--;
        if(arr[l] >= serarch_MAX(l, r-1)) cnt++;
    }
    cout << cnt << endl;
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}