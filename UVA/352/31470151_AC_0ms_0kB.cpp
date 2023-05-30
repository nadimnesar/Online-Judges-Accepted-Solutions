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

int n;
int war[26][26];

int dx[] = { +1, -1, +0, +0, +1, +1, -1, -1 };
int dy[] = { +0, +0, +1, -1, +1, -1, +1, -1 };

bool valid(int x, int y){
    if(x < 0 or x >= n) return false;
    if(y < 0 or y >= n) return false;
    if(war[x][y] == 0) return false;
    else return true;
}

void dfs(int r, int c){
    for(int i = 0; i < 8; i++){
        int p = dx[i]+r;
        int q = dy[i]+c;
        if(valid(p, q)){
            war[p][q] = 0;
            dfs(p, q);
        }
    }
}

void solve(){
    string temp;
    int cn = 0;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> temp;
            for(int j = 0; temp[j]; j++){
                if(temp[j] == '0') war[i][j] = 0;
                else war[i][j] = 1;
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(war[i][j] == 1){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << "Image number " << ++cn << " contains " << cnt << " war eagles." << endl;
    }
}
 
int main(){
    fastIO;
    solve();
    return 0;
}