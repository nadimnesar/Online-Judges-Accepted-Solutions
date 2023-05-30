#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

ll base[2] = { 169, 369 };
ll mod[2] = { 1000003769, 1000004569 };
ll n;

pair < ll, ll > get_hashValue(string &str) {
    pair < ll, ll > res; res.first = 0; res.second = 0;
    for (ll i = 0; str[i]; i++) {
        res.first *= base[0]; res.first %= mod[0];
        res.first += (str[i] - 'a' + 1);
        res.second *= base[1]; res.second %= mod[1];
        res.second += (str[i] - 'a' + 1);
    }
    return res;
}

void solve() {
    string s;
    cin >> s;

    n = s.size();
    ll res = 0;

    set < pair < ll, ll > > st;
    for (ll len = 1; len <= n; len++) {
        for (ll i = 0; i < n - len + 1; i++) {
            string sub = s.substr(i, len);
            string mx;
            ll limit = len;
            while (limit--) {
                sub = sub.back() + sub;
                sub.pop_back();
                mx = max(sub, mx);
            }
            st.in(get_hashValue(mx));
        }
    }

    cout << st.size() << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}