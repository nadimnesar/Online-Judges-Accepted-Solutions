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

vector < string > x, y;
bool visit[maxx][maxx];
string dp[maxx][maxx];

string uni_max(string a, string b){
    int cnt_a = 0, cnt_b = 0;
    for(int i = 0; a[i]; i++){
        if(a[i] == ' ') cnt_a++;
    }
    for(int i = 0; b[i]; i++){
        if(b[i] == ' ') cnt_b++;
    }
    if(cnt_a > cnt_b) return a;
    else return b;
}


string BT(int i, int j){
    if(i == x.size() or j == y.size()) return "";

    if(visit[i][j]) return dp[i][j];
    else visit[i][j] = true;

    if(x[i] == y[j]) return dp[i][j] = x[i] + " " + BT(i+1, j+1);
    else return dp[i][j] = uni_max(BT(i+1, j), BT(i, j+1));
}

void solve(){
    ll cnt = 0;
    string temp;
    while(cin >> temp){
        if(temp == "#") cnt++;

        if(cnt == 2){

            memset(visit, false, sizeof(visit));
            for(int i = 0; i < maxx; i++){
                for(int j = 0; j < maxx; j++){
                    dp[i][j].clear();
                }
            }

            cnt = 0;

            string res = BT(0, 0);
            res.ppb();
            cout << res << endl;
            x.clear();
            y.clear();
            continue;
        }

        if(cnt == 0) x.pb(temp);
        if(cnt == 1) y.pb(temp);
    }
}

int main(){
 
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}
