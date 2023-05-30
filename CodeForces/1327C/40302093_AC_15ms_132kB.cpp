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
    ll n, m, k;
    cin >> n >> m >> k;

    for(ll i = 0; i < 2*k; i++){
        ll x, y;
        cin >> x >> y;
    }

    string res;

    for(ll i = 0; i < m-1; i++) res.pb('L');
    for(ll i = 0; i < n-1; i++) res.pb('U');

    bool flag = true;
    while(n--){
        if(flag) for(ll i = 0; i < m-1; i++) res.pb('R');
        else for(ll i = 0; i < m-1; i++) res.pb('L');
        if(n) res.pb('D');
        flag = !flag;
    }

    if(res.size() > 2*n*m) cout << "-1" << endl;
    else{
        cout << res.size() << endl;
        cout << res << endl;
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);


    nadimnesar();
    

    return 0;
}