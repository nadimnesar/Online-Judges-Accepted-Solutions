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

int t;
int n, m;
vector < string > grid;

int dx[] = { +1, -1, +0, +0 };
int dy[] = { +0, +0, +1, -1 };

bool valid(int x, int y){
    if(x < 0 or x >= n) return false;
    if(y < 0 or y >= m) return false;
    if(grid[x][y] == '1') return false;
    return true;
}

int cnt;
void dfs(int r, int c){
    for(int i = 0; i < 4; i++){
        int p = dx[i]+r;
        int q = dy[i]+c;
        if(valid(p, q)){
            grid[p][q] = '1';
            cnt++;
            dfs(p, q);
        }
    }
}

int si, sj;
void magic(){
    n = grid.size();
    m = grid[0].size();
    cnt = 1;
    grid[si][sj] = '1';
    dfs(si, sj);
    cout << cnt << endl;
    grid.clear();
}

void solve(){
    cin >> t;
    cin.ignore();

    string str;
    getline(cin, str);

    bool flag = true, br = false;

    while(getline(cin, str)){
        if(flag){
            si = 0; sj = 0;
            int i = 0;
            for(; str[i]; i++){
                if(str[i] == ' ') break;
                else si = (si*10) + (str[i]-'0');
            }
            for(++i; str[i]; i++){
                if(str[i] == ' ') break;
                else sj = (sj*10) + (str[i]-'0');
            }
            flag = false;
            si--;
            sj--;
            continue;
        }
        if(str.size()) grid.pb(str);
        else{
            magic();
            cout << endl;
            flag = true;
        }
    }
    magic();
}

int main(){
    fastIO;
    solve();
    return 0;
}