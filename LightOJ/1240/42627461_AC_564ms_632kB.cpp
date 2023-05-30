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

typedef struct point {
  double x, y, z;
} point;

double distance(point a, point b) {
  double x = (b.x - a.x) * (b.x - a.x);
  double y = (b.y - a.y) * (b.y - a.y);
  double z = (b.z - a.z) * (b.z - a.z);
  return sqrt(x + y + z);
}

double line_segment(point a, point b, point p, double m) {
  double x = (((distance(a, b) - m) * a.x) + (m * b.x)) / distance(a, b);
  double y = (((distance(a, b) - m) * a.y) + (m * b.y)) / distance(a, b);
  double z = (((distance(a, b) - m) * a.z) + (m * b.z)) / distance(a, b);

  point q;
  q.x = x; q.y = y; q.z = z;

  return distance(p, q);
  //https://youtu.be/xuqThOk8zPo
}

void solve() {
  point a, b, p;

  cin >> a.x >> a.y >> a.z;
  cin >> b.x >> b.y >> b.z;
  cin >> p.x >> p.y >> p.z;

  double l = 0;
  double r = distance(a, b);

  double res = LLONG_MAX;

  ll limit = 1e3;
  while (limit--) {
    double m1 = l + (r - l) / 3.0;
    double m2 = r - (r - l) / 3.0;

    double d1 = line_segment(a, b, p, m1);
    double d2 = line_segment(a, b, p, m2);

    res = min({d1, d2, res});
    if (d1 > d2) l = m1;
    else r = m2;
  }

  cout << dot(10) << res << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ll t, cn = 0;
  cin >> t;
  while (t--) {
    cout << "Case " << ++cn << ": ";
    solve();
  }

  return 0;
}