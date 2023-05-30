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

ll triangles[maxx];

void solve(){

    triangles[0] = 0;
    triangles[1] = 0;

    ll i = 0;
    ll cnt = 0;

    ll j = 2;
    while(j < maxx){
        if(cnt == 2){
            cnt = 0;
            i++;
            continue;
        }

        triangles[j] = (2*triangles[j-1]) - triangles[j-2] + i;
        j++;
        cnt++;
    }

    ll n;
    while(cin >> n){
        if(n < 3) break;
        cout << triangles[n] << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}