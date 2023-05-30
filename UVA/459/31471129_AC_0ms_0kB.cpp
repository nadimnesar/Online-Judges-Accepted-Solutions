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

vector < int > graph[27];
bool flag[27];

void dfs(int v){
    for(int i = 0; i < graph[v].size(); i++){
        if(flag[graph[v][i]]) continue;
        flag[graph[v][i]] = true;
        dfs(graph[v][i]);
    }
}

void solve(){

    int t;
    cin >> t;
    cin.ignore();

    string temp;
    getline(cin, temp);

    while(t--){

        for(int i = 1; i <= 26; i++) graph[i].clear();

        int n;
        while(getline(cin, temp)){
            if(temp.size()){
                if(temp.size() == 1) n = (temp[0] - 'A')+1; 
                else{
                    graph[(temp[0] - 'A')+1].pb((temp[1] - 'A')+1);
                    graph[(temp[1] - 'A')+1].pb((temp[0] - 'A')+1);
                }
            }
            else break;
        }

        int cnt = 0;
        memset(flag, false, sizeof(flag));

        for(int i = 1; i <= n; i++){
            if(!flag[i]){
                cnt++;
                dfs(i);
            }
        }

        cout << cnt << endl;
        if(t) cout << endl;

    }
}
 
int main(){
    fastIO;
    solve();
    return 0;
}