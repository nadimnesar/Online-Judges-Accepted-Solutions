#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define llu                 unsigned long long

#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)(10)
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void nadimnesar() {
    ll n, m;
    cin >> n >> m;

    ll grid[n][m];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    bool flag = false;

    for (ll i = 0; i < m; i++) {
        ll x = 0;
        for (ll j = 0; j < n; j++) x ^= grid[j][i];
        if (x) {
            cout << "TAK" << endl;
            for (ll k = 0; k < n; k++) cout << i + 1 << ' ';
            flag = true;
            break;
        }
    }

    if (flag) return;

    for (ll i = 0; i < n; i++) {
        for (ll j = 1; j < m; j++) {
            if (grid[i][j] != grid[i][j - 1]) {
                cout << "TAK" << endl;
                for (ll k = 0; k < n; k++) {
                    if (k == i) cout << j << ' ';
                    else cout << j + 1 << ' ';
                }
                cout << endl;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    if (!flag) cout << "NIE" << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}