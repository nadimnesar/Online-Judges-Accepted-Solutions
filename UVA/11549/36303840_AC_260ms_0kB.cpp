#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

llu binpow(llu n, llu p){
    if(p == 0) return 1;
    llu res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}

unordered_map < llu, llu > um;

void solve(){
    llu t;
    cin >> t;

    while(t--){
        um.clear();

        llu k;
        cin >> k;

        llu n;
        cin >> n;

        um[n] = true;

        llu z = n;
        llu maxi = n;

again:
        string str = to_string(binpow(n, 2));
        str = str.substr(0, k);

        llu m = stoull(str);

        if(um[m]){
            cout << maxi << endl;
            continue;
        }

        um[m] = true;
        maxi = max(maxi, m);
        n = m;
        goto again;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}