#include "bits/stdc++.h"
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
    ll n;
    cin >> n;

    vector < ll > v;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        v.pb(temp);
    }

    sort(full(v));

    set < tuple <int, int, int> > st;
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            for(ll k = j+1; k < n; k++){

                ll a = v[i];
                ll b = v[j];
                ll c = v[k];

                double s = (a+b+c)/2.0;
                double area = sqrt(s*(s-a)*(s-b)*(s-c));

                if(area > eps) st.in({a, b, c});
            }
        }
    }

    cout << st.size() << endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--){
        cout << "Case #" << ++cn << ": ";
        nadimnesar();
    }

    return 0;
}