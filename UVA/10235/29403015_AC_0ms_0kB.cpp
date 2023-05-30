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
 
#define MAX              (1000007)
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
        if(str == "1"){
            cout << 1 << " is prime." << endl;
            continue;
        }
        ll num = 0;
        for(ll i = 0; str[i]; i++) num = (num*10) + (str[i]-48);
        if(primality_test(num)){
            reverse(full(str));
            ll revnum = 0;
            for(ll i = 0; str[i]; i++) revnum = (revnum*10) + (str[i]-48);
            if(primality_test(revnum) and revnum != num) cout << num << " is emirp." << endl;
            else cout << num << " is prime." << endl;
        }
        else cout << num << " is not prime." << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}