#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back

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
#define MAX              (2e7+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

vector < int > primes;
vector < bool > ifprime(MAX);

void sieve(){
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

ll get_power(ll n, ll p){
    ll freq = 0;
    while(n/p){
        freq += n/p;
        n /= p;
    }
    return freq;
}

llu BIGMOD(llu B, llu P, llu M){
    if(P==0) return 1;
    if(P%2==0){
        llu p1=(BIGMOD(B,P/2,M))%M;
        return (p1*p1)%M;
    }
    else{
        llu p1=B%M;
        llu p2=(BIGMOD(B,P-1,M))%M;
        return (p1*p2)%M;
    }
}

int fact(int n){
    if (n <= 1) return 1;
    return n * fact(n - 1);
}
 
int nPr(int n, int r){
    return fact(n) / fact(n - r);
}


void solve(){
    int n, m;
    int psize = primes.size();
    while(scanf("%d %d", &n, &m) != EOF){
        ll res = 1;
        if(n <= 5){
            res = nPr(n, m);
            while(res%10 == 0) res /= 10;
            printf("%lld\n", res%10);
            continue;
        }

        m = n-m;
        res = 1;
        ll for2;
        ll for5;

        for(ll i = 0; i < psize and primes[i] <= n; i++){
            ll x = get_power(n, primes[i]);

            if(primes[i] <= m){
                x -= get_power(m, primes[i]);
            }

            if(primes[i] == 2) for2 = x;
            else if(primes[i] == 5) for5 = x;
            else{
                if(!x) continue;
                ll p = BIGMOD(primes[i], x, 10);
                res = ((res%10) * (p%10))%10;
            }
        }

        int zeros = min(for2, for5);
        for2 -= zeros;
        for5 -= zeros;

        int p2 = BIGMOD(2, for2, 10);
        int p5 = BIGMOD(5, for5, 10);

        res = ((res%10) * (p2%10))%10;
        res = ((res%10) * (p5%10))%10;
        
        printf("%lld\n", res);
    }
}

int main(){

    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef NADIMNESAR
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    sieve();

    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
       solve();
    // }

#ifdef NADIMNESAR
    fprintf(stderr, "\n>> Runtime: %.3fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}