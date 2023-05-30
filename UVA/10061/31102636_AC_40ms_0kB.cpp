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
#define MAX              (1e4+7)
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

int factorialPrimePower(int n, int p){
    int freq = 0;
    int cur = p;
    while (n/cur){
        freq += n/cur;
        cur *= p;
    }
    return freq;
}

unordered_map < int, int > base;

void solve(){
    int n, b;
    while(cin >> n >> b){
        base.clear();

        int x = b;
        for(int i = 0; primes[i]*primes[i]; i++){
            if(x%primes[i] == 0){
                int cnt = 0;
                while(x%primes[i] == 0){
                    cnt++;
                    x /= primes[i];
                }
                base[primes[i]] = cnt;
            }
        }
        if(x > 1) base[x]++;
        int zero = INT_MAX;
        for(auto it: base){
            int res = factorialPrimePower(n, it.first);
            if(res == 0 or res/it.second == 0){
                zero = 0;
                break;
            }
            else zero = min(zero, res/it.second);
        }
        double digits = 0;
        for(int i = 1; i <= n; i++){
            digits += LOG(b, i);
        }

        cout << zero << ' ' << int(floor(digits)+1) << endl;
    }
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    sieve();
    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }

}