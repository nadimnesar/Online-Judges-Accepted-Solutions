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
#define MAX                 (4e4+7)
#define MOD                 (1e9+7)
#define PI                  (acos(-1.0))
#define LOG(b, x)           (log(x)/log(b))
 
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

void solve(){
    ll n;
    cin >> n;
    vector < ll > arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    bool love = false;
    for(int i = 1; i <= n; i++){
        ll x = arr[i];
        ll y = arr[x];
        ll z = arr[y];
        if(y != i and z == i) love = true;
    }
    if(love) cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
int main(){
    fastIO;
    solve();
    return 0;
}