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

ll BIGMOD(ll B, llu P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll p1=(BIGMOD(B,P/2,M))%M;
        return (p1*p1)%M;
    }
    else{
        ll p1=B%M;
        ll p2=(BIGMOD(B,P-1,M))%M;
        return (p1*p2)%M;
    }
}

void solve(){
    ll cn = 0;
    ll t;
    scanf("%lld", &t);
    while(t--){
        ll n, k;
        scanf("%lld %lld", &n, &k);

        string str = to_string(n);
        ll one = 0, zero = 0;

        for(ll i = 0; str[i]; i++){
            if(str[i] == '0') zero++;
            if(str[i] == '1') one++;
        }

        printf("Case %lld: ", ++cn);
        if(zero + one == str.size() and one == 1 and str[0] == '1'){
            printf("100 000\n");
            continue;
        }

        double z = (double)(log(10, n))*k;
        z -= int(z);

        printf("%03d %03d\n", int(pow(10, z)*100), BIGMOD(n, k, 1000));
    }
    
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}