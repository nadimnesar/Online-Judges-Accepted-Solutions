#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define llu                 unsigned long long

#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)(10)
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void nadimnesar() {
    ll x1, y1;
    ll x4, y4;

    cin >> x1 >> y1;
    cin >> x4 >> y4;

    ll m;
    cin >> m;

    for(ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;

        bool flag = false;

        if(x >= x1 and x <= x4){
            if(y >= y1 and y <= y4){
                cout << "Yes" << endl;
                flag = true;
            }
        }

        if(!flag) cout  << "No" << endl;
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--){
        cout << "Case " << ++cn << ":" << endl;
        nadimnesar();
    }

    return 0;
}