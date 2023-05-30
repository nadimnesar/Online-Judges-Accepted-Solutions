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
const ll maxx = 2e5 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-7;
const double pi = acos(-1.0);

ll arr[maxx];
ll segTree[4 * maxx];

void build_segTree(ll idx, ll left, ll right) {
    if (left == right) {
        segTree[idx] = arr[left];
        return;
    }

    ll mid = (left + right) >> 1;
    build_segTree((idx << 1), left, mid);
    build_segTree((idx << 1) + 1, mid + 1, right);

    segTree[idx] = segTree[(idx << 1)] + segTree[(idx << 1) + 1];
}

ll range_quary(ll idx, ll left, ll right, ll s, ll e) {
    if (right < s or left > e) return 0;
    if (left >= s and right <= e) return segTree[idx];

    ll mid = (left + right) >> 1;
    return (range_quary((idx << 1), left, mid, s, e) +
            range_quary((idx << 1) + 1, mid + 1, right, s, e));
}

void single_update(ll idx, ll left, ll right, ll ith, ll v) {
    if (right < ith or left > ith) return;
    if (left == ith and right == ith) {
        segTree[idx] = v;
        return;
    }

    ll mid = (left + right) >> 1;
    single_update((idx << 1), left, mid, ith, v);
    single_update((idx << 1) + 1, mid + 1, right, ith, v);

    segTree[idx] = segTree[(idx << 1)] + segTree[(idx << 1) + 1];
}

void solve() {
    ll n, cn = 0;
    bool fk = false;
    while (cin >> n and n) {
        for (ll i = 1; i <= n; i++) cin >> arr[i];

        for (ll i = 1; i <= 4*n; i++) segTree[i] = 0;
        build_segTree(1, 1, n);

        if(fk) cout << endl;
        else fk = true;

        cout << "Case " << ++cn << ":" << endl;
        string str;
        while (cin >> str) {
            if (str == "END") break;
            if (str == "M") {
                ll s, e;
                cin >> s >> e;
                cout << range_quary(1, 1, n, s, e) << endl;
            }
            else {
                ll idx, val;
                cin >> idx >> val;
                single_update(1, 1, n, idx, val);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}