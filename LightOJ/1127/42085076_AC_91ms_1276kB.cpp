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

vector < ll > left_sum;
vector < ll > right_sum;

void BT(vector < ll > &set, ll sum, ll index, ll n, ll op){
    if(index == n){
        if(op == 1) left_sum.pb(sum);
        else right_sum.pb(sum);
        return;
    }
    BT(set, sum+set[index], index+1, n, op);
    BT(set, sum, index+1, n, op);
}

void solve() {
    ll n, w;
    cin >> n >> w;

    vector < ll > left, right;

    ll x = n/2;
    ll y = n/2;

    if(n&1) x++;

    for(ll i = 0; i < x; i++){
        ll temp;
        cin >> temp;
        left.pb(temp);
    }

    for(ll i = 0; i < y; i++){
        ll temp;
        cin >> temp;
        right.pb(temp);
    }

    left_sum.clear();
    right_sum.clear();

    if(n == 1){
        if(left[0] > w) cout << 1 << endl;
        else cout << 2 << endl;
        return;
    }

    BT(left, 0, 0, x, 1);
    BT(right, 0, 0, y, 2);

    sort(full(right_sum));

    ll res = 0;
    for(ll i = 0; i < left_sum.size(); i++){
        if(left_sum[i] <= w){
            ll need = w-left_sum[i];
            ll cnt = upper_bound(full(right_sum), need) - right_sum.begin();
            res += cnt;
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t, cn = 0;
    cin >> t;
    while (t--){
        cout << "Case " << ++cn << ": ";
        solve();
    }

    return 0;
}