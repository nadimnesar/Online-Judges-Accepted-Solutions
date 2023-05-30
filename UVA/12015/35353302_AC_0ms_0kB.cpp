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


void solve(){

    ll t;
    cin >> t;
    ll cn = 0;
    while(t--){
        vector < string > url;
        vector < ll > point;

        string str;
        ll temp;
        ll max_pont = 0;
        for(int i = 0; i < 10; i++){
            cin >> str >> temp;
            max_pont = max(temp, max_pont);
            url.pb(str);
            point.pb(temp);
        }
        cout << "Case #" << ++cn << ":" << endl;
        for(int i = 0; i < 10; i++){
            if(point[i] == max_pont){
                cout << url[i] << endl;
            }
        }
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}