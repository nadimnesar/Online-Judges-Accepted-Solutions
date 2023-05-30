#include <bits/stdc++.h>
using namespace std;

#define ll              long long int
#define endl            '\n'
#define in              insert
#define pb              push_back

#define full(x)         x.begin(),x.end()
#define dot(x)          fixed<<setprecision(x)

#define gcd(x, y)       (ll)(__gcd(x, y))
#define lcm(x, y)       (ll)((x/gcd(x,y))*y)
#define log(b, x)       (double)(log(x)/log(b))

const ll mod = 1e9 + 7;
const ll maxx = 1e6 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-7;
const double pi = acos(-1.0);

ll dx[] = { 0,  0, 1, -1 };
ll dy[] = { 1, -1, 0,  0 };

void solve() {
  string s;
  cin >> s;

  if(s.size() == 1){
    cout << "OK" << endl;
    return;
  }

  ll x, y;
  x = 0;
  y = 0;
  for(ll i = 0; i < s.size(); i++){

    ll p, q;
    p = x; q = y;

    ll mv = 0;
    for(ll j = i; j < s.size(); j++){
      if(s[j] == 'L') p--;
      else if(s[j] == 'R') p++;
      else if(s[j] == 'U') q++;
      else q--;
      mv++;

      for(ll k = 0; k < 4; k++){
        if(p == x+dx[k] and q == y+dy[k] and mv > 1){
          cout << "BUG" << endl;
          return;
        }
      }

      if(p == x and q == y and mv > 0){
        cout << "BUG" << endl;
        return;
      }
    }

    if(s[i] == 'L') x--;
    else if(s[i] == 'R') x++;
    else if(s[i] == 'U') y++;
    else y--;
  }

  cout << "OK" << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}