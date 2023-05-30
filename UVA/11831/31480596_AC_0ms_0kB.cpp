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

int n, m, s;
char grid[101][101];

int dx[] = { -1, +0, +1, +0 };
int dy[] = { +0, +1, +0, -1 };

bool valid(int x, int y){
    if(x < 0 or x >= n) return false;
    if(y < 0 or y >= m) return false;
    if(grid[x][y] == '#') return false;
    return true;
}


void solve(){
    string temp, str;
    while(cin >> n >> m >> s){
        if(!n and !m and !s) break;
        int si, sj;
        int compus; // 0(north) 1(east) 2(south) 3(west)
        for(int i = 0; i < n; i++){
            cin >> temp;
            for(int j = 0; temp[j]; j++){
                grid[i][j] = temp[j];
                if(temp[j] == 'N'){
                    si = i; sj = j;
                    compus = 0;
                }
                if(temp[j] == 'S'){
                    si = i; sj = j;
                    compus = 2;
                }
                if(temp[j] == 'L'){
                    si = i; sj = j;
                    compus = 1;
                }
                if(temp[j] == 'O'){
                    si = i; sj = j;
                    compus = 3;
                }
            }
        }

        cin >> str;
        int res = 0;
        for(int i = 0; i < s; i++){ // 0(north) 1(east) 2(south) 3(west)
            if(str[i] == 'D'){
                compus++;
                if(compus > 3) compus = 0;
            }
            else if(str[i] == 'E'){
                compus--;
                if(compus < 0) compus = 3;
            }
            else{
                int p = si+dx[compus];
                int q = sj+dy[compus];
                if(valid(p, q)){
                    // debug(p, q, compus);
                    if(grid[p][q] == '*'){
                        res++;
                        grid[p][q] = '.';
                        // debug(p, q);
                    }
                    si = p;
                    sj = q;

                }
            }
        }

        cout << res << endl;
    }
}

int main(){
    fastIO;
    solve();
    return 0;
}