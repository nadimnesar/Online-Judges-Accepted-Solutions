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
  double a, b, c;
  while (cin >> a >> b >> c) {
    cout << "The radius of the round table is: ";
    if (a <= eps or b <= eps or c <= eps) cout << "0.000" << endl;
    else {
      double s = (a + b + c) / 2;
      double area = sqrt((s - a) * (s - b) * (s - c) / s);
      cout << dot(3) << area << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}