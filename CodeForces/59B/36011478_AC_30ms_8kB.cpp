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

    ll sum = 0;

    ll mini = 101;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;


        sum += temp;

        if(temp&1) mini = min(mini, temp);
    }

    if(sum&1) cout << sum << endl;
    else if(mini == 101) cout << "0" << endl;
    else cout << sum-mini << endl;
    
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}