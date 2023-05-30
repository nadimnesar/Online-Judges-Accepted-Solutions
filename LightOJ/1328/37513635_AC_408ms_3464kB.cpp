#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define ppb                 pop_back
#define ppf                 pop_front
#define pb                  push_back
#define pf                  push_front

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)23
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e6+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

ll dp[10000007];
ll arr[10000007];

void solve() {
    ll k, c, n;
    cin >> k >> c >> n >> arr[0];

    for (ll i = 1; i < n; i++) arr[i] = ((k * arr[i - 1] + c) % mod);

    sort(arr, arr+n);

    dp[0] = arr[0];
    for (ll i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + arr[i];
    }

    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        sum += abs(((((n - 1) - (i + 1)) + 1) * arr[i]) - (dp[n - 1] - dp[i]));
    }

    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--) {
        cout << "Case " << ++cn << ": ";
        solve();
    }
    // solve();

    return 0;
}