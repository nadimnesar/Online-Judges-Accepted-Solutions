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
#define maxx                (ll)(5e5+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

ll n, k;
ll leftt, rightt;
ll arr[maxx];
ll sTable[20][maxx];

void build_sTable(){
    ll limit = log(10, n)/log(10, 2);
    for(ll i = 0; i <= limit; i++){
        ll l = 1 << i;
        for(ll j = 0; j+l <= n; j++){
            if(l == 1) sTable[i][j] = arr[j];
            else sTable[i][j] = gcd(sTable[i-1][j], sTable[i-1][j+ l/2]);
        }
    }
}

ll serarch_GCD(){
    ll x = (rightt - leftt)+1;
    ll limit = log(10, x)/log(10, 2);
    ll l = 1 << limit;
    return gcd(sTable[limit][leftt], sTable[limit][(rightt-l)+1]);
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build_sTable();

    ll res = 0;

    for(ll i = 0; i < n; i++){

        ll r = n-1;
        ll l = i+1;
        ll index = -1;
        while(r >= l){
            ll mid = l + (r-l)/2;

            leftt = i;
            rightt = mid;

            if (serarch_GCD() >= k){
                index = mid;
                l = mid+1;
            }
            else r = mid-1;
        }

        ll ans;

        if(index == -1) ans = 0;
        else ans = (index - i)+1;

        res = max(res,  ans);
    }
 
    cout << res << endl;
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}