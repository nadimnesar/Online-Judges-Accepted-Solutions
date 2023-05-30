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
#define MOD              (int)(1e9+7)
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

ll get_power(ll n, ll p){
    int res = 0;
    int x = p;
    while (n / p){
        res += n / p;
        p *= x;
    }
    return res;
}

unordered_map < int , int > basefactor;
void solve(){
    int m, n; cin >> m >> n;
    basefactor.clear();
    int lagbe = 0;
    for(int i = 0; primes[i]*primes[i] <= m; i++){
        if(m%primes[i] == 0){
            int cnt = 0;
            while(m%primes[i] == 0){
                m /= primes[i];
                cnt++;
            }
            basefactor[primes[i]] = cnt;
            lagbe++;
        }
    }
    if(m > 1){
        basefactor[m] = 1;
        lagbe++;
    }
    int res = INT_MAX;
    bool notpossible = false;
    int total = 0;
    for(int i = 0; primes[i] <= n; i++){
        int cnt = get_power(n, primes[i]);
        if(basefactor[primes[i]]){
            if(cnt < basefactor[primes[i]]){
                notpossible = true;
                break;
            }
            res = min(res, cnt/basefactor[primes[i]]);
            total++;
        }
    }
    // debug(total);
    // debug(lagbe);

    if(total < lagbe) notpossible = true;
    if(notpossible) cout << "Impossible to divide" << endl;
    else cout << res << endl;
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    sieve();
    int t; cin >> t;
    int cn = 0;
    while(t--){
        // cout << "Case " << ++cn << ": ";
        cout << "Case " << ++cn << ':' << endl;
        solve();
    }

}