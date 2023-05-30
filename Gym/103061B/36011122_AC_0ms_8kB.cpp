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

    string str;
    cin >> str;

    ll n = str.size();

    ll mini = n;
    bool flag = false;
    for (ll i = 0; i < n; i++){
        for (ll j = 1; j <= n - i; j++){
            string p = str.substr(i, j);
            string cp = p;
            reverse(full(cp));
            if(p != cp){
                flag = true;
                mini = min(mini, (ll)p.size());
            }
        }
    }

    if(!flag) cout << "-1" << endl;
    else cout << mini << endl;

    
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}