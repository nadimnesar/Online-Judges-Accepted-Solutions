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

ll nine(string s) {
    // cout << s << endl;
    if (s.size() & 1) return ((s.size() - 1) / 2) + 1;
    return 1;
}

void solve() {
    string s;
    cin >> s;

    ll res = 1;

    bool a18 = false;
    bool a27 = false;
    bool a36 = false;
    bool a45 = false;

    string temp;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if (a18 and temp[temp.size() - 1] == '8') temp += s[i];
            else {
                if (temp.size() >= 2) res *= nine(temp);
                temp.clear();
                temp += s[i];
                a18 = true;
                a27 = false;
                a36 = false;
                a45 = false;
            }
        }
        else if (s[i] == '8') {
            if (a18 and temp[temp.size() - 1] == '1') temp += s[i];
            else {
                if (temp.size() >= 2) res *= nine(temp);
                temp.clear();
                temp += s[i];
                a18 = true;
                a27 = false;
                a36 = false;
                a45 = false;
            }
        }
        else if (s[i] == '2') {
            if (a27 and temp[temp.size() - 1] == '7') temp += s[i];
            else {
                if (temp.size() >= 2) res *= nine(temp);
                temp.clear();
                temp += s[i];
                a18 = false;
                a27 = true;
                a36 = false;
                a45 = false;
            }
        }
        else if (s[i] == '7') {
            if (a27 and temp[temp.size() - 1] == '2') temp += s[i];
            else {
                if (temp.size() >= 2) res *= nine(temp);
                temp.clear();
                temp += s[i];
                a18 = false;
                a27 = true;
                a36 = false;
                a45 = false;
            }
        }
        else if (s[i] == '3') {
            if (a36 and temp[temp.size() - 1] == '6') temp += s[i];
            else {
                if (temp.size() >= 2) res *= nine(temp);
                temp.clear();
                temp += s[i];
                a18 = false;
                a27 = false;
                a36 = true;
                a45 = false;
            }
        }
        else if (s[i] == '6') {
            if (a36 and temp[temp.size() - 1] == '3') temp += s[i];
            else {
                if (temp.size() >= 2) res *= nine(temp);
                temp.clear();
                temp += s[i];
                a18 = false;
                a27 = false;
                a36 = true;
                a45 = false;
            }
        }
        else if (s[i] == '4') {
            if (a45  and temp[temp.size() - 1] == '5') temp += s[i];
            else {
                if (temp.size() >= 2) res *= nine(temp);
                temp.clear();
                temp += s[i];
                a18 = false;
                a27 = false;
                a36 = false;
                a45 = true;
            }
        }
        else if (s[i] == '5') {
            if (a45 and temp[temp.size() - 1] == '4') temp += s[i];
            else {
                if (temp.size() >= 2) res *= nine(temp);
                temp.clear();
                temp += s[i];
                a18 = false;
                a27 = false;
                a36 = false;
                a45 = true;
            }
        }
        else {
            if (temp.size() >= 2) res *= nine(temp);
            temp.clear();
        }
    }
    if (temp.size() >= 2) res *= nine(temp);

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}