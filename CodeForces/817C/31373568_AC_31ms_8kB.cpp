#include <bits/stdc++.h>
using namespace std;

#define llu                 long long unsigned int
#define ll                  long long int

#define ff                  first
#define ss                  second
#define pb                  push_back
#define pob                 pop_back
#define in                  insert
#define pf                  printf
#define sf                  scanf

#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define rremove(x, y)       x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)       x.resize(distance(x.begin(),unique(x.begin(),x.begin()+y)))
#define fastIO              ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define EPS                 (1e-7)
#define MAX                 (4e4+7)
#define MOD                 (1e9+7)
#define PI                  (acos(-1.0))
#define LOG(b, x)           (log(x)/log(b))

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

ll n, s;
ll sumofdigits(ll x){
    ll res = 0;
    while(x){
        res += x%10;
        x /= 10;
    }
    return res;
}

ll magic(ll p){
    ll x = p;
    ll res = 0;
    while(x){
        res += x%10;
        x /= 10;
    }
    return abs(res-p);
}

void solve(){
    cin >> n >> s;
    ll low = 1;
    ll high = n;
    ll left = -1;
    while(low <= high){
        ll mid = ((low+high) >> 1);
        ll res = magic(mid);
        if(res >= s){
            left = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    if(left == -1) cout << 0 << endl;
    else cout << n-(left-1) << endl;
}

int main(){

    fastIO;
    solve();
    return 0;

}