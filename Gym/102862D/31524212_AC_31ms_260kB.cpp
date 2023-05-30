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
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define rremove(x, y)       x.erase(remove(x.begin(),x.end(),y),x.end())
#define fastIO              ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#define EPS                 (1e-7)
#define MAX                 (int)(1e5+7)
#define MOD                 (1e9+7)
#define PI                  (acos(-1.0))
#define LOG(b, x)           (log(x)/log(b))
 
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';}

void solve(){
    int n; cin >> n;
    string str;
    cin >> str;
    int res = 0;
    int v = 0, c = 0; 
    for(int i = 0; i < n; i++){
        if(str[i] == 'a' or str[i] == 'i' or str[i] == 'o' or str[i] == 'u' or str[i] == 'e' or str[i] == 'y') v++;
        else c++;
        if(v >= 1 and c >= 1){
            res++;
            v = 0;
            c = 0;
        }
    }
    cout << res << endl;
}

int main(){
    solve();
    return 0;
}