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

ll two[maxx];
ll five[maxx];

void solve(){
    
    ll t = 0;
    ll f = 0;
    for(ll i = 1; i < maxx; i++){

        ll m = i;
        while(m%2 == 0){
            m /= 2;
            t++;
        }

        while(m%5 == 0){
            m /= 5;
            f++;
        }

        two[i] = t;
        five[i] = f;
    }

    ll cn = 0;
    ll tc;
    scanf("%lld", &tc);
    while(tc--){
        ll n, r, p , q;
        scanf("%lld %lld %lld %lld", &n, &r, &p, &q);


        ll p_t = 0;
        ll p_f = 0;

        while(p%2 == 0){
            p /= 2;
            p_t++;
        }

        while(p%5 == 0){
            p /= 5;
            p_f++;
        }

        p_t *= q;
        p_f *= q;

        ll up_t = two[n]+p_t;
        ll up_f = five[n]+p_f;

        ll down_t = two[r]+two[n-r];
        ll down_f = five[r]+five[n-r];

        up_t -= down_t;
        up_f -= down_f;

        printf("Case %lld: %lld\n", ++cn, min(up_t, up_f));
    }
    
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}