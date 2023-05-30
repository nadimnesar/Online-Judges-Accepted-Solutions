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

const ll maxx = 1e6 + 7;

ll base[2] = { 169, 369 };
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

bool cmp(pair < ll , ll > sub, pair < ll , ll > reshash) {
    if (sub.first < reshash.first and sub.second < reshash.second) return true;
    return false;
}

void solve() {
    ll n;
    string s;
    cin >> n >> s;

    s += s;
    build_hashTable(s);

    ll res = 1;
    for (ll i = 2; i <= n; i++) {

        ll l = 1;
        ll r = n;

        ll siz = 0;

        while (l <= r) {
            ll mid = (l + r) / 2;

            if (get_subHash(res, res + mid - 1) == get_subHash(i, i + mid - 1)) {
                siz = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        if (siz < n and s[res + siz - 1] > s[i + siz - 1]) res = i;
    }

    cout << res-1 << endl;

    memset(hashTable, 0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init();
    ll t;
    cin >> t;
    while (t--) solve();
}