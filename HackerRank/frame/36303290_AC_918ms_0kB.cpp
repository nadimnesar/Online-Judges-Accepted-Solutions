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
    ll row, col;
    cin >> row >> col;

    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;

        if(x == 1 or x == 2) cout << "YES" << endl;
        else if((((row-2)%x == 0) and (col%x == 0)) or ((row%x == 0) and ((col-2)%x == 0))) cout << "YES" << endl;
        else if((row-1)%x == 0 and (col-1)%x == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}