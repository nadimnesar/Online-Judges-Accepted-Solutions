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

int dx[] = { +1, -1, +0, +0 };
int dy[] = { +0, +0, +1, -1 };

int n, m;
vector < string > grid;
char land, water;
int cnt;

bool valid(int r, int c){
    if(r < 0 or r >= n) return false;
    if(c < 0 or c >= m) return false;
    if(grid[r][c] == water) return false;
    return true;
}

void dfs(int r, int c){
    if(c == 0){
        int p = r;
        int q = m-1;
        if(valid(p, q)){
            grid[p][q] = water;
            cnt++;
            dfs(p, q);
        }
    }
    for(int i = 0; i < 4; i++){
        int p = dx[i]+r;
        int q = dy[i]+c;
        if(valid(p, q)){
            grid[p][q] = water;
            cnt++;
            dfs(p, q);
        }
    }
}

void solve(){
    while(cin >> n >> m){
        grid.clear();
        string temp;
        for(int i = 0; i < n; i++){
            cin >> temp;
            grid.pb(temp);
        }
        int x, y; cin >> x >> y;
        land = grid[x][y];

        bool flag = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != land){
                    water = grid[i][j];
                    flag = true;
                }
                if(flag) break;
            }
            if(flag) break;
        }

        cnt = 1;
        grid[x][y] = water;
        dfs(x, y);

        int result = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == land){
                    cnt = 1;
                    grid[i][j] = water;
                    dfs(i, j);
                    result = max(result, cnt);
                }
            }
        }
        cout << result << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}
