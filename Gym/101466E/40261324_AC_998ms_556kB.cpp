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

void nadimnesar() {
    string s, org;
    getline(cin, s);
    getline(cin, org);

    ll n;
    cin >> n;

    ll left = 0;
    ll right = org.size()-1;

    string res;

    while (left <= right) {

        ll mid = left + (right-left)/2;

        // cout << mid << endl;

        string fake = org.substr(0, mid+1);

        // cout << fake << endl;

        ll pos = 0;
        ll cnt = 0;
        while (true){
            ll idx = s.find(fake, pos);
            if(idx == -1) break;
            cnt++;
            pos = idx+1;
        }

        // cout << cnt << endl;

        if (cnt >= n) {
            res = fake;
            left = mid+1;
        }
        else right = mid-1;
    }

    if(res.size() == 0) cout << "IMPOSSIBLE" << endl;
    else cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}