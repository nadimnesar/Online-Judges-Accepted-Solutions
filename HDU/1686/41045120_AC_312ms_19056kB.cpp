#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define endl                '\n'
#define pb                  push_back

const int maxx = 1e6 + 7;
int base[2] = { 169, 369 };
int mod[2] = { 1669, 2069 };
int hashTable[2][maxx];
int basePow[2][maxx];
string s, w;

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

pair < int, int > get_subHash(int left, int right) { // 1 based idx
    pair < ll, ll > sub;
    sub.first = (hashTable[0][right] - (hashTable[0][left - 1] * basePow[0][right - left + 1])) % mod[0];
    sub.second = (hashTable[1][right] - (hashTable[1][left - 1] * basePow[1][right - left + 1])) % mod[1];
    if (sub.first < 0) sub.first += mod[0];
    if (sub.second < 0) sub.second += mod[1];
    return sub;
}

pair < int, int > get_hashValue(string &str) {
    pair < int, int > res; res.first = 0; res.second = 0;
    for (int i = 0; str[i]; i++) {
        res.first *= base[0]; res.first %= mod[0];
        res.first += (str[i] - 'a' + 1);
        res.second *= base[1]; res.second %= mod[1];
        res.second += (str[i] - 'a' + 1);
    }
    return res;
}

void solve() {
    cin >> w >> s;

    for (int i = 0; i < s.size(); i++) s[i] = tolower(s[i]);
    for (int i = 0; i < w.size(); i++) w[i] = tolower(w[i]);

    build_hashTable(s);
    pair < int, int > sub = get_hashValue(w);

    int res = 0;
    int len = w.size();
    int n = s.size();
    for (int i = 1; i <= n - len + 1; i++) {
        if (get_subHash(i, i + len - 1) == sub){
            res++;
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    while (t--) solve();
}