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

vector < pair < int, int > > cord;

vector < int > graph[1001];
bool flag[1001];
int cnt;

void dfs(int idx){
    if(!flag[idx]){
        flag[idx] = true;
        cnt++;
        for(int i = 0; i < graph[idx].size(); i++) dfs(graph[idx][i]);
    }
}

int distance(int x1, int y1, int x2, int y2){
    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

void solve(){

    
    int n;
    while(cin >> n and n){

        cord.clear();
        for(int i = 0; i < n; i++) graph[i].clear();
        memset(flag, false, sizeof(flag));

        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            cord.pb({x, y});
        }


        int mini, idx, dis;

        for(int i = 0; i < n; i++){
            mini = INT_MAX;
            for(int j = 0; j < n; j++){
                if(i == j) continue;

                dis = distance(cord[i].ff, cord[i].ss, cord[j].ff, cord[j].ss);
                if(mini == dis and cord[j].ff < cord[idx].ff) idx = j;
                if(dis < mini){
                    idx = j;
                    mini = dis;
                }
            }
            graph[i].pb(idx);
        }

        for(int i = 0; i < n; i++){
            mini = INT_MAX;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(j == graph[i][0]) continue;

                dis = distance(cord[i].ff, cord[i].ss, cord[j].ff, cord[j].ss);
                if(mini == dis and cord[j].ss < cord[idx].ss) idx = j;
                if(dis < mini){
                    idx = j;
                    mini = dis;
                }
            }
            graph[i].pb(idx);
        }

        cnt = 0;
        dfs(0);
        if(cnt == n) cout << "All stations are reachable." << endl;
        else cout << "There are stations that are unreachable." << endl;
    }
}
 

int main(){
    fastIO;
    solve();
    return 0;
}