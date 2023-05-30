#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define pb                  push_back

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
    ll n, m, k;
    cin >> n >> m >> k;

    ll cnt = 0;
    ll equal = 0;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;

        if(temp > m) cnt++;
        if(temp == m) equal++;
    }

    if(cnt){
        if(cnt <= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else{
        if(k) cout << "YES" << endl;
        else{
            if(equal) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}