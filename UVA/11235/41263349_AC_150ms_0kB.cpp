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
const ll maxx = 1e5 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-7;
const double pi = acos(-1.0);

typedef struct node {
    ll l_feq = 0, r_feq = 0;
    ll l_val = 0, r_val = 0;
    ll mx = 0;
} node;

ll arr[maxx];
node segTree[4 * maxx];

void build_segTree(ll idx, ll left, ll right) {
    if (left == right) {
        segTree[idx].l_feq = segTree[idx].r_feq = segTree[idx].mx = 1;
        segTree[idx].l_val = segTree[idx].r_val = arr[left];
        return;
    }

    ll mid = (left + right) >> 1;
    build_segTree((idx << 1), left, mid);
    build_segTree((idx << 1) + 1, mid + 1, right);

    node l_node = segTree[(idx << 1)];
    node r_node = segTree[(idx << 1) + 1];

    if (l_node.r_val == r_node.l_val) {
        ll feq = l_node.r_feq + r_node.l_feq;

        segTree[idx].l_val = l_node.l_val;
        segTree[idx].r_val = r_node.r_val;

        if (l_node.l_val == l_node.r_val) segTree[idx].l_feq = feq;
        else segTree[idx].l_feq = l_node.l_feq;

        if (r_node.r_val == r_node.l_val) segTree[idx].r_feq = feq;
        else segTree[idx].r_feq = r_node.r_feq;

        segTree[idx].mx = max({feq, l_node.mx, r_node.mx});
    }
    else {
        segTree[idx].l_val = l_node.l_val;
        segTree[idx].r_val = r_node.r_val;

        segTree[idx].l_feq = l_node.l_feq;
        segTree[idx].r_feq = r_node.r_feq;
        segTree[idx].mx = max(l_node.mx, r_node.mx);
    }
}

node range_quary(ll idx, ll left, ll right, ll s, ll e) {
    if (right < s or left > e) {
        node x; return x;
    }
    if (left >= s and right <= e) return segTree[idx];

    ll mid = (left + right) >> 1;
    node l_node = range_quary((idx << 1), left, mid, s, e);
    node r_node = range_quary((idx << 1) + 1, mid + 1, right, s, e);

    if (l_node.mx == 0) return r_node;
    if (r_node.mx == 0) return l_node;

    node res;
    if (l_node.r_val == r_node.l_val) {
        ll feq = l_node.r_feq + r_node.l_feq;

        res.l_val = l_node.l_val;
        res.r_val = r_node.r_val;

        if (l_node.l_val == l_node.r_val) res.l_feq = feq;
        else res.l_feq = l_node.l_feq;

        if (r_node.r_val == r_node.l_val) res.r_feq = feq;
        else res.r_feq = r_node.r_feq;

        res.mx = max({feq, l_node.mx, r_node.mx});
    }
    else {
        res.l_val = l_node.l_val;
        res.r_val = r_node.r_val;

        res.l_feq = l_node.l_feq;
        res.r_feq = r_node.r_feq;
        res.mx = max(l_node.mx, r_node.mx);
    }
    return res;
}

void solve() {
    ll n;
    while (cin >> n and n) {
        ll q, s, e;
        cin >> q;

        for (ll i = 1; i <= n; i++) cin >> arr[i];
        for (ll i = 1; i <= n; i++) {
            segTree[i].l_feq = 0;
            segTree[i].r_feq = 0;
            segTree[i].l_val = 0;
            segTree[i].r_val = 0;
            segTree[i].mx = 0;
        }
        build_segTree(1, 1, n);

        while (q--) {
            cin >> s >> e;
            cout << range_quary(1, 1, n, s, e).mx << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}