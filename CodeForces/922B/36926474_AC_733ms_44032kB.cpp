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

ll n;
set < pair < ll, pair < ll, ll > > > st; 

void solve(){
    cin >> n;

    ll res = 0;
    for(ll i = 1; i <= n; i++){
        for(ll j = i; j <= n; j++){
            ll x = (i^j);
            if(x <= n and x < i+j){
                ll k = x;
                double s = (i+j+k)/2.0;
                double area = s*(s-i)*(s-j)*(s-k);
                if(area > eps){

                    vector < ll > temp;
                    temp.pb(i); temp.pb(j); temp.pb(k);
                    sort(full(temp));

                    st.in({temp[0], {temp[1], temp[2]}});
                }
            }
        }
    }

    cout << st.size() << endl;
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