#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                "\n"
#define in                  insert             
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(1e7+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){
    ll row, col, k;
    while(cin >> row >> col >> k){
        if(row == 0 and col == 0 and k == 0) break;
        cout << (((row-7) * (col-7))+k)/2 << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }

    solve();
    
    return 0;
}