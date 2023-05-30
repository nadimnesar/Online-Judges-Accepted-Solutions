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

int dx[] = { +1, +0, -1, -0 };
int dy[] = { +0, +1, -0, -1 };
int n, sum;

int squre[11][11];
bool visited[11][11];

bool valid(int r, int c){
    if(r < 0 or r >= n) return false;
    if(c < 0 or c >= n) return false;
    if(visited[r][c]) return false;
    return true;
}

void count(int x, int y, int idx){

    if(idx > 3) return;

    if(!visited[x][y]){
        visited[x][y] = true;
        sum += squre[x][y];
    }

    int p = x+dx[idx];
    int q = y+dy[idx];

    if(valid(p, q)) count(p, q, idx);
    else count(x, y, idx+1);
}

void solve(){
    int cn = 0;
    while(cin >> n and n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> squre[i][j];
            }
        }
        memset(visited, false, sizeof(visited));

        cout << "Case " << ++cn << ":";

        int x = 0, y = 0;
        while(valid(x, y) and !visited[x][y]){
            sum = 0;
            count(x, y, 0);
            cout << ' ' << sum;
            x++;
            y++;
        }
        cout << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}