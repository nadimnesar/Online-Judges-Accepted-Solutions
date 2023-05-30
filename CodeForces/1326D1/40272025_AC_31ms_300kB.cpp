#include "bits/stdc++.h"
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

#define base                (ll)(10)
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

bool pelindrome(string s){
    string s2 = s;
    reverse(full(s2));
    return (s == s2);
}

void nadimnesar() {
    string s;
    cin >> s;


    string t;

    ll l = 0;
    ll r = s.size() - 1;

    while (l < r) {
        if (s[l] == s[r]) t.pb(s[l]);
        else break;

        l++;
        r--;
    }

    string s2 = s.substr(l, r - l + 1);
    string p1;
    while (s2.size()) {
        if(pelindrome(s2)){
            p1 = s2;
            break;
        }
        s2.pop_back();
    }

    s2 = s.substr(l, r - l + 1);
    string p2;
    while (s2.size()) {
        if(pelindrome(s2)){
            p2 = s2;
            break;
        }
        reverse(full(s2));
        s2.pop_back();
        reverse(full(s2));
    }

    string rt = t;
    reverse(full(rt));

    if(p1.size() > p2.size()) t = t + p1 + rt;
    else t = t + p2 + rt;

    cout << t << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--) nadimnesar();

    return 0;
}