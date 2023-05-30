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

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

vector < ll > cube;
map < ll, int > um;
void solve(){
    for(ll i = 1; i <= 1001; i++) cube.pb(i*i*i);
    for(ll i = 0; i < cube.size(); i++){
        for(ll j = i+1; j < cube.size(); j++){
            um[cube[i]+cube[j]]++;
        }
    }
    vector < ll > taxicab;
    for(auto it: um){
        if(it.second >= 2) taxicab.pb(it.first);
    }

    ll n, r;
    while(cin >> n >> r){
        ll left = n, right = n+r;
        bool flag = 0;
        for(ll i = 0; i < taxicab.size(); i++){
            if(taxicab[i] >= left and taxicab[i] <= right){
                flag = 1;
                cout << taxicab[i] << endl;
            }
        }
        if(!flag) cout << "None" << endl;
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    //ll t; cin >> t;
    //while(t--) solve();

    solve();

    
    return 0;
}