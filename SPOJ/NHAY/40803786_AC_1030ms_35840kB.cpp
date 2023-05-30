#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define endl                '\n'
const ll maxx = 1e6 + 7;
ll base[2] = { 169, 369 };
ll mod[2] = { 1000003769, 1000004569 };
ll hashTable[2][maxx];
ll basePow[2][maxx];

void init() {
  basePow[0][0] = basePow[1][0] = 1;
  for (ll i = 1; i < maxx; i++) {
    basePow[0][i] = (basePow[0][i - 1] * base[0]) % mod[0];
    basePow[1][i] = (basePow[1][i - 1] * base[1]) % mod[1];
  }
}

void build_hashTable(string &str) {
  hashTable[0][1] = hashTable[1][1] = (str[0] - 'a' + 1);
  for (ll i = 1; str[i]; i++) {
    hashTable[0][i+1] = (((hashTable[0][i] * base[0]) % mod[0]) + (str[i] - 'a' + 1)) % mod[0];
    hashTable[1][i+1] = (((hashTable[1][i] * base[1]) % mod[1]) + (str[i] - 'a' + 1)) % mod[1];
  }
}

ll get_subHash1D(ll left, ll right) {
  return (ll)(((hashTable[0][right] + mod[0]) - ((hashTable[0][left - 1] * basePow[0][right - left + 1]) % mod[0])) % mod[0]);
}

ll get_subHash2D(ll left, ll right) {
  return (ll)(((hashTable[1][right] + mod[1]) - ((hashTable[1][left - 1] * basePow[1][right - left + 1]) % mod[1])) % mod[1]);
}

ll get_hashValue1D(string &str) {
  ll res = 0;
  for (ll i = 0; str[i]; i++) {
    res *= base[0]; res %= mod[0];
    res += (str[i] - 'a' + 1);
  }
  return res;
}

ll get_hashValue2D(string &str) {
  ll res = 0;
  for (ll i = 0; str[i]; i++) {
    res *= base[1]; res %= mod[1];
    res += (str[i] - 'a' + 1);
  }
  return res;
}

int main() {
  init();
  ll n;
  string sub, str;

  while (cin >> n) {
    cin >> sub >> str;

    build_hashTable(str);
    ll value1D = get_hashValue1D(sub);
    ll value2D = get_hashValue2D(sub);

    ll len = str.size();
    bool ok = false;
    for (int i = 0; i < len - (n - 1); i++) {
      if (get_subHash1D(i+1, i + (n - 1)+1) == value1D and get_subHash2D(i+1, i + (n - 1)+1) == value2D) {
        cout << i << endl;
        ok = true;
      }
    }
    if (!ok) cout << endl;
  }
}