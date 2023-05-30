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
int dp[maxx][maxx];

int BT(int i, int j){
    if(i == x.size()) return 0;
    if(j == y.size()) return 0;

    if(~dp[i][j]) return dp[i][j];

    if(x[i] == y[j]) return dp[i][j] = 1+BT(i+1, j+1);
    else return dp[i][j] = max(BT(i+1, j), BT(i, j+1));
}

void solve(){
    while(getline(cin, x)){
        getline(cin, y);
        memset(dp, -1, sizeof(dp));
        cout << BT(0, 0) << endl;
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}