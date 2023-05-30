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

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll m = n*6;

    if(a*b >= m){
        cout << a*b << endl;
        cout << a << ' ' << b << endl;
        return;
    }

    bool flag = false;
again:
    ll x, y;
    for(ll i = a; i*i <= m; i++){
        if(m%i == 0){
            if(m/i >= b){
                x = i;
                y = m/i;
                flag = true;
                break;
            }
        }
    }

    if(!flag){
        for(ll i = b; i*i <= m; i++){
            if(m%i == 0){
                if(m/i >= a){
                    y = i;
                    x = m/i;
                    flag = true;
                    break;
                }
            }
        }
    }

    if(flag == false){
        m++;
        goto again;
    }

    cout << x*y << endl;
    cout << x << ' ' << y << endl;
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   /* int t, cn = 0;
    cin >> t;
    while (t--) {
        // cout << "Case #" << ++cn << ": ";
        solve();
    }*/

    solve();

    return 0;
}