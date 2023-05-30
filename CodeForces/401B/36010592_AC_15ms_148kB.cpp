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

    ll last, n;
    cin >> last >> n;

    if(n == 0){
        ll y = last-1;
        if(y%2 == 0) cout << y/2 << ' ' << y << endl;
        else cout << (y/2)+1 << ' ' << y << endl;
        return; 
    }

    ll cnt = 1;

    vector < pair < ll , ll > > r;

    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        if(x == 1){
            ll div2, div1;
            cin >> div2 >> div1;
            r.pb({div2, div1});
            cnt += 2;
        }
        else{
            ll div2;
            cin >> div2;
            cnt++;

            r.pb({div2, -1});
        }
    }

    sort(full(r));
    ll mini = 0;
    for(ll i = 0; i < r.size(); i++){
        if(i == 0){
            ll z = r[i].first-1;
            
            if(z%2 == 0) mini += z/2;
            else mini += (z/2)+1;
        }
        else{
            ll z;
            if(r[i-1].second == -1) z = (r[i].first-r[i-1].first)-1;
            else z = (r[i].first-r[i-1].second)-1;
            
            if(z%2 == 0) mini += z/2;
            else mini += (z/2)+1;
        }
    }

    ll z;
    if(r[r.size()-1].second == -1) z = (last - r[r.size()-1].first)-1;
    else z = (last - r[r.size()-1].second)-1;

    if(z%2 == 0) mini += z/2;
    else mini += (z/2)+1;

    ll maxi = last - cnt;
    cout << mini << ' ' << maxi << endl;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}