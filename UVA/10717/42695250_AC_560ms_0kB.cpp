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

ll res1, res2;
vector < ll > coin;

void AllCombination(vector < ll > &storage, ll start, ll index, ll table) {
    if (storage.size() == 4) {

        ll llcm = storage[0];
        llcm = lcm(llcm, storage[1]);
        llcm = lcm(llcm, storage[2]);
        llcm = lcm(llcm, storage[3]);

        res1 = max(res1, llcm*(table/llcm));
        res2 = min(res2, llcm*((table/llcm)+1));

        return;
    }

    for (ll i = start; i < coin.size(); i++) {
        storage.pb(coin[index]);
        AllCombination(storage, i + 1, index + 1, table);
        storage.pop_back();
        index++;
    }
}

void solve() {
    ll c, t;
    while (cin >> c >> t and c and t) {

        coin.clear();

        for (ll i = 0; i < c; i++) {
            ll temp;
            cin >> temp;
            coin.pb(temp);
        }

        for (ll i = 0; i < t; i++) {
            ll temp;
            cin >> temp;

            res1 = 0;
            res2 = LLONG_MAX;

            vector < ll > storage;
            AllCombination(storage, 0, 0, temp);

            if(res1 == temp) res2 = res1;
            cout << res1 << ' ' << res2 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}