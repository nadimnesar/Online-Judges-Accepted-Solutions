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

vector < int > graph[101];
bool flag[101];
int cnt;
void dfs(int v){
    for(int i = 0; i < graph[v].size(); i++){
        if(flag[graph[v][i]]) continue;
        flag[graph[v][i]] = true;
        cnt--;
        dfs(graph[v][i]);
    }
}

void solve(){
    int n;
    while(cin >> n and n){
        for(int i = 1; i <= n; i++) graph[i].clear();
        int p, q;
        while(cin >> p and p){
            while(cin >> q and q) graph[p].pb(q);
        }
        int t;
        cin >> t;
        while(t--){
            int s;
            cin >> s;
            memset(flag, false, sizeof(flag));
            cnt = n;
            dfs(s);
            cout << cnt;
            for(int i = 1; i <= n; i++)
                if(flag[i] == false) cout << ' ' << i;
            cout << endl;
        }
    }
}
 
int main(){
    fastIO;
    solve();
    return 0;
}