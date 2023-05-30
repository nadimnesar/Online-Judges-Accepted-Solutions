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

ll BIGMOD(ll B, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll p1=(BIGMOD(B,P/2,M))%M;
        return (p1*p1)%M;
    }
    else{
        ll p1=B%M;
        ll p2=(BIGMOD(B,P-1,M))%M;
        return (p1*p2)%M;
    }
}

bool ifprime(ll n){
    if(n == 1) return false;
    else if(n == 2) return true;
    else if(n&1){
        for(ll i = 3; i*i <= n; i+=2){
            if(n%i == 0) return false;
        }
        return true;
    }
    else return false;
}


void solve() {
    ll p, a;
    while(cin >> p >> a and p and a){
        bool x = ifprime(p);
        if(!x){
            ll y = BIGMOD(a, p, p);
            if(y == a) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else cout << "no" << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    /*int t, cn = 0;
    cin >> t;
    while(t--){
        // cout << "Case #" << ++cn << ": ";
        solve();
    }*/

    solve();

    return 0;
}