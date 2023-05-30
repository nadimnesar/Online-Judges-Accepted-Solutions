#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

const int mod = 1e9+7;
const int maxx = 3e4+7;
const double eps = 1e-7;
const double pi = acos(-1.0);

void solve() {
    ll m, n, sum = 0;
    cin >> m >> n;

    vector < ll > v;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        v.pb(temp);
        sum += temp;
    }

    cout << "Thank You BACS!!! ";

    if(sum == m) cout << "Thik ache. ";
    else cout << "Bojjat dokandar!! ";

    for(ll i = 1; i < n; i++){
        if(v[i]-v[i-1] == 1){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int cn = 0;
    int t;
    cin >> t;
    while (t--){
        cout << "Case " << ++cn << ": ";
        solve();
    }

    return 0;
}