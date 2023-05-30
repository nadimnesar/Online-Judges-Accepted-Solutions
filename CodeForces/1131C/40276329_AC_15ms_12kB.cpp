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
    ll n;
    cin >> n;

    vector < ll > v;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        v.pb(temp);
    }

    vector < ll > x;
    vector < ll > y;

    sort(full(v));

    while(v.size()){
        x.pb(v[v.size()-1]);
        v.pop_back();

        if(v.size()){
            y.pb(v[v.size()-1]);
            v.pop_back();
        }
    }

    reverse(full(y));

    for(ll i = 0; i < x.size(); i++){
        cout << x[i] << ' ';
    }

    for(ll i = 0; i < y.size(); i++){
        cout << y[i] << ' ';
    }

    cout << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}