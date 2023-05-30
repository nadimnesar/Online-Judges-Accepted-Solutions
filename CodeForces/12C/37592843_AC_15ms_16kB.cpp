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

void solve() {
    ll n, m;
    cin >> n >> m;

    vector < ll > v1, v2;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        v1.pb(temp);
        v2.pb(temp);
    }

    sort(full(v1));
    sort(full(v2));
    reverse(full(v2));

    map < string , ll > mp;
    for(ll i = 0; i < m; i++){
        string str;
        cin >> str;
        mp[str]++;
    }

    vector < ll > x;
    for(auto it: mp){
        if(it.second > 0) x.pb(it.second);
    }

    sort(full(x));
    reverse(full(x));

    ll maxi = 0, mini = 0;
    ll idx1 = 0, idx2 = 0;

    for(ll i = 0; i < x.size(); i++){
        maxi += x[i] * v2[idx2++];
        mini += x[i] * v1[idx1++];
    }

    cout << mini << ' ' << maxi << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // int t, cn = 0;
    // cin >> t;
    // cin.ignore();
    // while (t--) {
    //     // cout << "Case " << ++cn << ": ";
    //     solve();
    // }
    solve();

    return 0;
}