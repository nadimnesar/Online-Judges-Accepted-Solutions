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
vector < string > visited;

int dx[] = { +1, -1, +0, +0, +1, +1, -1, -1 };
int dy[] = { +0, +0, +1, -1, +1, -1, +1, -1 };

bool valid(int x, int y){
    if(x < 0 or x >= n) return false;
    if(y < 0 or y >= m) return false;
    if(visited[x][y] == 'L') return false;
    else return true;
}

void dfs(int r, int c){
    for(int i = 0; i < 8; i++){
        int p = dx[i]+r;
        int q = dy[i]+c;
        if(valid(p, q)){
            visited[p][q] = 'L';
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
            if(temp.size()){
                if(temp[0] >= '0' and temp[0] <= '9'){
                    n = grid.size();
                    m = grid[0].size();
                    visited = grid;
                    int x = 0;
                    int y = 0;
                    int i = 0;
                    for(; temp[i]; i++){
                        if(temp[i] == ' ') break;
                        x = (x*10) + (temp[i] - '0');
                    }
                    for(++i; temp[i]; i++){
                        if(temp[i] == ' ') break;
                        y = (y*10) + (temp[i] - '0');
                    }
                    cnt = 1;
                    visited[x-1][y-1] = 'L';
                    dfs(x-1, y-1);
                    cout << cnt << endl;
                }
                else grid.pb(temp);
            }
            else break;
        }
        grid.clear();

        if(t) cout << endl;
    }
}

int main(){
    fastIO;
    solve();
    return 0;
}