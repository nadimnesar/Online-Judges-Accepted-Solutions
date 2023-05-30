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

    string x, y;
    cin >> x;
    cin >> y;
    
    ll res = 0;
    for(ll i = 0; i < n; i++){
        if((x[i] == '0' and y[i] == '1') or (x[i] == '1' and y[i] == '0')) res += 2;
        if(x[i] == '0' and y[i] == '0'){
            if(i+1 < n){
                if(x[i+1] == '1' and y[i+1] == '1'){
                    i++, res += 2;
                    continue;
                }
                else res += 1;
            }
            else res += 1;
        }
        if(x[i] == '1' and y[i] == '1'){
            if(i+1 < n){
                if(x[i+1] == '0' and y[i+1] == '0'){
                    i++, res += 2;
                    continue;
                }
                if(x[i+1] == '0' and y[i+1] == '1'){
                    i++, res += 2;
                    continue;
                }
            }
        }
    }

    cout << res << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--) nadimnesar();

    return 0;
}