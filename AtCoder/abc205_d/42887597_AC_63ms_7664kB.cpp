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

typedef struct node
{
  ll left, right, idx;
} node;

void solve() {
  ll n, q;
  cin >> n >> q;

  vector < ll > v;
  for (ll i = 0; i < n; i++) {
    ll temp;
    cin >> temp;
    v.pb(temp);
  }

  sort(full(v));

  ll pre = 0;
  vector < node > v2;
  for (ll i = 0; i < n; i++) {
    if (i == 0) {
      if (v[i] != 1) {
        node tmp;
        tmp.left = 1;
        tmp.right = tmp.idx = pre = v[i] - 1;
        v2.pb(tmp);
      }

      if (i < n - 1 and v[i + 1] - v[i] != 1) {
        node tmp;
        tmp.left = v[i] + 1;
        tmp.right = v[i + 1] - 1;
        tmp.idx = pre + (tmp.right - tmp.left + 1);
        pre = tmp.idx;
        v2.pb(tmp);
      }
    }
    else if (i + 1 == n) {
      node tmp;
      tmp.left = v[i] + 1;
      tmp.right = LLONG_MAX;
      tmp.idx = pre + (tmp.right - tmp.left + 1);
      if (tmp.idx < 0) tmp.idx = LLONG_MAX;
      pre = tmp.idx;

      v2.pb(tmp);
    }
    else {
      if (i < n - 1 and v[i + 1] - v[i] != 1) {
        node tmp;
        tmp.left = v[i] + 1;
        tmp.right = v[i + 1] - 1;
        tmp.idx = pre + (tmp.right - tmp.left + 1);
        pre = tmp.idx;
        v2.pb(tmp);
      }
    }
  }

  // for (ll i = 0; i < v2.size(); i++) {
  //   cout << v2[i].left << ' ' << v2[i].right << ' ' << v2[i].idx << endl;
  // }


  while (q--) {
    ll k;
    cin >> k;

    ll l = 0;
    ll r = v2.size() - 1;
    ll low = -1;

    while (l <= r) {
      ll mid = l + (r - l) / 2;

      if (v2[mid].idx >= k) {
        low = mid;
        r = mid - 1;
      }
      else l = mid + 1;
    }

    if (low == 0) cout << (v2[low].left - 1) + k << endl;
    else cout << (v2[low].left - 1) + (k - v2[low - 1].idx) << endl;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}