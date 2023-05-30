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

vector < ll > sums1;
vector < ll > sums2;

void allsubsets(vector < ll > &set, ll sum, ll index, ll type){
    if(index == set.size()){
        if(type == 1) sums1.pb(sum);
        if(type == 2) sums2.pb(sum);
        return;
    }
    allsubsets(set, sum+set[index], index+1, type);
    allsubsets(set, sum, index+1, type);
}

bool checker(vector < ll > &v2, ll w) {
  sums1.clear();
  sums2.clear();

  vector < ll > v3, v4;
  for(ll i = 0; i < v2.size()/2; i++) v3.pb(v2[i]);
  for(ll i = v2.size()/2; i < v2.size(); i++) v4.pb(v2[i]);

  allsubsets(v3, 0, 0, 1);
  allsubsets(v4, 0, 0, 2);

  sort(full(sums2));

  for(ll i = 0; i < sums1.size(); i++){
    if(sums1[i] > w) continue;
    if(sums1[i] == w) return true;
    ll x = w-sums1[i];
    if(binary_search(full(sums2), x)) return true;
  }

  return false;
}

void solve() {
  ll n, cn = 0;
  while (cin >> n) {

    vector < ll > v;
    for (ll i = 0; i < n; i++) {
      ll temp;
      cin >> temp;
      v.pb(temp);
    }

    cout << "Case #" << ++cn << ": ";
    for (ll i = 0; i < n; i++) {
      if (i + 1 == n) cout << v[i] << endl;
      else cout << v[i] << ' ';
    }

    if (!is_sorted(full(v))) {
      cout << "This is not an A-sequence." << endl;
      continue;
    }

    bool flag = true;

    vector < ll > v2;
    for (ll i = 0; i < n; i++) {
      if (checker(v2, v[i])) {
        flag = false;
        break;
      }
      v2.pb(v[i]);
    }

    if (flag) cout << "This is an A-sequence." << endl;
    else cout << "This is not an A-sequence." << endl;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}