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
    vector < ll > d1, d2;
    for (ll i = 0; i < 6; i++) {
        ll temp;
        cin >> temp;
        d1.pb(temp);
    }

    map < ll , ll > mp;
    for (ll i = 0; i < 6; i++) {
        ll temp;
        cin >> temp;
        d2.pb(temp);
        mp[temp]++;
    }

    sort(full(d1));
    sort(full(d2));

    ll win = 0;

    for (ll i = 0; i < 6; i++) {
        for (ll j = 0; j < 6; j++) {
            if (d1[i] > d2[j]) win++;
        }
    }

    ll g = gcd(win, 36LL);
    cout << win/g << '/' << 36/g << endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}