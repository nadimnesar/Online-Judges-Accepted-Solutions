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
#define MAX                 (1e5+7)
#define MOD                 (1e9+7)
#define PI                  (acos(-1.0))
#define LOG(b, x)           (log(x)/log(b))
 
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

set < ll > good;
vector < ll > goodd;
ll binpow(ll n, ll p){
    if(p == 0) return 1;
    ll res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}

void builder(vector < ll > sub){
    ll len = sub.size();
    ll num = 0;
    for(ll i = 0; i < len; i++) num += binpow(3, sub[i]);
    good.in(num);
    return;
}

void allsubsets(vector < ll > &set, vector < ll > &sub, ll n, ll index){
    if(index == n){
        builder(sub);
        return;
    }
    sub.pb(set[index]);
    allsubsets(set, sub, n, index+1);
    sub.pop_back();
    allsubsets(set, sub, n, index+1);
}


void magic(){
    vector < ll > x;
    for(ll i = 0; i <= 9; i++) x.pb(i);
    vector < ll > sub;
    allsubsets(x, sub, 10, 0);
    for(auto it: good){
        goodd.pb(it);
    }
}

ll upperbound(ll q){
    ll right = goodd.size()-1;
    ll left = 0;
    ll up = -1;
    while(right >= left){
        ll mid = left + (right-left)/2;
        if(goodd[mid] > q){
            up = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    return up;
}

void solve(){
    ll n;
    cin >> n;
    ll res = upperbound(n);
    if(goodd[res-1] == n) cout << goodd[res-1] << endl;
    else cout << goodd[res] << endl;
}

int main(){
    fastIO;
    magic();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
