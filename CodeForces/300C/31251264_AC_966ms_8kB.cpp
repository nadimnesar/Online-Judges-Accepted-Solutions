#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y)))

#define EPS              (1e-7)
#define MAX              (1e5+7)
#define MOD              (int)(1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

ll a, b, n;
bool magic(int good){
    ll ok = true;
    while(good){
        ll x = good%10;
        if(x == a or x == b) good /= 10;
        else{
            ok = false;
            break;
        }
    }
    return ok;
}

ll factorialmod(int n){
    ll nfactorial = 1;
    for(ll i = 1; i <= n; i++) nfactorial = ((nfactorial%MOD) * (i%MOD))%MOD;
    return nfactorial;
}

ll BIGMOD(ll B, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll p1=(BIGMOD(B,P/2,M))%M;
        return (p1*p1)%M;
    }
    else{
        ll p1=B%M;
        ll p2=(BIGMOD(B,P-1,M))%M;
        return (p1*p2)%M;
    }
}

void solve(){
    cin >> a >> b >> n;
    ll nfactorial = 1;
    for(ll i = 1; i <= n; i++) nfactorial = ((nfactorial%MOD) * (i%MOD))%MOD;
    ll res = 0;
    for(ll i = n, j = 0; i >= 0; i--, j++){
        ll sum = (a * i) + (b * j);
        if(magic(sum)) res = ((res%MOD) + (nfactorial * BIGMOD(((factorialmod(i) * factorialmod(j))%MOD), MOD-2, MOD)%MOD))%MOD;
    }
    cout << res << endl;
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }

}