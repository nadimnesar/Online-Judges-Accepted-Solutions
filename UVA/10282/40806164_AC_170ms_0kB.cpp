#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define base 69
#define mod 1001069

ll get_hashValue(string &str) {
  ll res = 0;
  for (ll i = 0; str[i]; i++) {
    res *= base; res %= mod;
    res += (str[i] - 'a' + 1);
  }
  return res;
}

vector < pair < string, string > > mp[1001069+1];

void solve() {
    string s;
    while (getline(cin, s) and s.size()) {
        istringstream ss(s);
        string eng, china;
        ss >> eng >> china;
        mp[get_hashValue(china)].push_back({eng, china});
    }

    while (cin >> s) {
        vector < pair < string, string > > res = mp[get_hashValue(s)];
        bool flag = false;
        for(ll i = 0; i < res.size(); i++){
            if(res[i].second == s){
                cout << res[i].first << endl;
                flag = true;
                break;
            }
        }
        if(!flag) cout << "eh" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}