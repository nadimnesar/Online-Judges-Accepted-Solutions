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
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

unordered_map < string, ll > um;

void solve(){

    string str;
    cin >> str;

    ll n = str.size();

    for (ll i = 0; i < n; i++){
        for (ll j = 1; j <= n - i; j++){
            um[str.substr(i, j)]++;
        }
    }

    ll maxi = 0;
    for(auto it: um){
        if(it.second >= 2){
            maxi = max(maxi, (ll)(it.first).size());
        }
    }

    cout << maxi << endl;

    um.clear();
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}