#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                "\n"
#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define pqueue              priority_queue<ll,vector<ll>,greater<ll>>
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(1e4+7)
#define mod                 (ll)(1e7+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

ll dp[maxx];

ll a, b, c, d, e, f;
ll fn(ll n) {
    if(n < 0) return 0;

    if (n == 0) return a%mod;
    if (n == 1) return b%mod;
    if (n == 2) return c%mod;
    if (n == 3) return d%mod;
    if (n == 4) return e%mod;
    if (n == 5) return f%mod;

    if(dp[n] != -1) return dp[n];

    return dp[n] = (fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))%mod;
}

void solve() {
    ll n, cases;
    scanf("%lld", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        memset(dp, -1, sizeof(dp));
        printf("Case %lld: %lld\n", caseno, fn(n));
    }
}

int main() {

    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // int t, cn = 0;
    // cin >> t;
    // while(t--){
    //     // cout << "Case #" << ++cn << ": ";
    //     solve();
    // }

    solve();

    return 0;
}