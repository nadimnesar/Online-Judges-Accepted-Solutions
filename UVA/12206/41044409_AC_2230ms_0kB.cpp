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

const int maxx = 1e6 + 7;
const double eps = 1e-7;
const double pi = acos(-1.0);

int base[2] = { 169, 369 };
ll mod[2] = { 1000003769, 1000004569 };
ll hashTable[2][maxx];
ll basePow[2][maxx];

void init() {
    basePow[0][0] = basePow[1][0] = 1;
    for (int i = 1; i < maxx; i++) {
        basePow[0][i] = (basePow[0][i - 1] * base[0]) % mod[0];
        basePow[1][i] = (basePow[1][i - 1] * base[1]) % mod[1];
    }
}

void build_hashTable(string &str) { // 1 based idx
    hashTable[0][1] = hashTable[1][1] = (str[0] - 'a' + 1);
    for (int i = 1; str[i]; i++) {
        hashTable[0][i + 1] = ((hashTable[0][i] * base[0]) + (str[i] - 'a' + 1)) % mod[0];
        hashTable[1][i + 1] = ((hashTable[1][i] * base[1]) + (str[i] - 'a' + 1)) % mod[1];
    }
}

pair < ll, ll > get_subHash(int left, int right) { // 1 based idx
    pair < ll, ll > sub;
    sub.first = (hashTable[0][right] - (hashTable[0][left - 1] * basePow[0][right - left + 1])) % mod[0];
    sub.second = (hashTable[1][right] - (hashTable[1][left - 1] * basePow[1][right - left + 1])) % mod[1];
    if (sub.first < 0) sub.first += mod[0];
    if (sub.second < 0) sub.second += mod[1];
    return sub;
}

pair < ll, ll > get_hashValue(string &str) {
    pair < ll, ll > res; res.first = 0; res.second = 0;
    for (int i = 0; str[i]; i++) {
        res.first *= base[0]; res.first %= mod[0];
        res.first += (str[i] - 'a' + 1);
        res.second *= base[1]; res.second %= mod[1];
        res.second += (str[i] - 'a' + 1);
    }
    return res;
}

map < pair < ll, ll > , ll > mp;

void solve() {
    ll m;
    while (cin >> m and m) {
        string s;
        cin >> s;

        build_hashTable(s);

        ll n = s.size();

        ll l = 1;
        ll r = n;
        ll res1 = -1;
        ll res2 = -1;

        while (l <= r) {
            ll len = (l + r) / 2;
            bool flag = false;
            ll at;
            mp.clear();
            for (ll i = 1; i <= n - len + 1; i++) {
                ll x = mp[get_subHash(i, i + len - 1)]++;
                if (++x >= m) {
                    flag = true;
                    at = i;
                }
            }
            if (flag) {
                res1 = len;
                res2 = at;
                l = len + 1;
            }
            else r = len - 1;
        }

        if (res1 == -1) cout << "none" << endl;
        else cout << res1 << ' ' << res2 - 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init();
    solve();
}