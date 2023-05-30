#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

struct customHash {
  static uint64_t nadimnesar(uint64_t x) {
    x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return nadimnesar(x + FIXED_RANDOM);
  }
};

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
const ll maxx = 2e5 + 7;
const ll block = 450;
const double eps = 1e-7;
const double pi = acos(-1.0);

ll dx[] = { 0, 0, 1, -1 };
ll dy[] = { 1, -1, 0, 0 };

typedef struct query {
  ll l, r, idx, k;
  bool res;
} query;

bool cmp(query A, query B) {
  if (A.l / block != B.l / block) return (A.l / block < B.l / block);
  return (A.r < B.r);
}

bool cmp2(query A, query B) {
  return (A.idx < B.idx);
}

ll arr[maxx];
query qarr[maxx];

int feq[20000001];
int feq_of_feq[20000001];
ll mx_frq = 0;

void add(ll idx) {
  feq_of_feq[feq[arr[idx]]]--;
  feq[arr[idx]]++;
  feq_of_feq[feq[arr[idx]]]++;

  mx_frq = max(mx_frq, (ll)feq[arr[idx]]);
}

void remove(ll idx) {
  feq_of_feq[feq[arr[idx]]]--;
  feq[arr[idx]]--;
  feq_of_feq[feq[arr[idx]]]++;

  if (!feq_of_feq[mx_frq]) mx_frq--;
}

void solve() {
  ll n, q;
  cin >> n >> q;

  gp_hash_table < ll, ll, customHash> table;
  ll at = 1;
  for (ll i = 0; i < n; i++){
    cin >> arr[i];
    if (table[arr[i]] > 0) arr[i] = table[arr[i]];
    else {
      table[arr[i]] = at++;
      arr[i] = table[arr[i]];
    }
  }

  for (ll i = 0; i < q; i++) {
    ll x, y, z;
    cin >> x >> y >> z;

    qarr[i].l = x - 1;
    qarr[i].r = y - 1;
    qarr[i].k = z;
    qarr[i].idx = i;
  }

  sort(qarr, qarr + q, cmp);

  ll mo_left = 0;
  ll mo_right = -1;

  for (ll i = 0; i < q; i++) {
    ll L = qarr[i].l;
    ll R = qarr[i].r;
    ll K = qarr[i].k;

    while (mo_right < R) add(++mo_right);
    while (mo_left > L) add(--mo_left);

    while (mo_left < L) remove(mo_left++);
    while (mo_right > R) remove(mo_right--);

    if (mx_frq * K >= R - L + 1) qarr[i].res = true;
    else qarr[i].res = false;
  }

  sort(qarr, qarr + q, cmp2);

  for (ll i = 0; i < q; i++) {
    if (qarr[i].res) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}