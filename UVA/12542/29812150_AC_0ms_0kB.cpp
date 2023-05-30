#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int 
#define ll               long long int
#define pop              pop_back
#define pb               push_back
#define mp               make_pair

#define full(x)          x.begin(), x.end()
#define iremove(x, y)    x.erase(x.begin() + y)
#define dot(x)           fixed << setprecision(x)
#define Clock            clock_t tStart = clock()
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(distance(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)

#define EPS              (1e-7)
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }

vector < bool > ifprime(MAX);
void sieve(){
    for(ll i = 3; i*i <= MAX; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j <= MAX; j += i+i){
                ifprime[j] = true;
            }
        }
    }
}

bool primality_test(ll n){
    if(n == 1) return false;
    else if(n == 2) return true;
    else if(n%2 == 0) return false;
    else if(!ifprime[n]) return true;
    else return false;
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    sieve();
    string str;
    while(cin >> str){
        if(str == "0") break;
        ll maxi = 0;
        for(ll i = 0; i < str.size(); i++){
            ll num = 0;
            for(ll j = i; j < str.size(); j++){
                num = (num*10) + (ll)(str[j]-48);
                if(num > 100000) break;
                if(num >= 2 and num <= 100000){
                    if(primality_test(num)){
                        maxi = max(num, maxi);
                    }
                }
            }
        }
        cout << maxi << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}