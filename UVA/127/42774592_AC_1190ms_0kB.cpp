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

#define iremove(x,y)        x.erase(x.begin()+y)

void solve() {
  string s;
  vector < stack < string > > v;

  while (cin >> s) {
    if (s == "#") break;

    stack < string > temp;
    temp.push(s);
    v.pb(temp);

    if (v.size() == 52) {

      while (true) {
        bool flag = false;

        for (ll i = 0; i < v.size(); i++) {
          if (!v[i].size()) iremove(v, i);
        }

        for (ll i = 0; i < v.size(); i++) {
          if(i == 0) continue;
          else if (i <= 2) {

            string a = v[i].top();
            string b = v[i - 1].top();

            if (a[0] == b[0] or a[1] == b[1]) {
              v[i - 1].push(a);
              v[i].pop();
              flag = true;
              break;
            }

          }
          else {

            string a = v[i].top();
            string b = v[i - 3].top();

            if (a[0] == b[0] or a[1] == b[1]) {
              v[i - 3].push(a);
              v[i].pop();
              flag = true;
              break;
            }

            b = v[i - 1].top();
            
            if (a[0] == b[0] or a[1] == b[1]) {
              v[i - 1].push(a);
              v[i].pop();
              flag = true;
              break;
            }
          }
        }
        if (!flag) break;
      }

      if (v.size() == 1) cout << v.size() << " pile remaining: ";
      else cout << v.size() << " piles remaining: ";

      for (ll i = 0; i < v.size(); i++) {
        if (i + 1 == v.size()) cout << v[i].size() << endl;
        else cout << v[i].size() << ' ';
      }

      v.clear();
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}