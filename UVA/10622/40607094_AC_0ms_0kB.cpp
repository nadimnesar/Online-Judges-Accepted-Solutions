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
#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void nadimnesar() {
    ll n;
    while (cin >> n and n) {
        bool flag = false;
        ll m = abs(n);
        for (ll i = 2; i * i <= m; i++) {
            if (m % i == 0) {
                ll cnt = 0;
                ll x = abs(n);
                while (x % i == 0) {
                    cnt++;
                    x /= i;
                }

                if (x > 1) continue;
                else {
                    if(n < 0 and cnt&1) cout << cnt << endl;
                    else if(n < 0) continue;
                    else cout << cnt << endl;
                    
                    flag = true;
                    break;
                }
            }
        }

        if (!flag) cout << 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}