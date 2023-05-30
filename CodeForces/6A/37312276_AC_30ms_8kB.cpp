#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define ppb                 pop_back
#define ppf                 pop_front
#define pb                  push_back
#define pf                  push_front

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)23
#define maxx                (ll)(1e3+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    vector < ll > data;
    data.pb(a); data.pb(b);
    data.pb(c); data.pb(d);

    bool dg = false, t = false;

    for(ll i = 0; i < 4; i++){
        for(ll j = i+1; j < 4; j++){
            for(ll k = j+1; k < 4; k++){

                double s = (data[i]+data[j]+data[k])/2.0;
                double area = s*(s-data[i])*(s-data[j])*(s-data[k]);

                if(area < 0) continue;

                if(area == 0){
                    dg = true;
                    continue;
                }

                t = true;
            }
        }
    }

    if(t) cout << "TRIANGLE" << endl;
    else if(dg) cout << "SEGMENT" << endl;
    else cout << "IMPOSSIBLE" << endl;
}
 
int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // int t, cn = 0;
    // cin >> t;
    // while (t--) {
    //     // cout << "Case " << ++cn << ": ";
    //     solve();
    // }

    solve();


    return 0;
}