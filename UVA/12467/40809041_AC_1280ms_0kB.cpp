#include <bits/stdc++.h>
using namespace std;

#define endl                '\n'
#define pb                  push_back
#define ll                  long long int
#define full(x)             x.begin(),x.end()

const ll maxx = 1e6 + 7;

int base[2] = { 169, 369 };
ll mod[2] = { 1000003769, 1000004569 };
ll basePow[2][maxx];

ll hashTable2[2][maxx];
ll hashTable[2][maxx];

void init() {
    basePow[0][0] = basePow[1][0] = 1;
    for (int i = 1; i < maxx; i++) {
        basePow[0][i] = (basePow[0][i - 1] * base[0]) % mod[0];
        basePow[1][i] = (basePow[1][i - 1] * base[1]) % mod[1];
    }
}

void build_hashTable(string &str) { // 1 based inx
    hashTable[0][1] = hashTable[1][1] = (str[0] - 'a' + 1);
    for (int i = 1; str[i]; i++) {
        hashTable[0][i + 1] = ((hashTable[0][i] * base[0]) + (str[i] - 'a' + 1)) % mod[0];
        hashTable[1][i + 1] = ((hashTable[1][i] * base[1]) + (str[i] - 'a' + 1)) % mod[1];
    }
}

pair < ll, ll > get_subHash(int left, int right) { // 1 based inx
    pair < ll, ll > sub;
    sub.first = (hashTable[0][right] - (hashTable[0][left - 1] * basePow[0][right - left + 1])) % mod[0];
    sub.second = (hashTable[1][right] - (hashTable[1][left - 1] * basePow[1][right - left + 1])) % mod[1];
    if(sub.first < 0) sub.first += mod[0];
    if(sub.second < 0) sub.second += mod[1];
    return sub;
}

void build_hashTable2(string &str) { // 1 based inx
    hashTable2[0][1] = hashTable2[1][1] = (str[0] - 'a' + 1);
    for (ll i = 1; str[i]; i++) {
        hashTable2[0][i + 1] = ((hashTable2[0][i] * base[0]) + (str[i] - 'a' + 1)) % mod[0];
        hashTable2[1][i + 1] = ((hashTable2[1][i] * base[1]) + (str[i] - 'a' + 1)) % mod[1];
    }
}

pair < ll, ll > get_subHash2(int left, int right) { // 1 based inx
    pair < ll, ll > sub;
    sub.first = (hashTable2[0][right] - (hashTable2[0][left - 1] * basePow[0][right - left + 1])) % mod[0];
    sub.second = (hashTable2[1][right] - (hashTable2[1][left - 1] * basePow[1][right - left + 1])) % mod[1];
    if(sub.first < 0) sub.first += mod[0];
    if(sub.second < 0) sub.second += mod[1];
    return sub;
}

int main() {
    init();

    int t;
    cin >> t;
    while (t--) {
        string s, rs;
        cin >> s;

        rs = s;
        reverse(full(rs));

        build_hashTable(rs);
        build_hashTable2(s);

        int l = 1;
        int h = s.size();
        int ans;
        ll mid;

        while (l <= h) {
            mid = (l + h) / 2;

            pair < ll, ll > v = get_subHash2(1, mid);

            bool flag = false;
            for (int j = 1; j <= rs.size() - mid + 1; j++) {
                if (v == get_subHash(j, j + mid - 1)) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                ans = mid;
                l = mid + 1;
            }
            else h = mid - 1;
        }

        for (int i = ans - 1; i >= 0; i--) cout << s[i];
        cout << endl;
    }
}