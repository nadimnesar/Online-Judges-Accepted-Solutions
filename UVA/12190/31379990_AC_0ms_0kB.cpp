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

ll magic(ll n){
    ll res = 0;
    res += min((n/2), (ll)100);
    n -= min((n/2), (ll)100)*2;
    res += min((n/3), (ll)9900);
    n -= min((n/3), (ll)9900)*3;
    res += min((n/5), (ll)990000);
    n -= min((n/5), (ll)990000)*5;
    res += (n/7);
    return res;
}

ll pagic(ll n){
    int res = 0;
    res += min(n*2, (ll)2*100); n -= min(n*2, (ll)2*100)/2;
    res += min(n*3, (ll)3*9900); n -= min(n*3, (ll)3*9900)/3;
    res += min(n*5, (ll)5*990000); n -= min(n*5, (ll)5*990000)/5;
    res += n*7;
    return res;
}

void solve(){
    ll total, diff;
    while(cin >> total >> diff){
        if(!total and !diff) break;

        ll unit = magic(total);

        ll low = 0;
        ll high = unit;

        ll res;

        while(low <= high){
            ll mid = (low + high) >> 1;

            ll my = mid;
            ll your = unit - mid;

            ll amar = pagic(my);
            ll neighbor = pagic(your);

            if(abs(amar-neighbor) == diff){
                res = amar;
                break;
            }
            if(abs(amar-neighbor) < diff) high = mid - 1;
            else low = mid + 1;
        }
        cout << res << endl;
    }
}

int main(){

    fastIO;
    solve();
    return 0;

}
