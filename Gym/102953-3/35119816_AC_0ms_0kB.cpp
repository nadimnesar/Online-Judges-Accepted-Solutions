#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e5+7)                           
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){
    ll n;
    cin >> n;
    vector < ll > tree[n+1];
    for(ll i = 0; i < n-1; i++){
        ll u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    ll res = 0;
    for(ll i = 2; i <= n; i++){
        if(tree[i].size() == 1){
            if(tree[i][0] != 1 and tree[tree[i][0]].size() == 2) res++;
        }
    }
    cout << res << endl;
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}
