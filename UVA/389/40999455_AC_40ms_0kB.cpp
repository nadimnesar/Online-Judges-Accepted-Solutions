#include <bits/stdc++.h>
using namespace std;

#define  ll            long long
#define  elif          else if
#define  endl          '\n'
#define  rev(a)        reverse(a.begin(),a.end())


ll binpow(ll n, ll p) {
    if (p == 0) return 1;
    ll res = binpow(n, p / 2);
    if (p % 2) return res * res * n;
    else return res * res;
}

void baseConvert(string n, ll ib, ll cb) {
    string rs;
    ll res = 0;
    for (int i = n.size() - 1, j = 0; i >= 0; i--, j++) {
        if (n[i] >= '0' and n[i] <= '9') {
            res += (n[i] - '0') * binpow(ib, j);
        }
        else {
            if (n[i] == 'A') {
                res += 10 * binpow(ib, j);
            }
            elif(n[i] == 'B') {
                res += 11 * binpow(ib, j);
            }
            elif(n[i] == 'C') {
                res += 12 * binpow(ib, j);
            }
            elif(n[i] == 'D') {
                res += 13 * binpow(ib, j);
            }
            elif(n[i] == 'E') {
                res += 14 * binpow(ib, j);
            }
            else {
                res += 15 * binpow(ib, j);
            }
        }
    }
    while (res > 0) {
        ll md = res % cb;
        if (md >= 10 and md <= 15) {
            if (md == 10) {
                rs += 'A';
            }
            elif(md == 11) {
                rs += 'B';
            }
            elif(md == 12) {
                rs += 'C';
            }
            elif(md == 13) {
                rs += 'D';
            }
            elif(md == 14) {
                rs += 'E';
            }
            else {
                rs += 'F';
            }
        }
        else {
            rs += md + '0';
        }
        res /= cb;
    }
    if (rs.size() == 0) rs = '0';
    if (rs.size() > 7) cout << "  ERROR" << endl;
    else {
        for (int i = 0; i < 7 - rs.size(); i++) {
            cout << " ";
        }
        rev(rs);
        cout << rs << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string n;
    ll ib, cb;
    while (cin >> n >> ib >> cb) {
        baseConvert(n, ib, cb);
    }

    return 0;
}