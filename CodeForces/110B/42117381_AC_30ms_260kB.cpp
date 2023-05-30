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

void solve() {
    ll n;
    cin >> n;

    string s;
    for(ll i = 0; i < n; i++) s += ' ';

    char ch = 'a';
    for(ll i = 0; i < n; i++){
        if(s[i] != ' ') continue;
        for(ll j = i; j < n; j += 4) s[j] = ch;
        ch++;
    }

    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}