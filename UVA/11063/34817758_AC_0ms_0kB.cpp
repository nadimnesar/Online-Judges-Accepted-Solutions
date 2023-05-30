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

int arr[107];
unordered_map < int, bool > um;

void solve(){
    int n, cn = 0;
    while(cin >> n){
        bool flag = 1;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] <= 0) flag = 0;
        }
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(um[arr[i]+arr[j]]){
                    flag = 0;
                    break;
                }
                um[arr[i]+arr[j]] = true;
            }
        }
        for(int i = 0; i < n-1; i++){
            if(arr[i] >= arr[i+1]){
                flag = 0;
                break;
            }
        }
        cout << "Case #" << ++cn << ": ";
        if(flag) cout << "It is a B2-Sequence." << endl << endl;
        else cout << "It is not a B2-Sequence." << endl << endl;
        um.clear();
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    //ll t; cin >> t;
    //while(t--) solve();

    solve();

    
    return 0;
}