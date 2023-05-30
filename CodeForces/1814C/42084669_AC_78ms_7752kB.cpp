#include<bits/stdc++.h>
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

void solve() {
    ll n, sa, sb;
    cin >> n >> sa >> sb;

    vector < pair < ll, ll > > v;
    for (ll i = 1; i <= n; i++) {
        ll temp;
        cin >> temp;
        v.pb({temp, i});
    }

    sort(full(v));
    reverse(full(v));

    vector < ll > a, b;
    ll op_a = sa;
    ll op_b = sb;

    for (ll i = 0; i < n; i++) {
        if (op_a == op_b) {
            if (sa < sb) {
                a.pb(v[i].second);
                op_a += sa;
            }
            else {
                b.pb(v[i].second);
                op_b += sb;
            }
        }
        else if (op_a < op_b) {
            a.pb(v[i].second);
            op_a += sa;
        }
        else {
            b.pb(v[i].second);
            op_b += sb;
        }
    }

    cout << a.size();
    for (ll i = 0; i < a.size(); i++) cout << ' ' << a[i];
    cout << endl;

    cout << b.size();
    for (ll i = 0; i < b.size(); i++) cout << ' ' << b[i];
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}