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
const ll maxx = 2e5 + 7;
const ll block = 500;
const double eps = 1e-7;
const double pi = acos(-1.0);

ll dx[] = { 0, 0, 1, -1 };
ll dy[] = { 1, -1, 0, 0 };

typedef struct query{
  ll l, r, idx, res;
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

ll feq[1000001];
ll power = 0;

void add(ll idx){
  ll prefeq = feq[arr[idx]];
  feq[arr[idx]]++;
  ll curfeq = feq[arr[idx]];

  power -= prefeq*prefeq*arr[idx];
  power += curfeq*curfeq*arr[idx];
}

void remove(ll idx){
  ll prefeq = feq[arr[idx]];
  feq[arr[idx]]--;
  ll curfeq = feq[arr[idx]];
  
  power -= prefeq*prefeq*arr[idx];
  power += curfeq*curfeq*arr[idx];
}

void solve() {
  ll n, q;
  cin >> n >> q;

  for (ll i = 0; i < n; i++) cin >> arr[i];
  for (ll i = 0; i < q; i++) {
    ll x, y;
    cin >> x >> y;

    qarr[i].l = x-1;
    qarr[i].r = y-1;
    qarr[i].idx = i;
  }

  sort(qarr, qarr + q, cmp);

  ll mo_left = 0;
  ll mo_right = -1;

  for (ll i = 0; i < q; i++) {
    ll L = qarr[i].l;
    ll R = qarr[i].r;

    while(mo_right < R) add(++mo_right);   
    while(mo_left > L) add(--mo_left);

    while(mo_left < L) remove(mo_left++);
    while(mo_right > R) remove(mo_right--);

    qarr[i].res = power;
  }

  sort(qarr, qarr+q, cmp2);

  for (ll i = 0; i < q; i++){
    cout << qarr[i].res << endl;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}