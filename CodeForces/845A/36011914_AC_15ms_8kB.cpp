#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e3+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){

    ll n;
    cin >> n;

    vector < ll > arr;
    for(ll i = 0; i < 2*n; i++){
        ll temp;
        cin >> temp;

        arr.pb(temp);
    }

    sort(full(arr));


    for(ll i = 0; i < n; i++){
        for(ll j = n; j < 2*n; j++){
            if(arr[i] >= arr[j]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    

    cout << "YES" << endl;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}