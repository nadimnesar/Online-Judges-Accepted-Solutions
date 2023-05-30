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

    ll zero = 0;
    ll one = 0;
    ll two = 0;

    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;

        if(temp%3 == 0) zero++;
        if(temp%3 == 1) one++;
        if(temp%3 == 2) two++;
    }

    ll mn = (zero+one+two)/3;
    ll res = 0;

    while(zero < mn){
        if(two > mn){
            ll x = min(two-mn, mn-zero);
            zero += x;
            two -= x;
            res += x;
        }
        else if(one > mn){
            ll x = min(one-mn, mn-zero);
            zero += x;
            one -= x;
            res += x*2;
        }
        else break;
    }

    while(one < mn){
        if(zero > mn){
            ll x = min(zero-mn, mn-one);
            one += x;
            zero -= x;
            res += x;
        }
        else if(two > mn){
            ll x = min(two-mn, mn-one);
            one += x;
            two -= x;
            res += x*2;
        }
        else break;
    }

    while(two < mn){
        if(one > mn){
            ll x = min(one-mn, mn-two);
            two += x;
            one -= x;
            res += x;
        }   
        else if(zero > mn){
            ll x = min(zero-mn, mn-two);
            two += x;
            zero -= x;
            res += x*2;
        }
        else break;
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--) nadimnesar();

    return 0;
}