#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e5+7)                           
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

vector < ll > fib;

void pre(){
    ll p = 1;
    ll q = 2;
    fib.pb(p);
    fib.pb(q);
    for(int j = 0; j < 36; j++){
        ll temp = p+q;
        fib.pb(temp);
        p = q;
        q = temp;
    }
}

void solve(){
    pre();
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << n << " = ";
        string res;
        for(int j = fib.size()-1; j >= 0; ){
            if(fib[j] > n){
                j--;
                res += '0';
                continue;
            }
            n -= fib[j];
            res += '1';
            j--;
            if(j >= 0){
                res += '0';
                j --;
            }
        }
        bool flg = false;
        for(int i = 0; res[i]; i++){
            if(!flg and res[i] == '1'){
                flg = true;
            }
            if(flg) cout << res[i];
        }
        cout << " (fib)" << endl;
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}