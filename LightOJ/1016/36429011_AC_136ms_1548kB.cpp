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
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){ 

  ll t, dis;
  cin >> t;
  ll cn = 0;
  while(t--){
    ll n, w;
    cin >> n >> w;

    vector < ll > all_y;
    for(ll i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        all_y.pb(y);
    }

    cout << "Case " << ++cn << ": ";

    if(n == 1){
        cout << 1 << endl;
        continue;
    }

    sort(full(all_y));
    
    ll res = 0;
    for(ll i = 0; i < n; i++){
      if(i+1 == n){
        res++;
        break;
      }

      bool flag = false;
      for(ll j = i+1; j < n; j++){
          dis = (all_y[j] - all_y[i]);
          if(dis > w){
              res++;
              i = j-1;
              flag = true;
              break;
          }
      }

      if(!flag){
          res++;
          break;
      }
    }
    
    cout << res << endl;
  }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}