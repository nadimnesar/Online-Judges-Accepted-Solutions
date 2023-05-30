#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define endl '\n'
const ll maxx = 2e5 + 7;

bool arr[maxx];

typedef struct node {
  ll zero_main = 0, one_main = 0;
  ll inv_main = 0;

  ll zero_cpy = 0, one_cpy = 0;
  ll inv_cpy = 0;
} node;

node segTree[4 * maxx];
ll lazy[4 * maxx];

node marge(node left, node right) {
  node res;

  res.inv_main = left.inv_main + right.inv_main + (left.one_main * right.zero_main);
  res.zero_main = left.zero_main + right.zero_main;
  res.one_main = left.one_main + right.one_main;

  res.inv_cpy = left.inv_cpy + right.inv_cpy + (left.one_cpy * right.zero_cpy);
  res.zero_cpy = left.zero_cpy + right.zero_cpy;
  res.one_cpy = left.one_cpy + right.one_cpy;

  return res;
}

void build(ll idx, ll left, ll right) {
  if (left == right) {
    if (arr[left]) segTree[idx].one_main = 1, segTree[idx].zero_main = 0;
    else segTree[idx].one_main = 0, segTree[idx].zero_main = 1;

    if (arr[left]) segTree[idx].one_cpy = 0, segTree[idx].zero_cpy = 1;
    else segTree[idx].one_cpy = 1, segTree[idx].zero_cpy = 0;

    segTree[idx].inv_main = segTree[idx].inv_cpy = 0;
    return;
  }

  ll mid = ((left + right) >> 1);
  build((idx << 1), left, mid);
  build((idx << 1) + 1, mid + 1, right);

  segTree[idx] = marge(segTree[(idx << 1)], segTree[(idx << 1) + 1]);
}

void propagation(ll idx, ll left, ll right) {
  if (lazy[idx] & 1) {
    swap(segTree[idx].zero_main, segTree[idx].zero_cpy);
    swap(segTree[idx].one_main, segTree[idx].one_cpy);
    swap(segTree[idx].inv_main, segTree[idx].inv_cpy);
  }

  if (left != right) {
    lazy[(idx << 1)] += lazy[idx];
    lazy[(idx << 1) + 1] += lazy[idx];
  }

  lazy[idx] = 0;
}

void update(ll idx, ll left, ll right, ll p, ll q, ll v) {
  if (lazy[idx]) propagation(idx, left, right);

  if (left > q or right < p) return;
  if (left >= p and right <= q) {

    swap(segTree[idx].zero_main, segTree[idx].zero_cpy);
    swap(segTree[idx].one_main, segTree[idx].one_cpy);
    swap(segTree[idx].inv_main, segTree[idx].inv_cpy);

    if (left != right) {
      lazy[(idx << 1)] += v;
      lazy[(idx << 1) + 1] += v;
    }
    return;
  }

  ll mid = ((left + right) >> 1);
  update((idx << 1), left, mid, p, q, v);
  update((idx << 1) + 1, mid + 1, right, p, q, v);

  segTree[idx] = marge(segTree[(idx << 1)], segTree[(idx << 1) + 1]);
}

node quary(ll idx, ll left, ll right, ll p, ll q) {
  if (lazy[idx]) propagation(idx, left, right);

  if (right < p or left > q) {
    node z;
    return z;
  }

  if (left >= p and right <= q) return segTree[idx];

  ll mid = ((left + right) >> 1);
  return marge(quary((idx << 1), left, mid, p, q), quary((idx << 1) + 1, mid + 1, right, p, q));
}

void solve() {
  ll n, c, type, p, q;
  cin >> n >> c;

  for (ll i = 1; i <= n; i++) cin >> arr[i];

  build(1, 1, n);

  for (ll i = 1; i <= c; i++) {
    cin >> type;
    if (type == 1) {
      cin >> p >> q;
      update(1, 1, n, p, q, 1);
    }
    else {
      cin >> p >> q;
      cout << quary(1, 1, n, p, q).inv_main << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}
