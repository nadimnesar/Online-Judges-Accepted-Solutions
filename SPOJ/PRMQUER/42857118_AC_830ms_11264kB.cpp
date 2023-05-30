#include <bits/stdc++.h>
using namespace std;

#define ll    long long
#define endl  '\n'

vector < bool > ifprime(1e7+7);

void Sieve() {
  for (ll i = 3; i * i <= 1e7+7; i += 2) {
    if (!ifprime[i]) {
      for (ll j = i * i; j < 1e7+7; j += i + i) {
        ifprime[j] = true;
      }
    }
  }
}

ll pcheck(ll n) {
  if (n < 2) return 0;
  if (n == 2) return 1;
  if (!(n & 1)) return 0;
  if(n > 1e7) return 0;
  if (!ifprime[n]) return 1;
  return 0;
}

const ll maxx = 1e5 + 7;

ll arr[maxx];

typedef struct node
{
  ll prime_count = 0;
  ll value = 0;
} node;

node segTree[4 * maxx];
ll lazy[4 * maxx];

node marge(node left, node right) {
  node res;
  res.value = left.value + right.value;
  res.prime_count = left.prime_count + right.prime_count;
  return res;
}

void build(ll idx, ll left, ll right) {
  if (left == right) {
    segTree[idx].value = arr[left];
    segTree[idx].prime_count = pcheck(arr[left]);
    return;
  }

  ll mid = ((left + right) >> 1);
  build((idx << 1), left, mid);
  build((idx << 1) + 1, mid + 1, right);

  segTree[idx] = marge(segTree[(idx << 1)], segTree[(idx << 1) + 1]);
}

void propagation(ll idx, ll left, ll right) {

  segTree[idx].value = (lazy[idx] * ((right - left) + 1));
  segTree[idx].prime_count = (pcheck(lazy[idx]) * ((right - left) + 1));

  if (left != right) {
    lazy[(idx << 1)] = lazy[idx];
    lazy[(idx << 1) + 1] = lazy[idx];
  }

  lazy[idx] = 0;
}

void replace(ll idx, ll left, ll right, ll p, ll q, ll v) {
  if (lazy[idx]) propagation(idx, left, right);

  if (left > q or right < p) return;
  if (left >= p and right <= q) {

    segTree[idx].value = (v * ((right - left) + 1));
    segTree[idx].prime_count = (pcheck(v) * ((right - left) + 1));

    if (left != right) {
      lazy[(idx << 1)] = v;
      lazy[(idx << 1) + 1] = v;
    }

    return;
  }

  ll mid = ((left + right) >> 1);
  replace((idx << 1), left, mid, p, q, v);
  replace((idx << 1) + 1, mid + 1, right, p, q, v);

  segTree[idx] = marge(segTree[(idx << 1)], segTree[(idx << 1) + 1]);
}

void update(ll idx, ll left, ll right, ll ith, ll v) {
  if (lazy[idx]) propagation(idx, left, right);
  if (right < ith or left > ith) return;

  if (left == ith and right == ith) {
    segTree[idx].value += v;
    segTree[idx].prime_count = pcheck(segTree[idx].value);
    return;
  }

  ll mid = (left + right) >> 1;
  update((idx << 1), left, mid, ith, v);
  update((idx << 1) + 1, mid + 1, right, ith, v);

  segTree[idx] = marge(segTree[(idx << 1)], segTree[(idx << 1) + 1]);
}

node quary(ll idx, ll left, ll right, ll p, ll q) {
  if (lazy[idx]) propagation(idx, left, right);

  if (right < p or left > q) {
    node tmp;
    return tmp;
  }
  if (left >= p and right <= q) return segTree[idx];

  ll mid = ((left + right) >> 1);
  return marge(quary((idx << 1), left, mid, p, q), quary((idx << 1) + 1, mid + 1, right, p, q));
}

void solve() {
  ll n, c, p, q, v, idx;
  cin >> n >> c;
  for (ll i = 1; i <= n; i++) cin >> arr[i];

  build(1, 1, n);

  for (ll i = 1; i <= c; i++) {
    char type;
    cin >> type;

    if (type == 'A') {
      cin >> v >> idx;
      update(1, 1, n, idx, v);
    }

    if (type == 'Q') {
      cin >> p >> q;
      cout <<  quary(1, 1, n, p, q).prime_count << endl;
    }

    if (type == 'R') {
      cin >> v >> p >> q;
      replace(1, 1, n, p, q, v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  Sieve();

  solve();

  return 0;
}
