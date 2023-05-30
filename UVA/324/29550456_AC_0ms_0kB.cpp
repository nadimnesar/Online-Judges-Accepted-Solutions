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
 
#define MAX              (3037000499)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < string > factorial(367);

class BIG_INT{
private:
    string result;
public:
    string multiplication(string a, ll b){
        result.clear();
        ll m = 0;
        reverse(full(a));
        for(ll i = 0; a[i] ; i++){
            m = m + b * (a[i]-'0');
            result.pb((m%10)+48);
            m /= 10;
        }
        while(m > 0){
            result.pb((m%10) + 48);
            m /= 10;
        }
        reverse(full(result));
        while(result[0] == '0' and result.size() > 1) iremove(result, 0);
        return result;
    }
};

void solve(){
    BIG_INT Int;
    factorial[0] = "1";
    for(ll i = 1; i <= 366; i++){
        factorial[i] = Int.multiplication(factorial[i-1], i);
    }
}

ll countDigit(ll n){
    if(n < 10) return 1;
    return floor(log10(n)+1); 
}

int main(){

#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    solve();
    ll f;
    while(cin >> f and f){
        vector < ll > feq(10, 0);
        for(ll i = 0; factorial[f][i]; i++){
            feq[factorial[f][i]-48]++;
        }
        cout << f << "! --" << endl;
        for(ll i = 0; i < 5; i++){
            if(i == 0) cout << "   (" << i << ")";
            else cout << "    (" << i << ")";
            ll space = abs(5-countDigit(feq[i]));
            while(space--) cout << ' ';
            cout << feq[i];
        }
        cout << endl;
        for(ll i = 5; i < 10; i++){
            if(i == 5) cout << "   (" << i << ")";
            else cout << "    (" << i << ")";
            ll space = abs(5-countDigit(feq[i]));
            while(space--) cout << ' ';
            cout << feq[i];
        }
        cout << endl;
    }
    
    
#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}