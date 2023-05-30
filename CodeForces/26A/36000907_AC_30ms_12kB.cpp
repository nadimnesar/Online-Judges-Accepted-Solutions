#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e3+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){

    ll n;
    cin >> n;

    ll res = 0;

    for(ll i = 1; i <= n; i++){

        ll m = i;
        ll p = 0;
        bool flag = false;
        while(m%2 == 0){
            m /= 2;
            flag = true;
        }
        if(flag) p++;

        for(ll j = 3; j <= m; j+=2){
            flag = false;
            while(m % j == 0){
                m /= j;
                flag = true;
            }
            if(flag) p++;
        }

        if(p == 2){
            res ++;
        }
    }
    cout << res << endl;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}