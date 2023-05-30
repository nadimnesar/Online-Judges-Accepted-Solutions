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
#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void nadimnesar() {
    ll n;
    cin >> n;

    map < ll, ll > table;
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        table[temp]++;
    }

    ll res = 0;
    for(ll i = 1; i <= 150001; i++){
if(table[i-1] > 0){
            res++;
            table[i-1]--;
            continue;
        }
        if(table[i] > 0){
            res++;
            table[i]--;
            continue;
        }

        if(table[i+1] > 0){
            res++;
            table[i+1]--;
            continue;
        }

        
    }

    cout << (ll)res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}