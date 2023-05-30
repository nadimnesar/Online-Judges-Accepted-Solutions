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
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

vector < ll > x, y;
vector < ll > xsum;
vector < ll > ysum;

void BT(ll idx, ll sum, char type, ll end){
    if(idx == end){
        if(type == 'x') xsum.pb(sum);
        if(type == 'y') ysum.pb(sum);
        return;
    }

    if(type == 'x'){
        BT(idx+1, sum, type, end);
        BT(idx+1, sum + x[idx], type, end);
        BT(idx+1, sum + x[idx] + x[idx], type, end);
    }

    if(type == 'y'){
        BT(idx+1, sum, type, end);
        BT(idx+1, sum + y[idx], type, end);
        BT(idx+1, sum + y[idx] + y[idx], type, end);
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;

    x.clear();
    y.clear();
    for(ll i = 0; i < n/2; i++){
        ll temp;
        cin >> temp;

        x.pb(temp);
    }

    for(ll i = n/2; i < n; i++){
        ll temp;
        cin >> temp;

        y.pb(temp);
    }

    xsum.clear();
    ysum.clear();

    BT(0, 0, 'x', x.size());
    BT(0, 0, 'y', y.size());

    sort(full(ysum));

    for(ll i = 0; i < xsum.size(); i++){
        if(xsum[i] <= k){
            if(binary_search(full(ysum), k-xsum[i])){
                cout << "Yes" << endl;
                return;
            }
        }
    }

    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--) {
        cout << "Case " << ++cn << ": ";
        solve();
    }
    // solve();

    return 0;
}