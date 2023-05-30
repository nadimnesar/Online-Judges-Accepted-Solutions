#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                "\n"
#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define pqueue              priority_queue<ll,vector<ll>,greater<ll>>
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(1e5+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

ll dp[maxx];

ll n;
vector < ll > arr;

ll BT(ll pos){
    if(pos >= n-1) return 0;

    if(dp[pos] != -1) return dp[pos];

    if(pos < n-2) return dp[pos] = min(BT(pos+1) + abs(arr[pos]-arr[pos+1]), BT(pos+2) + abs(arr[pos]-arr[pos+2]));
    else return dp[pos] = BT(pos+1) + abs(arr[pos]-arr[pos+1]);
}

void solve() {
    cin >> n;

    arr.clear();
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        arr.pb(temp);
    }

    memset(dp, -1, sizeof(dp));

    cout << BT(0) << endl;
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // int t, cn = 0;
    // cin >> t;
    // while(t--){
    //     // cout << "Case #" << ++cn << ": ";
    //     solve();
    // }

    solve();

    return 0;
}