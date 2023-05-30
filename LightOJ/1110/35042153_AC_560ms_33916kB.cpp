#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e3+7)                           
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

string x, y;
bool visit[maxx][maxx];
string dp[maxx][maxx];

string BT(int i, int j){
    if(i == x.size() or j == y.size()) return "";

    if(visit[i][j]) return dp[i][j];
    else visit[i][j] = true;

    if(x[i] == y[j]) return dp[i][j] = x[i] + BT(i+1, j+1);
    else{
        string a = BT(i+1, j);
        string b = BT(i, j+1);

        if(a.size() > b.size()) return dp[i][j] = a;
        else if(a.size() < b.size()) return dp[i][j] = b;
        else{
            if(a < b) return dp[i][j] = a;
            else return dp[i][j] = b;
        }
    }
}

void solve(){
    ll t, cn = 0;
    cin >> t;
    while(t--){
        cin >> x >> y;
        memset(visit, false, sizeof(visit));
        for(int i = 0; i < maxx; i++){
            for(int j = 0; j < maxx; j++){
                dp[i][j].clear();
            }
        }

        cout << "Case " << ++cn << ": ";
        string res = BT(0, 0);

        if(res.size()) cout << res << endl;
        else cout << ":(" << endl;
    }
}

int main(){
 
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}