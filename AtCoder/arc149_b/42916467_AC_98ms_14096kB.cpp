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

void solve() {
  ll n;
  cin >> n;

  vector < ll > a;
  for (ll i = 0; i < n; i++) {
    ll temp;
    cin >> temp;
    a.pb(temp);
  }

  vector < pair < ll, ll > > b;
  for (ll i = 0; i < n; i++) {
    ll temp;
    cin >> temp;
    b.pb({a[i], temp});
  }

  sort(full(b));

  vector < ll > v;
  for (ll i = 0; i < b.size(); i++) {
    auto it = lower_bound(full(v), b[i].second);
    if (v.end() == it) v.pb(b[i].second);
    else v[it - v.begin()] = b[i].second;
  }

  cout << n + v.size() << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}