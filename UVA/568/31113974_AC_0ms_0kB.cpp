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

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y)))    

#define EPS              (1e-7)
#define MAX              (1e5+7)
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
    for(int i = 3; i < MAX; i+=2) if(!ifprime[i]) primes.pb(i);
}

int magic(int n, int p){
    int freq = 0;
    int cur = p;
    while (n/cur){
        freq += n/cur;
        cur *= p;
    }
    return freq;
}

ll BIGMOD(ll B, ll P, ll M){
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
    int n;
    while(~scanf("%d", &n)){

        int res = 1;

        int for2 = magic(n, 2), for5 = magic(n, 5);

        int zeros = min(for2, for5);
        for2 -= zeros;
        for5 -= zeros;

        res = ((res%10) * BIGMOD(2, for2, 10))%10;
        res = ((res%10) * BIGMOD(5, for5, 10))%10;

        for(int i = 0; primes[i] <= n; i++){
            if(primes[i] == 2) continue;
            else if(primes[i] == 5) continue;
            else{
                int cnt = magic(n, primes[i]);
                res = ((res%10) * BIGMOD(primes[i], cnt, 10))%10;
            }
        }

        printf("%5d -> %d\n", n, res);
    }
}

int main(){
    
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    sieve();
    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }

}
