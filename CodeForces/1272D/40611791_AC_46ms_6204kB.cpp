#include <bits/stdc++.h>
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
    ll n;
    cin >> n;

    vector < ll > v;
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        v.pb(temp);
    }

    ll res = 1;

    vector < ll > left_lis(n, 1);
    for (ll i = 1; i < n; i++) {
        if (v[i] > v[i - 1]) left_lis[i] = left_lis[i - 1] + 1;
        res = max(res, left_lis[i]);
    }

    vector < ll > right_lis(n, 1);
    for (ll i = n-2; i >= 0; i--) {
        if (v[i] < v[i + 1]) right_lis[i] = right_lis[i + 1] + 1;
        res = max(res, right_lis[i]);
    }

    for(ll i = 0; i < n-2; i++){
        if(v[i] < v[i+2]){
            res = max(res, left_lis[i]+right_lis[i+2]);
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}