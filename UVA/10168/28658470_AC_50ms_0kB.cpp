#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair
#define pop              pop_back

#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MAX              (10000001)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < ll > primes;
vector < bool > ifprime(MAX);

void Sieve(){
    ifprime[0] = ifprime[1] = true;
    for(ll i = 4; i < MAX; i += 2) ifprime[i] = true;
    for(ll i = 3; i*i <= MAX; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j < MAX; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    for(ll i = 0; i < MAX; i++) if(!ifprime[i]) primes.pb(i);
}


int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    Sieve();
    ll n;
    while(cin >> n){
        if(n <= 7) cout << "Impossible." << endl;
        else{
            vector < ll > ans;
            ll limit, index;

Start:
            index = (lower_bound(full(primes), n) - primes.begin())-1;
            //debug(primes[index]);
            while(true){
                if(ans.size() == 0) limit = 6;
                else if(ans.size() == 1) limit = 4;
                else if(ans.size() == 2) limit = 2;
                else if(ans.size() == 3){
                    ans.pb(n);
                    break;
                }
                ll rest = n - primes[index];
                //debug(rest);
                if(rest < limit){
                    index--;
                    continue;
                }
                else if(rest == limit){
                    if(limit == 6){
                        ans.pb(primes[index]);
                        ans.pb(2);
                        ans.pb(2);
                        ans.pb(2);
                        break;
                    }
                    else if(limit == 4){
                        ans.pb(primes[index]);
                        ans.pb(2);
                        ans.pb(2);
                        break;
                    }
                    else{
                        ans.pb(primes[index]);
                        ans.pb(2);
                        break;
                    }
                }
                else{
                    ans.pb(primes[index]);
                    n -= primes[index];
                    goto Start;
                }
            }
            cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << endl; 
        }
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}