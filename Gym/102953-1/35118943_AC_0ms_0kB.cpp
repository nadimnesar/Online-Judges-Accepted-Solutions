#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e3+7)                           
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

unordered_map < char, ll > um;

void solve(){
    ll n;
    cin >> n;
    string str;
    cin >> str;

    for(ll i = 0; str[i]; i++){
        um[str[i]]++;
    }
    ll res = INT_MAX;

    res = min(res, um['c']);
    res = min(res, um['o']);
    res = min(res, um['d']);
    res = min(res, um['e']);
    res = min(res, um['r']);
    res = min(res, um['a']);
    res = min(res, um['m']);
    res = min(res, um['s']);

    cout << res << endl;
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}
