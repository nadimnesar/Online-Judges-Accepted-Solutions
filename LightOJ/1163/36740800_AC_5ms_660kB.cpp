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
#define pqueue              priority_queue<ll,vector<ll>,greater<ll>>
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(3e5+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){
    llu n;
    cin >> n;

    llu low = n;
    llu high = 1e19;

    while(high >= low){
        ll mid = (high+low)/2;

        if(mid - (mid/10) == n){
            if((mid+1) - ((mid+1)/10) == n) cout << mid << ' ' << mid+1 << endl;
            else if((mid-1) - ((mid-1)/10) == n) cout << mid-1 << ' ' << mid << endl;
            else cout << mid << endl;
            break;
        }

        if(mid - (mid/10) < n) low = mid+1;
        else high = mid - 1;
    }
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t, cn = 0;
    cin >> t;
    while(t--){
        cout << "Case " << ++cn << ": ";
        solve();
    }

    // solve();
    
    return 0;
}