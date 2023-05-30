#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;

#define endl                '\n'
#define ff                  first
#define ss                  second
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

const ll base = 10;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll maxx = 1e5 + 7;
const double eps = 1e-7;
const double pi = acos(-1.0);

void solve() {
    ll n;
    cin >> n;

    ll good = 0;
    ll bad = 0;

    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        if(temp > 0) good += temp;
        if(temp < 0) bad += abs(temp);
    }

    if(good == bad) cout << ":|" << endl;
    else if(good > bad) cout << ":)" << endl;
    else cout << ":(" << endl;


}

int main() {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    // int cn = 0;
    // int t;
    // cin >> t;
    // while (t--) {
    //     // cout << "Case #" << ++cn << ": ";
    //     solve();
    // }
    solve();

    return 0;
}