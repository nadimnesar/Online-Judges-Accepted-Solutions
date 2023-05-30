#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define pb                  push_back
#define endl                '\n'

const int base = 69;
const int mod = 1000969;
const int maxx = 1e6 + 7;
const double eps = 1e-7;
const double pi = acos(-1.0);

ll get_hashValue(string &str) {
    ll res = 0;
    for (ll i = 0; str[i]; i++) {
        res *= base; res %= mod;
        res += (str[i] - 'a' + 1);
    }
    return res;
}

vector < pair < string, ll > > mp[mod + 1];

int main() {
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll x = get_hashValue(s);

        if (mp[x].size() == 0) {
            cout << "OK" << endl;
            mp[x].pb({s, 1});
            continue;
        }

        bool flag = false;
        for (ll j = 0; j < mp[x].size(); j++) {
            if (mp[x][j].first == s) {
                cout << s << mp[x][j].second << endl;
                mp[x][j] = {s, mp[x][j].second+1};
                flag = true;
                break;
            }
        }

        if(!flag){
            cout << "OK" << endl;
            mp[x].pb({s, 1});
        }
    }
}