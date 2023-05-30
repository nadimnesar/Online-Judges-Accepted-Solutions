#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        vector < pair < ll, ll > > students;
        for(ll i = 0; i < n; i++){
            ll x, y;
            cin >> x >> y;

            students.pb({x, y});
        }

        vector < ll > res;

        ll now = 1;
        for(ll i = 0; i < n; i++){
            if(now <= students[i].first){
                res.pb(students[i].first);
                now = students[i].first+1;
            }
            else{
                if(now <= students[i].second){
                    res.pb(now);
                    now++;
                }
                else res.pb(0);
            }
        }
        for(ll i = 0; i < n; i++){
            if(i == n-1) cout << res[i] << endl;
            else cout << res[i] << ' ';
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