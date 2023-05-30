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
#define fastIO              ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
 
#define EPS                 (1e-7)
#define MAX                 (1e6+7)
#define MOD                 (1e9+7)
#define PI                  (acos(-1.0))
#define LOG(b, x)           (log(x)/log(b))
 
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

int learn[1001];
vector < int > graph[1001];
bool flag[101];

ll maxi;
ll last;

void dfs(int v, int sum){
    if(flag[v]) return;
    flag[v] = true;
    if(sum >= maxi){ last = v; maxi = sum; }
    
    if(graph[v].size() == 0) return;

    int maxii = 0, u;
    bool found = false;

    for(int i = 0; i < graph[v].size(); i++){
        if(maxii <= learn[graph[v][i]]){
            u = graph[v][i];
            maxii = learn[graph[v][i]];
        }
    }
    dfs(u, sum+maxii);
}

void solve(){
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < n; i++) cin >> learn[i];

    for(int i = 0; i < n; i++) graph[i].clear();
    memset(flag, false, sizeof(flag));

    for(int i = 0; i < e; i++){
        int x, y; cin >> x >> y;
        graph[x].pb(y);
    }
    
    maxi = 0;
    dfs(0, learn[0]);
    cout << maxi << ' ' << last << endl;
}

int main(){
    fastIO;
    int t, cn = 0;
    cin >> t;
    while(t--){
        cout << "Case " << ++cn << ": ";
        solve();
    }
    return 0;
}