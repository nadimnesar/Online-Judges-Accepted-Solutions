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

typedef struct node {
    int sp = -1;
    int cost = 0;
} node;

void nadimnesar() {
    ll n;
    cin >> n;

    vector < ll > v;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        v.pb(temp);
    }

    int sup[n];
    memset(sup, 0);

    node emp[n];

    ll m;
    cin >> m;

    while(m--){
        ll e, s, c;
        cin >> s >> e >> c;
        e--; s--;

        if(v[e] < v[s]){
            if(emp[e].sp == -1){
                emp[e].cost = c;
                emp[e].sp = s;
                sup[s]++;
            }
            else{
                if(c == emp[e].cost){
                    if(sup[emp[e].sp] > sup[s]){
                        sup[emp[e].sp]--;
                        sup[s]++;
                        emp[e].sp = s;
                    }
                }
                else if(c < emp[e].cost){
                    sup[emp[e].sp]--;
                    sup[s]++;
                    emp[e].sp = s;
                    emp[e].cost = c;
                }
            }
        }
    }

    ll cnt = 0;
    ll res = 0;
    for(ll i = 0; i < n; i++){
        res += emp[i].cost;
        if(emp[i].sp == -1) cnt++;
    }

    if(cnt == 1) cout << res << endl;
    else cout << "-1" << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    // int t, cn = 0;
    // cin >> t;
    // while (t--) {
        // cout << "Case #" << ++cn << ": ";
        nadimnesar();
    // }

    return 0;
}