#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(2e7+7)
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){
    ll a, b, n;
    cin >> a >> b >> n;
    
    bool a_turn = true;
    while(true){
        if(a_turn){
            ll x = __gcd(a, n);
            if(x <= n) n -= x;
            else{
                cout << "1" << endl;
                break;
            }
        }
        else{
            ll x = __gcd(b, n);
            if(x <= n) n -= x;
            else{
                cout << "0" << endl;
                break;
            }
        }
        a_turn = !(a_turn);
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}
