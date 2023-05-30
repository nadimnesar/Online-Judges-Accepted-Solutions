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
#define mod                 (ll)(998244353)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))
 
void solve(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        string str;
        cin >> str;

        ll res = 0;

        ll k = n-1;
        while(true){
            if(str[k] != '0'){
                res += str[k] - '0';
                str[k] = '0';
            }
            bool flag = false;
            for(ll i = 0; i < k; i++){
                if(str[i] != '0'){
                    swap(str[k], str[i]);
                    res++;
                    flag = true;
                    break;
                }
            }
            if(!flag) break;
        }

        cout << res << endl;
    }
}
 
int main(){
 
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 
    solve();
    
    return 0;
}