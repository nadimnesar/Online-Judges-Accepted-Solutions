#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

const ll mod = 1e9 + 7;
const ll maxx = 1e6 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-7;
const double pi = acos(-1.0);

double dis(double x1, double y1, double x2, double y2) {
    return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

void solve() {
    double r;
    ll n;
    cin >> n >> r;

    vector < pair < double, double > > v;
    for (ll i = 0; i < n; i++) {
        double x1, y1;
        cin >> x1 >> y1;
        v.pb({x1, y1});
    }

    double res = 0;
    for (ll i = 0; i < n; i++) {
        if (i == n - 1) {
            res += dis(v[i].first, v[i].second, v[0].first, v[0].second);
        }
        else {
            res += dis(v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
        }
    }

    res += 2 * pi * r;
    cout << dot(2) << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}