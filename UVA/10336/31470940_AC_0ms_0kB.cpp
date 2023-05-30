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

int n, m;
char current;
vector < string > grid;

int dx[] = { +1, -1, +0, +0 };
int dy[] = { +0, +0, +1, -1 };

bool valid(int x, int y){
    if(x < 0 or x >= n) return false;
    if(y < 0 or y >= m) return false;
    if(grid[x][y] == '*') return false;
    else if(grid[x][y] != current) return false;
    else return true;
}

void dfs(int r, int c){
    for(int i = 0; i < 4; i++){
        int p = dx[i]+r;
        int q = dy[i]+c;
        if(valid(p, q)){
            grid[p][q] = '*';
            dfs(p, q);
        }
    }
}

bool cmp(pair < int, char > x, pair < int, char > y){
    if(x.ff > y.ff) return true;
    else if(x.ff < y.ff) return false;
    else{
        if(x.ss < y.ss) return true;
        else if(x.ss > y.ss) return false;
        else return false;
    }
}

void solve(){
    int t, cn = 0; cin >> t;
    string temp;

    while(t--){
        cin >> n >> m;

        for(int i = 0; i < n; i++){
            cin >> temp;
            grid.pb(temp);
        }
        map < char, int > feq;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != '*'){
                    current = grid[i][j];
                    grid[i][j] = '*';
                    dfs(i, j);
                    feq[current]++;
                }
            }
        }

        vector < pair < int, char > > res;
        for(auto it: feq){
            res.pb({it.ss, it.ff});
        }
        sort(full(res), cmp);

        cout << "World #" << ++cn << endl;

        for(int i = 0; i < res.size(); i++){
            cout << res[i].ss << ": " << res[i].ff << endl;
        }

        grid.clear();
    }
}

int main(){
    fastIO;
    solve();
    return 0;
}