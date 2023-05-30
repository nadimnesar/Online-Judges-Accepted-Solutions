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
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

unordered_map < ll, ll > um;

void solve(){
    ll cn = 0;
    ll Z, I, M, L;
    while(cin >> Z >> I >> M >> L){
        if(!Z and !I and !M and !L) break;

        cout << "Case " << ++cn << ": ";
        ll cnt = 0;
        ll i = 0;
        while(true){
            if(!um[L]){
                cnt++;
                um[L] = i++;
            }
            else{
                cout << cnt-um[L] << endl;
                break;
            }
            L = (Z * L + I)%M;
        }
        um.clear();
    }
    
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}