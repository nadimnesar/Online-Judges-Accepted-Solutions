#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define base 69

ll get_hashValue(string &str) {
    ll res = 0;
    for (ll i = 0; str[i]; i++) {
        res *= base;
        res += (str[i] - 'a' + 1);
    }
    return res;
}

void solve() {

    map < ll, string > mp;
    string s;
    while (getline(cin, s) and s.size()) {
        istringstream ss(s);
        string eng, china;
        ss >> eng >> china;
        mp[get_hashValue(china)] = eng;
    }

    while (cin >> s) {
        string res;
        res = mp[get_hashValue(s)];

        if (res.size()) cout << res << endl;
        else cout << "eh" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}