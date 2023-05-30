#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

int dx[9] = { +0, +0, +1, +1, -1, -1, +1, -1 };
int dy[9] = { +1, -1, +1, -1, -1, +1, +0, +0 };

void solve(){
    int cn = 0;
    int n, m;
    bool ok = false;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;

        if(ok) cout << endl;
        ok = true;

        vector < string > grid(n);
        for(int i = 0; i < n; i++) cin >> grid[i];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '.'){
                    int res = 0;
                    for(int k = 0; k < 8; k++){
                        int p = i+dx[k];
                        int q = j+dy[k];
                        if(p < 0) continue;
                        if(p >= n) continue;
                        if(q < 0) continue;
                        if(q >= m) continue;

                        if(grid[p][q] == '*'){
                            res++;
                        }
                    }
                    grid[i][j] = res+'0';
                }
            }
        }
        cout << "Field #" << ++cn << ":" << endl;
        for(int i = 0; i < n; i++){
            cout << grid[i] << endl;
        }
    }
}

int main(){
    solve();
    return 0;
}
