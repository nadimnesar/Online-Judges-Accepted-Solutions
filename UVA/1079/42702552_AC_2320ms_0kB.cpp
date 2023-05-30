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

void solve() {
    ll n, cn = 0;
    while (cin >> n and n) {
        vector < pair < double, double > > v;
        double mx = 0;
        for (ll i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            mx = max(mx, y * 60);
            v.pb({x * 60, y * 60});
        }

        vector < ll > v2;
        for (ll i = 0; i < n; i++) v2.pb(i);

        double finalres = 0;

        do {
            double l = 0;
            double r = mx;
            double res = 0;

            ll limit = 100;
            while (limit--) {
                double mid = (l + r) / 2;
                bool flag = true;

                double pre = -1;
                for (ll i = 0; i < v2.size(); i++) {
                    if (pre == -1) pre = v[v2[i]].first;
                    else {
                        double x = pre + mid;
                        if ((x - v[v2[i]].second) > eps) {
                            flag = false;
                            break;
                        }
                        pre =  max(x, v[v2[i]].first);
                    }
                }

                if (flag) {
                    l = mid;
                    res = mid;
                }
                else r = mid;
            }
            finalres = max(res, finalres);
        }
        while (next_permutation(full(v2)));

        ll res2 = round(finalres);
        if ((res2 % 60) <= 9) cout << "Case " << ++cn << ": " << (res2 / 60) << ":0" << (res2 % 60) << endl;
        else cout << "Case " << ++cn << ": " << (res2 / 60) << ':' << (res2 % 60) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}