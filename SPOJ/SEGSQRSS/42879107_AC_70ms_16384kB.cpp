#include <bits/stdc++.h>
using namespace std;

#define ll    long long
#define endl  '\n'
const ll maxx = 1e5 + 7;

ll arr[maxx];

typedef struct sq_node {
  ll sq_sum = 0, sum = 0;
} sq_node;

typedef struct lzy_node {
  ll add = 0, set = -1;
} lzy_node;

sq_node segTree[4 * maxx];
lzy_node lazy[4 * maxx];

sq_node marge(sq_node left, sq_node right) {
  sq_node res;
  res.sum = left.sum + right.sum;
  res.sq_sum = left.sq_sum + right.sq_sum;
  return res;
}

void build(ll idx, ll left, ll right) {
  if (left == right) {
    segTree[idx].sum = arr[left];
    segTree[idx].sq_sum = arr[left] * arr[left];
    return;
  }

  ll mid = ((left + right) >> 1);
  build((idx << 1), left, mid);
  build((idx << 1) + 1, mid + 1, right);

  segTree[idx] = marge(segTree[(idx << 1)], segTree[(idx << 1) + 1]);
}

void propagation(ll idx, ll left, ll right) {
  if (lazy[idx].set != -1) {

    segTree[idx].sq_sum = ((right - left) + 1) * lazy[idx].set * lazy[idx].set;
    segTree[idx].sum = (lazy[idx].set * ((right - left) + 1));

    if (left != right) {
      lazy[(idx << 1)].set = lazy[idx].set;
      lazy[(idx << 1) + 1].set = lazy[idx].set;
    }

    lazy[idx].set = -1;
    return;
  }

  if (lazy[idx].add != 0) {
    segTree[idx].sq_sum += ((right - left) + 1) * lazy[idx].set * lazy[idx].set;
    segTree[idx].sq_sum += 2 * lazy[idx].add * segTree[idx].sum;

    segTree[idx].sum += (lazy[idx].add * ((right - left) + 1));

    if (left != right) {
      lazy[(idx << 1)].add += lazy[idx].add;
      lazy[(idx << 1) + 1].add += lazy[idx].add;
    }

    lazy[idx].add = 0;
    return;
  }
}

void update(ll idx, ll left, ll right, ll p, ll q, ll v) {
  propagation(idx, left, right);

  if (left > q or right < p) return;
  if (left >= p and right <= q) {
    lazy[idx].add += v;
    cout << segTree[idx].sq_sum << endl;
    propagation(idx, left, right);
    cout << segTree[idx].sq_sum << endl;

    return;
  }

  ll mid = ((left + right) >> 1);
  update((idx << 1), left, mid, p, q, v);
  update((idx << 1) + 1, mid + 1, right, p, q, v);

  segTree[idx] = marge(segTree[(idx << 1)], segTree[(idx << 1) + 1]);
}

void replace(ll idx, ll left, ll right, ll p, ll q, ll v) {
  propagation(idx, left, right);

  if (left > q or right < p) return;
  if (left >= p and right <= q) {
    lazy[idx].set = v;
    lazy[idx].add = 0;
    propagation(idx, left, right);
    return;
  }

  ll mid = ((left + right) >> 1);
  replace((idx << 1), left, mid, p, q, v);
  replace((idx << 1) + 1, mid + 1, right, p, q, v);

  segTree[idx] = marge(segTree[(idx << 1)], segTree[(idx << 1) + 1]);
}

sq_node quary(ll idx, ll left, ll right, ll p, ll q) {
  propagation(idx, left, right);

  if (right < p or left > q) {
    sq_node tmp;
    return tmp;
  }

  if (left >= p and right <= q) return segTree[idx];

  ll mid = ((left + right) >> 1);
  return marge(quary((idx << 1), left, mid, p, q), quary((idx << 1) + 1, mid + 1, right, p, q));
}

void solve() {
  ll n, c, p, q, v;
  cin >> n >> c;

  for (ll i = 1; i <= 4 * n; i++) {
    segTree[i].sum = 0;
    segTree[i].sq_sum = 0;

    lazy[i].add = 0;
    lazy[i].set = -1;
  }

  for (ll i = 1; i <= n; i++) cin >> arr[i];


  build(1, 1, n);

  for (ll i = 1; i <= c; i++) {
    ll type;
    cin >> type;

    if (type == 0) {
      cin >> p >> q >> v;
      replace(1, 1, n, p, q, v);
    }

    if (type == 1) {
      cin >> p >> q >> v;
      update(1, 1, n, p, q, v);
    }

    if (type == 2) {
      cin >> p >> q;
      cout << quary(1, 1, n, p, q).sq_sum << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ll t, cn = 0;
  cin >> t;
  while (t--) {
    cout << "Case " << ++cn << ":" << endl;
    solve();
  }

  return 0;
}
