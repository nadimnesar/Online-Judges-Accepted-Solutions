#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y)))

#define EPS              (1e-7)
#define MAX              (1e5+7)
#define MOD              (int)(1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

void solve(){
    llu a, b;
    cin >> a >> b;
    if((b-a)+1 > 3) cout << 0 << endl;
    else{
        vector < ll > v;
        for(ll i = a; i <= b; i++){
            if(i == 0) v.pb(1);
            else if(i == 1) v.pb(0);
            else if(i == 3) v.pb(1);
            else if((i-1)%4 == 0) v.pb(0);
            else if((i-1)%2 == 0) v.pb(1);
            else{
                if(i-1 == 3) v.pb(i+1);
                else if(i-1 == 0) v.pb(i);
                else if((i-2)%4 == 0) v.pb(i);
                else if((i-2)%2 == 0) v.pb(i+1);
            }
        }
        // cout << v.size() << endl;
        ll res = v[0];
        for(ll i = 1; i < v.size(); i++){
            res = res&v[i];
        }
        cout << res << endl;
    }
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin >> t;
    // int cn = 0;
    while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    }

}