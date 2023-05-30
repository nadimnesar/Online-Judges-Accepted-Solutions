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

    int n, m, k;
    cin >> n >> m >> k;

    vector < int > arr;
    int cnt = 0;

    bool flag = false;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp > m){
            k--;
            arr.pb(m);
        }
        else arr.pb(temp);

        if(arr[i] == m) flag = true;
    }

    if(k < 0){
        cout << "NO" << endl;
        return;
    }

    if(flag){
        cout << "YES" << endl;
        return;
    }

    if(k > 0){
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;

}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}