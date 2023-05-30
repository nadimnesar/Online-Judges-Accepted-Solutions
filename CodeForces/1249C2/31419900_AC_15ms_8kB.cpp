#include <bits/stdc++.h>
using namespace std;
 
#define llu                 long long unsigned int
#define ll                  long long int
 
#define ff                  first
#define ss                  second
#define pb                  push_back
#define pob                 pop_back
#define in                  insert
#define pf                  printf
#define sf                  scanf
 
#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define rremove(x, y)       x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)       x.resize(distance(x.begin(),unique(x.begin(),x.begin()+y)))
#define fastIO              ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define EPS                 (1e-7)
#define MAX                 (1e5+7)
#define MOD                 (1e9+7)
#define PI                  (acos(-1.0))
#define LOG(b, x)           (log(x)/log(b))
 
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

llu binpow(llu n, llu p){
    if(p == 0) return 1;
    llu res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}

vector < ll > arr;
void magic(){
    for(ll i = 0; i <= 38; i++) arr.pb(binpow(3, i));
    // for(ll i = 0; i <= 38; i++) debug(arr[i]);
}

void solve(){
    ll n;
    cin >> n;
    ll big;
    ll res = 0;
    ll k = 0;
    
    for(ll i = 0; i < arr.size(); i++){
        if(arr[i] == n){
            big = arr[i];
            break;
        }
        if(arr[i] > n){
            big = arr[i];
            break;
        }
        if(arr[i] < n){
            res += arr[i];
            k = i;
        }
    }

    if(big == n) cout << big << endl;
    else{
        if(res >= n){
            for(; k >= 0; k--){
                ll p = res - arr[k];
                if(p >= n) res -= arr[k];
            }
            cout << res << endl;
        }
        else cout << big << endl;
    }
}

int main(){
    fastIO;
    magic();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
