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
    for(ll i = 6; i <= 50000000LL; i++){
        ll n = (i*(i-1))/2;
        ll l = (n*2)+(i*(i+1));
        ll left = i+1;
        ll right = 70000000LL;
        ll res = -1;
        while(left <= right){
            ll k = (left+right)/2;
            ll d = k*(k+1);
            if(d == l){
                res = k;
                break;
            }
            if(d < l) left = k+1;
            else right = k-1;
        }

        if(res != -1){
            cout << "  ";
            string temp;
            temp = to_string(i);
            int sp = 8 - temp.size();
            while(sp--) cout << ' ';
            cout << i << "  ";

            temp = to_string(res);
            sp = 8 - temp.size();
            while(sp--) cout << ' ';
            cout << res << endl;
        }
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    //ll t; cin >> t;
    //while(t--) solve();

    solve();

    
    return 0;
}