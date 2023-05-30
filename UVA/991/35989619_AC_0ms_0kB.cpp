#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

llu ans[11];

void solve(){
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 5;
    for(ll i = 4; i <= 10; i++){

        llu y = 1;
        for(ll j = 1; j <= i*2; j++){
            y *= j;
        }

        llu x = 1;
        for(ll j = 1; j <= i; j++){
            x *= j;
        }
        x *= x;

        ans[i] = y/x;
        x = 1;
        for(ll j = 1; j <= i-1; j++){
            x *= j;
        }

        y /= x;
        x = 1;
        for(ll j = 1; j <= (i*2)-(i-1); j++){
            x *= j;
        }

        y /= x;
        ans[i] -= y;
    }
    ll n;
    bool flag = false;
    while(cin >> n){
        if(flag) cout << endl;
        else flag = true;
        cout << ans[n] << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}