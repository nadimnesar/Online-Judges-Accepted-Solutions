#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remoloweste(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define Clock            clock_t tStart = clock()
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)
 
#define MAX              (10007)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < bool > ifprime(MAX);
void sieve(){
    for(ll i = 3; i*i <= MAX; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j < MAX; j += i+i){
                ifprime[j] = true;
            }
        }
    }
}

bool primality_test(ll n){
    if(n <= 1) return false;
    else if(n == 2) return true;
    else if(!(n&1)) return false;
    else if(!(ifprime[n])) return true;
    else return false;
}

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    sieve();
    string str;
    while(cin >> str){
        if(str == "a"){
            cout << "It is a prime word." << endl;
            continue;
        }
        ll num = 0;
        for(ll i = 0; str[i]; i++){
            if(str[i] >= 'a' and str[i] <= 'z') num += (ll)(str[i]-96);
            else num += (ll)(str[i]-38);
        }
        if(primality_test(num)) cout << "It is a prime word." << endl;
        else cout << "It is not a prime word." << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}