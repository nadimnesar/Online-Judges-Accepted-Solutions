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
    ll n, m;
    cin >> n >> m;

    string b;
    for(ll i = 0; i < m; i++) b.pb('B');
    
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;

        ll x = temp; x--;
        ll y = m+1-temp; y--;

        if(b[x] == 'A') b[y] = 'A';
        else if(b[y] == 'A') b[x] = 'A';
        else{
            if(x < y) b[x] = 'A';
            else b[y] = 'A';
        }
    }

    cout << b << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--){
        // cout << "Case #" << ++cn << ": ";
        nadimnesar();
    }

    return 0;
}