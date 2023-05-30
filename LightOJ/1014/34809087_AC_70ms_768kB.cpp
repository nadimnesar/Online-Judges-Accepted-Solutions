#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e6+7)
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
    int t;
    cin >> t;
    int cn = 0;
    while(t--){
        int p, l;
        cin >> p >> l;
        vector < int > arr;
        int x = p-l;
        cout << "Case " << ++cn << ":";

        if(x <= l){
            cout << " impossible" << endl;
            continue;
        }
        for(ll i = 1; i*i <= x; i++){
            if(x%i == 0){
                if(i > l) arr.pb(i);
                if(i*i != x and (x/i) > l)  arr.pb(x/i);
            }
        }
        
        if(arr.size() == 0) cout << " impossible" << endl;
        else{
            sort(full(arr));
            for(int i  = 0; i < arr.size(); i++){
                cout << ' ' << arr[i];
            }
            cout << endl;
        }
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}