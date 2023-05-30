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
#define MAX                 (ll)(1e5+7)
#define MOD                 (ll)(1e9+7)
#define PI                  (double)(acos(-1.0))
#define LOG(b, x)           (double)(log(x)/log(b))
#define INF                 (0x3f3f3f3f)

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

void solve(){
    ll t;
    cin >> t;
    while(t--){
        ll k;
        cin >> k;

        vector < ll > arr;
        for(ll i  = 0; i < k; i++){
            ll temp;
            cin >> temp;
            arr.pb(temp);
        }

        if(k==1){
            cout << "Better luck next time!" << endl;
            continue;
        }

        ll num_zero = 0;
        ll one = 0;
        for(int i = 0; i < k; i++){
            if(arr[i] == 0){
                num_zero++;
            }
            if(arr[i] == 1){
                one++;
            }
        }

        if(one == 0){
            cout << "Better luck next time!" << endl;
            continue;
        }

        if(num_zero == k){
            cout << "Better luck next time!" << endl;
            continue;
        }

        cout << "Happy Birthday Tutu!" << endl;

    }

}

int main(){

    solve();
    
    return 0;
}