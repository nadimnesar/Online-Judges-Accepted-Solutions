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

void solve() {
  ll n, m;
  cin >> n >> m;

  vector < string > grid;
  for(ll i = 0; i < n; i++){
    string s;
    cin >> s;
    grid.pb(s);
  }

  bool sb = true;

  for(ll i = 0; i < n; i++){
    bool b = sb;
    for(ll j = 0; j < m; j++){
      if(grid[i][j] == '.'){
        if(b) grid[i][j] = 'B';
        else grid[i][j] = 'W';
      }
      b = !b;
    }
    sb = !sb;
  }

  for(ll p = 0; p < n; p++){
    for(ll q = 0; q < m; q++){
      cout << grid[p][q];
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}