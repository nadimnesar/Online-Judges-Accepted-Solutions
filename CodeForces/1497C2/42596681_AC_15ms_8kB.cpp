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
  ll n, k;
  cin >> n >> k;

  for (ll i = 0; i < k - 3; i++) {
    cout << 1 << ' ';
    n--;
  }

  if (n % 3 == 0) cout << n / 3 << ' ' << n / 3 << ' ' << n / 3 << endl;
  else if (n % 2 == 1) cout << n / 2 << ' ' << n / 2 << ' ' << 1 << endl;
  else{
    ll x = n/2;
    if(x&1) cout << (n/2)-1 << ' ' << (n/2)-1 << ' ' << 2 << endl;
    else cout << x << ' ' << x/2 << ' ' << x/2 << endl;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) solve();

  return 0;
}