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

int graph[50001];
bool Total_Visit[50001];
bool Cur_Visit[50001];
ll cnt;

void dfs(int i){
    if(Cur_Visit[graph[i]]) return;
    Cur_Visit[graph[i]] = true;
    Total_Visit[graph[i]] = true;
    cnt++;
    dfs(graph[i]);
}

void solve(){
    int t, cn = 0;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            int p, q;
            cin >> p >> q;
            graph[p] = q;
        }

        int maxi = 0;
        int res;

        memset(Total_Visit, false, sizeof(Total_Visit));

        for(int i = 1; i <= n; i++){
            if(!Total_Visit[i]){
                Total_Visit[i] = true;
                memset(Cur_Visit, false, sizeof(Cur_Visit));
                Cur_Visit[i] = true;
                cnt = 0;
                dfs(i);
                if(maxi < cnt){
                    res = i;
                    maxi = cnt;
                }
            }
        }
        cout << "Case " << ++cn << ": " << res << endl;
    }
}

int main(){
    fastIO;
    solve();
    return 0;
}