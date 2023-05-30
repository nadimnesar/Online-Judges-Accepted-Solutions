#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e5+7)                           
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

ll n;
ll arr[maxx];
ll sTable[17][maxx];

void build_sTable(){
    ll limit = log(10, n)/log(10, 2);
    for(ll i = 0; i <= limit; i++){
        ll l = 1 << i;
        for(ll j = 0; j+l <= n; j++){
            if(l == 1) sTable[i][j] = arr[j];
            else sTable[i][j] = __gcd(sTable[i-1][j], sTable[i-1][j+ l/2]);
        }
    }
}

ll serarch_GCD(ll leftt, ll rightt){
    ll x = (rightt - leftt)+1;
    ll limit = log(10, x)/log(10, 2);
    ll l = 1 << limit;
    return __gcd(sTable[limit][leftt], sTable[limit][(rightt-l)+1]);
}

ll binary_search(ll start, ll lefter, ll righter, ll target){
    ll res = lefter;
    while(lefter <= righter){
        ll mid = lefter + (righter-lefter)/2;

        ll g = serarch_GCD(start, mid);

        if(g == target){
            res = mid;
            lefter = mid+1;
        }
        else righter = mid-1;
    }
    return res;
}

map < ll, ll > um;

void solve(){
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        um[arr[i]]++;
    }
    build_sTable();

    for(ll l = 0; l < n-1; l++){
        ll g = __gcd(arr[l], arr[l+1]);
        ll last = l;

        while(true){
            int idx = binary_search(l, last+1, n-1, g);

            um[g] += (idx - (last+1))+1;

            if(idx == n-1) break;

            g = serarch_GCD(l, idx+1);
            last = idx;
        }
    }

    ll q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        cout << um[x] << endl;
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}