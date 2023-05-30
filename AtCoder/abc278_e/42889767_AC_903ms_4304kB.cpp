#include <bits/stdc++.h>
using namespace std;

#define ll              long long int
#define endl            '\n'
#define in              insert
#define pb              push_back

#define full(x)         x.begin(),x.end()
#define memset(x, y)    memset(x,y,sizeof(x))
#define dot(x)          fixed<<setprecision(x)

#define gcd(x, y)       (ll)(__gcd(x, y))
#define lcm(x, y)       (ll)((x/gcd(x,y))*y)
#define log(b, x)       (double)(log(x)/log(b))

const ll mod = 1e9 + 7;
const ll maxx = 1e6 + 7;
const double eps = 1e-7;
const double pi = acos(-1.0);

ll dx[] = { 0, 0, 1, -1 };
ll dy[] = { 1, -1, 0, 0 };

ll grid[301][301];
ll mp[301];

void solve() {
  ll n, m, k, h, w;
  cin >> n >> m >> k >> h >> w;

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> grid[i][j];
      mp[grid[i][j]]++;
    }
  }

  for (ll i = 0; i <= n - h; i++) {
    for (ll j = 0; j <= m - w; j++) {

      for (ll p = i; p < i + h; p++) {
        for (ll q = j; q < j + w; q++) {
          mp[grid[p][q]]--;
        }
      }

      ll cnt = 0;
      for(ll d = 1; d <= k; d++){
        if(mp[d]) cnt++;
      }

      if (j == m - w) cout << cnt << endl;
      else cout << cnt << ' ';

      for (ll p = i; p < i + h; p++) {
        for (ll q = j; q < j + w; q++) {
          mp[grid[p][q]]++  ;
        }
      }
      
    }
  }

}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}