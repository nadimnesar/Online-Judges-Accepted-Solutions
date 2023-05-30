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

int n, goal, skip;
bool can;

bool graph[101][101];
bool res[101][101];
bool flag[101];
bool canvisit[101];

void dfs(int idx){
    if(can) return;
    if(idx == skip) return;
    if(idx == goal){ can = true; return; }
    if(!flag[idx]){
        flag[idx] = true;
        for(int i = 0; i < n; i++){
            if(graph[idx][i]) dfs(i);
        }
    }
}

void checkerdfs(int idx){
    if(!canvisit[idx]){
        canvisit[idx] = true;
        for(int i = 0; i < n; i++){
            if(graph[idx][i]) checkerdfs(i);
        }
    }
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];
    }
    memset(canvisit, false, sizeof(canvisit));
    checkerdfs(0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            can = false;
            goal = j;
            skip = i;
            
            memset(flag, false, sizeof(flag));
            dfs(0);

            if(can) res[i][j] = 0;
            else if(canvisit[j]) res[i][j] = 1;
            else res[i][j] = 0;
        }
    }

    int limit = (2*n)-1;
    for(int i = 0; i < n; i++){
        cout << '+';
        for(int k = 0; k < limit; k++) cout << '-';
        cout << '+' << endl;
        cout << '|';
        for(int j = 0; j < n; j++){
            if(res[i][j]) cout << 'Y' << '|';
            else cout << 'N' << '|';
        }
        cout << endl;
    }
    cout << '+';
    for(int k = 0; k < limit; k++) cout << '-';
    cout << '+' << endl;
}

int main(){
    fastIO;
    int t, cn = 0;
    cin >> t;
    while(t--){
        cout << "Case " << ++cn << ":" << endl;
        solve();
    }
    return 0;
}