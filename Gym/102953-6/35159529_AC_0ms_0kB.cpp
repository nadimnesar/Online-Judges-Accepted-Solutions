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

map < ll, ll > um;

ll nCr(ll n, ll r){
    if(r == 2) return (n*(n-1))/2;
    else return (n*(n-1)*(n-2))/6;
}

void solve(){
    ll n, m;
    cin >> n >> m;

    vector < ll > arr;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;

        if(m%temp == 0){

            if(um[temp] == 0) arr.pb(temp);
            um[temp]++;
            
        }
    }

    n = arr.size();
    ll res = 0;

    for(ll i = 0; i < n; i++){

        if(arr[i]*arr[i]*arr[i] == m) res += nCr(um[arr[i]], 3);
        
        for(ll j = i+1; j < n; j++){

            if(arr[i]*arr[i]*arr[j] == m) res += nCr(um[arr[i]], 2)*(um[arr[j]]);
            if(arr[j]*arr[j]*arr[i] == m) res += nCr(um[arr[j]], 2)*(um[arr[i]]);

            for(ll k = j+1; k < n; k++){
                if(arr[i]*arr[j]*arr[k] == m){
                    res += (um[arr[i]]*um[arr[j]]*um[arr[k]]);
                }
            }
        }
    }

    cout << res << endl;
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}
