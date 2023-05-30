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
    ll n;
    cin >> n;

    ll five = 0;
    ll zero = 0;

    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        if(temp == 5) five++;
        else zero++;
    }

    if(zero == 0) cout << "-1" << endl;
    else{
        ll maxi = 0;
        for(ll i = 1; i <= five; i++){
            if((i*5)%9 == 0){
                maxi = max(maxi, i);
            }
        }
        five = maxi;
        if(five == 0){
            cout << "0" << endl;
            return;
        }

        for(ll i = 1; i <= five; i++) cout << '5';
        for(ll i = 1; i <= zero; i++) cout << '0';
    }
}
 
int main(){
 
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 
    solve();
    
    return 0;
}