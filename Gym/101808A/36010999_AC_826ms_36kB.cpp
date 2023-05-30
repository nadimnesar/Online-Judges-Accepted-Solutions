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

    while(n--){
        double R, r;
        cin >> R >> r;

        ll ara1, ara2;
        ara1 = pi*R*R;
        ara2 = pi*r*r;
        ara2 += ara2;

        if((ara1 - ara2) > 0) cout << "1" << endl;
        else cout << "2" << endl;
    }
     
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}