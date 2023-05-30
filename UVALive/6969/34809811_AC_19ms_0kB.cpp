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
    while(t--){
        ll n, m;
        cin >> n >> m;

        double temp, avg1 = 0, avg2 = 0;
        for(int i = 0; i < n-1; i++){
            cin >> temp;
            avg1 += temp;
        }

        avg1 /= n-1;

        for(int i = 0; i < m; i++){
            cin >> temp;
            avg2 += temp;
        }

        avg2 /= m;

        int maxi, mini;

        int x = avg1;
        if(abs(avg1-x) <= eps) maxi = x-1;
        else maxi = x;

        x = avg2;
        mini = x+1;

        cout << mini << ' ' << maxi << endl;   
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}