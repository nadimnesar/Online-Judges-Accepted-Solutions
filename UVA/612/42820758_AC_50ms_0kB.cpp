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

vector < string > graph[5001];

void solve() {
  ll s, n;
  cin >> s >> n;

  vector < string > v;
  for (ll i = 0; i < n; i++) {
    string str;
    cin >> str;
    v.pb(str);
  }

  for (ll i = 0; i < v.size(); i++) {
    ll total = 0;
    for (ll j = 0; j < s; j++) {
      ll cnt = 0;
      for (ll k = j + 1; k < s; k++) {
        if (v[i][k] < v[i][j]) {
          cnt++;
        }
      }
      total += cnt;
    }
    graph[total].pb(v[i]);
  }

  for (ll i = 0; i < 5001; i++) {
    for(ll j = 0; j < graph[i].size(); j++){
      cout << graph[i][j] << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ll t;
  cin >> t;
  bool bl = false;
  while (t--){

    if(bl) cout << endl;
    else bl = true;

    solve();

    for (ll i = 0; i < 5001; i++) graph[i].clear();
  }

  return 0;
}