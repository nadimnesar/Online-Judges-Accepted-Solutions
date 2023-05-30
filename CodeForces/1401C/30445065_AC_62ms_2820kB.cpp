#include <bits/stdc++.h>
using namespace std;

#define ull              long long unsigned int
#define ll               long long int
#define pb               push_back

#define bug              cout << "!!!!!!" << endl
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl

#define full(x)          x.begin(), x.end()
#define dot(x)           fixed << setprecision(x)
#define iremove(x, y)    x.erase(x.begin() + y)
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y))) //for sorted array

#define EPS              (1e-7)
#define MAX              (100)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

void solve(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector < ll > x;
        bool ok = true;
        ll temp;
        cin >> temp;
        x.pb(temp);
        ll mini = temp;
        for(ll i = 1; i < n; i++){
            cin >> temp;
            x.pb(temp);
            if(temp < x[i-1]) ok = false;
            mini = min(temp, mini);
        }
        if(ok){
             cout << "YES" << endl;
             continue;
        }
        ok = true;
        vector < ll > y = x;
        sort(full(y));
        for(ll i = 0; i < n; i++){
            if(x[i] == y[i]) continue;
            if(y[i]%mini == 0) continue;
            ok = false;
            break;
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    solve();

    
}