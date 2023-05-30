#include <bits/stdc++.h>
using namespace std;
 
#define llu                 long long unsigned int
#define ll                  long long int
 
#define ff                  first
#define ss                  second
#define pb                  push_back
#define popb                pop_back
#define in                  insert
#define pf                  printf
#define sf                  scanf

#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define dot(x)              fixed<<setprecision(x)

#define EPS                 (double)(1e-7)
#define MAX                 (ll)(1e5+7)
#define MOD                 (ll)(1e9+7)
#define PI                  (double)(acos(-1.0))
#define LOG(b, x)           (double)(log(x)/log(b))
 
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}


void solve(){
    int n;
    sf("%d", &n);
    bool flag = true;
    for(int i = 0; i < n; i++){
        int sh, sm, ss;
        int eh, em, es;
        sf("%d:%d:%d %d:%d:%d", &sh, &sm, &ss, &eh, &em, &es);

        // debug(sh, sm, ss);
        // debug(eh, em, es);

        int total_start = ss;
        total_start += sm*60;
        total_start += sh*60*60;

        int total_end = es;
        total_end += em*60;
        total_end += eh*60*60; 

        int total = total_end - total_start;

        if(total >= 10800) flag = false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){

    // ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}