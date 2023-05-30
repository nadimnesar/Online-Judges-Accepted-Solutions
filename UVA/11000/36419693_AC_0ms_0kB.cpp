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
  ll n;
  while(cin >> n){
    if(n == -1) break;

    ll male = 0;
    ll female = 0;
    ll emortal = 1;

    while(n--){

      ll new_female = 0;

      if(male) new_female += male;
      if(female) male += female;
      female = new_female;
      
      if(emortal) male++;
    }

    cout << male << ' ' << male+female+emortal << endl;
  }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}