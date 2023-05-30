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
  while (cin >> n and n) {

    while (true) {

      ll tmp;
      cin >> tmp;
      if (tmp == 0) {
        cout << endl;
        break;
      }

      vector < ll > v;
      v.pb(tmp);

      for (ll i = 0; i < n - 1; i++) {
        cin >> tmp;
        v.pb(tmp);
      }

      stack < ll > st;

      ll i = 0;
      ll k = 1;
      bool f = 1;

      while(i < n){
        if(v[i] == k) i++, k++;
        else if(!st.empty() and st.top() == v[i]) i++, st.pop();
        else if(k <= n) st.push(k), k++;
        else{
          f = 0;
          break;
        }
      }

      if (f) cout << "Yes" << endl;
      else cout << "No" << endl;
    }


  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}