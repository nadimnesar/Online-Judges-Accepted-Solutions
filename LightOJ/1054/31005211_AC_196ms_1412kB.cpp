#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define For(x,y)         for(ll i = (int)x; i < (int)y; i++)
#define rFor(x,y)        for(ll i = (int)x; i => (int)y; i--)

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y))) //for sorted array

#define EPS              (1e-7)
#define MAX              (50007)
#define MOD              (1000000007)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

ll BIGMOD(ll B, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        llu p1=(BIGMOD(B,P/2,M))%M;
        return (p1*p1)%M;
    }
    else{
        ll p1=B%M;
        ll p2=(BIGMOD(B,P-1,M))%M;
        return (p1*p2)%M;
    }
}

vector < ll > primes;
vector < bool > ifprime(MAX);

void Sieve(){
    for(ll i = 3; i*i <= MAX; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j < MAX; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    primes.pb(2);
    for(ll i = 3; i < MAX; i+=2) if(!ifprime[i]) primes.pb(i);
}

void solve(){
    ll n, p;
    cin >> n >> p;
    if(n == MOD){
        cout << 1 << endl;
        return;
    }
    ll limit = sqrtl(n+1);
    ll sum = 1;
    for(ll i = 0; primes[i] <= limit; i++){
        if(n%primes[i] == 0){
            ll cnt = 0;
            while(n%primes[i] == 0){
                n /= primes[i];
                cnt++;
            }
            cnt = (cnt*p)+1;
            ll up = (BIGMOD(primes[i], cnt, MOD)-1)%MOD;
            ll down = BIGMOD(primes[i]-1, MOD-2, MOD);
            ll res = ((up%MOD)*(down%MOD))%MOD;

            sum = ((sum%MOD) * (res%MOD))%MOD;
        }
    }
    if(n > 1){
        ll up = (BIGMOD(n, p+1, MOD)-1)%MOD;
        ll down = BIGMOD(n-1, MOD-2, MOD);
        ll res = ((up%MOD)*(down%MOD))%MOD;
        sum = ((sum%MOD) * (res%MOD))%MOD;
    }
    cout << sum << endl;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef NADIMNESAR
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Sieve();
    int t; cin >> t;
    int cn = 0;
    while(t--){
        cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    }

#ifdef NADIMNESAR
    fprintf(stderr, "\n>> Runtime: %.3fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
