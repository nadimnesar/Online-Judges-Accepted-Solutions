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
const ll maxx = 1e6 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-7; 
const double pi = acos(-1.0);

void solve() {
    string s;
    cin >> s;

    ll n = 0;
    for(ll i = 0; i < s.size(); i++){
        n += s[i];
    }

    if(n%3 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
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