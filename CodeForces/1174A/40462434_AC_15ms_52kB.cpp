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
    for(ll i = 0; i < 2*n; i++){
        ll temp;
        cin >> temp;
        v.pb(temp);
    }

    sort(full(v));

    ll sum1 = 0, sum2 = 0;
    for(ll i = 0; i < n; i++) sum1 += v[i];
    for(ll i = n; i < 2*n; i++) sum2 += v[i];

    if(sum1 == sum2) cout << "-1" << endl;
    else{
        for(ll i = 0; i < v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << endl;
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}