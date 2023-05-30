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
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define EPS              (1e-7)
#define MAX              (5e2+7)
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

llu binpow(llu n, llu p){
    if(p == 0) return 1;
    llu res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}

void solve(){
    ll n;
    while(cin >> n and n){
        int m = n;
        ll sum = 1;
        for(int i = 0; primes[i]*primes[i] <= n; i++){
            if(n%primes[i] == 0){
                int cnt = 1;
                while(n%primes[i] == 0){
                    n /= primes[i];
                    cnt++;
                }
                sum *= (binpow(primes[i], cnt)-1)/(primes[i]-1);
            }
        }
        if(n > 1) sum *= (binpow(n, 2)-1)/(n-1);
        sum -= m;

        // debug(sum);

        string str;
        str = to_string(m);
        int ssize = str.size();
        while(ssize < 5){
            cout << ' ';
            ssize++;
        }
        cout << m << "  ";

        if(sum == m) cout << "PERFECT" << endl;
        else if(sum < m) cout << "DEFICIENT" << endl;
        else cout << "ABUNDANT" << endl;
    }
}

int main(){
    
    FastIO;
    sieve();

    cout << "PERFECTION OUTPUT" << endl;
    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }
    cout << "END OF OUTPUT" << endl;
}