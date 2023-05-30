#include <bits/stdc++.h>
using namespace std;

#define llu                 long long unsigned int
#define ll                  long long int

#define ff                  first
#define ss                  second
#define pb                  push_back
#define popb                pop_back
#define in                  insert

#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define dot(x)              fixed<<setprecision(x)

#define EPS                 (double)(1e-7)
#define MAX                 (ll)(1e5+7)
#define MOD                 (ll)(1e9+7)
#define PI                  (double)(acos(-1.0))
#define LOG(b, x)           (double)(log(x)/log(b))
#define INF                 (0x3f3f3f3f)

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

bool cmp(pair < int, int > x, pair < int, int > y){
    if(x.second == y.second) return (x.first < y.first);
    return (x.second < y.second); 
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        ll n, k, m;
        cin >> n >> k >> m;

        vector < pair < int, int > > arr;
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            arr.pb({x, y});
        }
        sort(full(arr), cmp);
        vector < int > res;
        for(int i = 0; i < n; i++) res.pb(i);

        for(int i = 0; i < k; i++){
            if(arr[i].first + 1 >= n) continue;
            if(i<k-1&&arr[i].first==arr[i+1].first) continue;
            swap(res[arr[i].first], res[arr[i].first + 1]);
        }
        vector < int > final(n);
        for(int i = 0; i < n; i++){
            final[res[i]] = i;
        }
        for(int i = 0; i < n; i++){
            cout << final[i] << endl;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}