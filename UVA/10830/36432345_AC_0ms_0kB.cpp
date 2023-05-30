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

void solve(){
    ll n;
    ll cn = 0;
    while(cin >> n and n){
        cout << "Case " << ++cn << ": ";
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        if(n == 2){
            cout << 0 << endl;
            continue;
        }
        if(n == 3){
            cout << 0 << endl;
            continue;
        }
        ll res = 0;
        for(ll i = 2; i*i <= n; i++){
            res += (n / i)*(( n/i)+1)/2  - ((i-1)*(i))/2;
            res += ((((n/i) - i)+1)*i)-i;
        }
        cout << res << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}