#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve() {
    ll n, q;
    cin >> n >> q;

    pbds not_come_but_called;
    pbds not_called;

    for(ll i = 1; i <= n; i++) not_called.in(i);

    while(q--){
        ll e;
        cin >> e;

        if(e == 1){
            ll x = *not_called.find_by_order(0);
            not_called.erase(x);
            not_come_but_called.in(x);
        }
        else if(e == 2){
            ll x;
            cin >> x;
            not_come_but_called.erase(x);
        }
        else{
            ll x = *not_come_but_called.find_by_order(0);
            cout << x << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}