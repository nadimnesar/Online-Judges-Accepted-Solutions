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

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}


void solve(){
    ll n, m, cn = 0;
    while(cin >> n >> m){
        if(n <= 0 and m <= 0) break;
        cout << "Case " << ++cn << ": ";
        ll a = n, res = 0;
        while(true){
            if(n == 1){
                res++;
                break;
            }
            if(n > m) break;
            res++;
            if(n&1) n = (3LL*n*1LL)+1LL;
            else n = (n/2LL)*1LL;
        }
        cout << "A = " << a << ", limit = " << m << ", number of terms = " << res << endl;
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    //ll t; cin >> t;
    //while(t--) solve();

    solve();

    
    return 0;
}