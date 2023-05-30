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
int cnt;

bool valid(int r, int c){
    if(r < 0 or r >= n) return false;
    if(c < 0 or c >= m) return false;
    if(grid[r][c] == '.') return false;
    return true;
}

bool valid_x(int r, int c){
    if(r < 0 or r >= n) return false;
    if(c < 0 or c >= m) return false;
    if(grid[r][c] == '*') return false;
    if(grid[r][c] == '.') return false;
    return true;
}

void dfs_x(int r, int c){
    for(int i = 0; i < 4; i++){
        int p = dx[i]+r;
        int q = dy[i]+c;
        if(valid_x(p, q)){
            grid[p][q] = '*';
            dfs_x(p, q);
        }
    }
}

void dfs(int r, int c){
    for(int i = 0; i < 4; i++){
        int p = dx[i]+r;
        int q = dy[i]+c;
        if(valid(p, q)){
            if(grid[p][q] == 'X'){
                grid[p][q] = '*';
                dfs_x(p, q);
                cnt++;
            }
            grid[p][q] = '.';
            dfs(p, q);
        }
    }
}

void dfs_arkoto(int r, int c){
    for(int i = 0; i < 4; i++){
        int p = dx[i]+r;
        int q = dy[i]+c;
        if(valid_x(p, q)){
            grid[p][q] = '.';
            dfs_arkoto(p, q);
        }
    }
}


void solve(){
    int cn = 0;
    while(cin >> m >> n){
        if(n == 0 and m == 0) break;

        grid.clear();

        cout << "Throw " << ++cn << endl;

        string temp;
        for(int i = 0; i < n; i++){
            cin >> temp;
            grid.pb(temp);
        }

        vector < int > res;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '*'){
                    grid[i][j] = '.';
                    cnt = 0;
                    dfs(i, j);
                    res.pb(cnt);
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'X'){
                    grid[i][j] = '.';
                    dfs_arkoto(i, j);
                    res.pb(1);
                }
            }
        }

        sort(full(res));
        for(int i = 0; i < res.size(); i++){
            if(i+1 == res.size()) cout << res[i] << endl;
            else cout << res[i] << ' ';
        }
        cout << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}