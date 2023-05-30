#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define For(x,y)         for(ll i = (int)x; i < (int)y; i++)
#define rFor(x,y)        for(ll i = (int)x; i => (int)y; i--)

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y))) //for sorted array

#define EPS              (1e-7)
#define MAX              (100007)
#define MOD              (1000000007)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

int dx[] = { +0, +0, +1, -1, -1, +1, +1, -1 };
int dy[] = { +1, -1, +0, +0, -1, +1, -1, +1 };

int r, c;
char board[105][105];

bool valid(int x, int y){
    if(x < 0 or x >= r) return false;
    if(y < 0 or y >= c) return false;
    if(board[x][y] == '*') return true;
    else return false;
}

void solve(){
    bool br = false;
    int field = 0;
    while(cin >> r >> c){
        if(r == 0 and c == 0) break;
        if(br) cout << endl;
        else br = true;
        for(int  i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> board[i][j];
            }
        }
        for(int  i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == '.'){
                    int cnt = 0;
                    for(int k = 0; k < 8; k++){
                        int p = i+dx[k];
                        int q = j+dy[k];
                        if(valid(p, q)) cnt++;
                    }
                    board[i][j] = cnt+48;
                }
            }
        }
        cout << "Field #" << ++field << ":" << endl;
        for(int  i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cout << board[i][j];
            }
            cout << endl;
        }
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef NADIMNESAR
    clock_t tStart = clock();
    freopen("Input.txt", "r", stdin); freopen("Output.txt", "w", stdout);
#endif

    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }

#ifdef NADIMNESAR
    fprintf(stderr, "\n>> Runtime: %.3fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}