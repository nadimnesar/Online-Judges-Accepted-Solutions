#include <bits/stdc++.h>
using namespace std;
 
#define llu                 long long unsigned int
#define ll                  long long int
 
#define ff                  first
#define ss                  second
#define pb                  push_back
#define popb                pop_back
#define in                  insert
#define pf                  printf
#define sf                  scanf

#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define dot(x)              fixed<<setprecision(x)

#define EPS                 (double)(1e-7)
#define MAX                 (ll)(1e5+7)
#define MOD                 (ll)(1e9+7)
#define PI                  (double)(acos(-1.0))
#define LOG(b, x)           (double)(log(x)/log(b))
 
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

vector < int > node[201];
int flag[201];
bool res;

void DFS(int u, int color){
    if(!res) return;

    for(int i = 0; i < node[u].size(); i++){
        
        int colorbad;
        if(color == 1) colorbad = 2;
        else colorbad = 1;

        if(flag[node[u][i]] == colorbad){
            res = false;
            return;
        }

        if(flag[node[u][i]] == 0){
            flag[node[u][i]] = color;
            DFS(node[u][i], colorbad);
        }
    }
}

void solve(){

    int n, e;
    while(cin >> n and n){
        cin >> e;
        for(int i = 0; i <= n; i++) node[i].clear();
        memset(flag, 0, sizeof(flag));

        for(int i = 0; i < e; i++){
            int u, v;
            cin >> u >> v;
            node[u].pb(v);
            node[v].pb(u);
        }

        res = true;

        for(int i = 0; i < n; i++){
            if(flag[i] == 0){
                flag[i] = 1;
                DFS(i, 2);
            }
        }

        if(res) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}