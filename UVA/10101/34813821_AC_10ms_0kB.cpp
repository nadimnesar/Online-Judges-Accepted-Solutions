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

void recall(ll n){
    ll x;
    if(n >= 10000000){
        x = n/10000000;
        recall(x);
        cout << " kuti";
        n %= 10000000;
    }

    if(n >= 100000){
        x = n/100000;
        recall(x);
        cout << " lakh";
        n %= 100000;
    }

    if(n >= 1000){
        x = n/1000;
        recall(x);
        cout << " hajar";
        n %= 1000;
    }

    if(n >= 100){
        x = n/100;
        recall(x);
        cout << " shata";
        n %= 100;
    }

    if(n) cout << " " << n;
}

void solve(){
    ll n;
    int cn = 0;
    vector < ll > arr;
    while(cin >> n){
        arr.pb(n);
    }

    string str = to_string(arr.size());
    ll sp = str.size();

    for(int i = 0; i < arr.size(); i++){
        str = to_string(++cn);
        ll ssp = str.size();
        ll q = sp - ssp;
        while(q--) cout << ' ';
        cout << cn << ".";
        if(arr[i] == 0) cout << " " << arr[i];
        else recall(arr[i]);
        cout << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}