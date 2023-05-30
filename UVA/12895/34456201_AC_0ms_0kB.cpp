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

ll power[10][11];
void prePow(){
    power[0][0] = 1;
    for(int i = 1; i <= 10; i++) power[0][i] = 0;

    for(int i = 1; i <= 9; i++){
        power[i][0] = 1;
        for(int j = 1; j <= 10; j++){
            power[i][j] = power[i][j-1]*i;
        }
    }
}

void solve(){

    prePow();

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll sum = 0;

        string str = to_string(n);
        int base = str.size();
        for(int i = 0; str[i]; i++){
            sum += power[str[i]-'0'][base];
        }

        if(sum == n) cout << "Armstrong" << endl;
        else cout << "Not Armstrong" << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}