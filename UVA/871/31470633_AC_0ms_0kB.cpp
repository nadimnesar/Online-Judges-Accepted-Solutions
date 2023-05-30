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

int n, m, cnt;
vector < string > grid;

int dx[] = { +1, -1, +0, +0, +1, +1, -1, -1 };
int dy[] = { +0, +0, +1, -1, +1, -1, +1, -1 };

bool valid(int x, int y){
    if(x < 0 or x >= n) return false;
    if(y < 0 or y >= m) return false;
    if(grid[x][y] == '0') return false;
    else return true;
}

void dfs(int r, int c){
    for(int i = 0; i < 8; i++){
        int p = dx[i]+r;
        int q = dy[i]+c;
        if(valid(p, q)){
            grid[p][q] = '0';
            cnt++;
            dfs(p, q);
        }
    }
}

void solve(){
    int t;
    cin >> t;
    cin.ignore();

    string temp;
    getline(cin, temp);

    while(t--){

        while(getline(cin, temp)){
            if(temp.size()) grid.pb(temp);
            else break;
        }

        n = grid.size();
        m = grid[0].size();

        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    cnt = 1;
                    dfs(i, j);
                    maxi = max(maxi, cnt);
                }
            }
        }
        cout << maxi << endl;
        if(t) cout << endl;

        grid.clear();
    }
}

int main(){
    fastIO;
    solve();
    return 0;
}