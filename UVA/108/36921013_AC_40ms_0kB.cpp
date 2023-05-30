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

#define maxx                (ll)(1e2+7)
#define mod                 (ll)(1e7+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

ll n;
ll grid[maxx][maxx];
ll dp[maxx][maxx];

void solve() {
    
    for(ll i = 0; i < n; i++){
      for(ll j = 0; j < n; j++){
        cin >> grid[i][j];
        dp[i][j] = grid[i][j];
      }
    }

    for(ll i = 0; i < n; i++){
      for(ll j = 1; j < n; j++){
        dp[i][j] += dp[i][j-1];
      }
    }

    for(ll j = 0; j < n; j++){
      for(ll i = 1; i < n; i++){
        dp[i][j] += dp[i-1][j];
      }
    }


    ll maxi = LLONG_MIN;
    for(ll i = 0; i < n; i++){
      for(ll j = 0; j < n; j++){

        for(ll k = i; k < n; k++){
          for(ll p = j; p < n; p++){

            ll x = ((dp[k][p] - dp[i][j]) + grid[i][j]);

            if(i > 0) x -= (dp[i-1][p] - dp[i-1][j]);
            if(j > 0) x -= (dp[k][j-1] - dp[i][j-1]);

            maxi = max(maxi, x);
            
          }
        }

      }
    }

    cout << maxi << endl;
}

int main() {

    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // int t, cn = 0;
    // cin >> t;
    // while(t--){
    //     // cout << "Case #" << ++cn << ": ";
    //     solve();
    // }

  while(cin >> n){
    solve();
  }


  return 0;
}