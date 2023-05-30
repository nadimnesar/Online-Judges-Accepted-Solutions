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

void solve(){
    ll t;
    cin >> t;
    bool ok = false;
    while(t--){
        ll n;
        cin >> n;
        if(ok) cout << endl;
        else ok = true;
        ll pre_n = n;
        n = abs(n);

        ll low = 1;
        ll high = 1000000000LL;
        ll res = -1;
        ll paisi = -1;
        while(low <= high){
            ll mid = (low+high)/2;
            ll sum = (mid*(mid+1))/2;
            if(sum == n){
                paisi = mid;
                break;
            }
            if(sum > n){
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        if(paisi != -1) cout << paisi << endl;
        else{

            while(true){
                ll sum = (res*(res+1))/2;
                ll dis = sum - n;
                if(dis == 2){
                    if(res&1) res += 2;
                    else res++;
                }
                else if(dis&1){
                    if(res&1) res += 2;
                    else res++;
                }
                else break;
            }
            
            cout << res << endl;
        }
    }
}

int main(){
 
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
    
    return 0;
}