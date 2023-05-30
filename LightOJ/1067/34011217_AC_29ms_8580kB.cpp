#include <bits/stdc++.h>
using namespace std;

#define llu                 long long unsigned int
#define ll                  long long int

#define ff                  first
#define ss                  second
#define pb                  push_back
#define popb                pop_back
#define in                  insert

#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define dot(x)              fixed<<setprecision(x)

#define EPS                 (double)(1e-7)
#define MAX                 (ll)(1e6+7)
#define MOD                 (ll)(1e6+3)
#define PI                  (double)(acos(-1.0))
#define LOG(b, x)           (double)(log(x)/log(b))

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

ll factorial[MAX];

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

    //precalcualtion
    factorial[0] = 1;

    for(ll i = 1; i < MAX; i++)
        factorial[i] = ((factorial[i-1]%MOD)*(i%MOD))%MOD;

    ll t;
    cin >> t;
    ll cn = 0;
    while(t--){
        ll n, r;
        cin >> n >> r;

        cout << "Case " << ++cn << ": " << (factorial[n]%MOD  * (BIGMOD(((factorial[r]%MOD * factorial[n-r]%MOD)%MOD), MOD-2, MOD))%MOD)%MOD << endl;
    }
}

int main(){ ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); solve(); return 0; }