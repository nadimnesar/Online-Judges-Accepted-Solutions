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

int n;
int cnt_h, cnt_v;

bool valid(int r, int c, vector < string > &temp){
    if(r < 0 or r >= n) return false;
    if(c < 0 or c >= n) return false;
    if(temp[r][c] == '.') return false;
    return true;
}

void dfs_h(int r, int c, vector < string > &temp){
    for(int i = 0; i < 2; i++){
        int p = dx[i]+r;
        int q = dy[i]+c;
        if(valid(p, q, temp)){
            temp[p][q] = '.';
            dfs_h(p, q, temp);
            cnt_h++;
        }
    }
}

void dfs_v(int r, int c, vector < string > &temp){
    for(int i = 2; i < 4; i++){
        int p = dx[i]+r;
        int q = dy[i]+c;
        if(valid(p, q, temp)){
            temp[p][q] = '.';
            dfs_v(p, q, temp);
            cnt_v++;
        }
    }
}

void solve(){
    cin >> n;
    vector < string > grid;
    string temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        grid.pb(temp);
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 'x'){

                vector < string > temp_h = grid;
                vector < string > temp_v = grid;

                cnt_h = 1;
                temp_h[i][j] = '.';
                dfs_h(i, j, temp_h);

                cnt_v = 1;
                temp_h[i][j] = '.';
                dfs_v(i, j, temp_v);

                if(cnt_v > cnt_h) dfs_v(i, j, grid);
                else dfs_h(i, j, grid);

                res++;
            }
        }
    }
    cout << res << endl;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int cn = 0, t; cin >> t;
    while(t--){
        cout << "Case " << ++cn << ": ";
        solve();
    }

    return 0;
}