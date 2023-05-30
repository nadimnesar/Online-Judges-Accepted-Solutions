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
 
#define MAX              (10000001)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

ll BtoD(string n){
    string num = n;
    ll dec_value = 0;
    ll base = 1;
    ll len = num.length();
    for (ll i = len-1; i >= 0; i--){
        if (num[i] == '1') dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll t, cn = 0;
    cin >> t;
    cin.ignore();
    while(t--){
        string n1, n2;
        cin >> n1;
        cin >> n2;
        ll num1 = BtoD(n1);
        ll num2 = BtoD(n2);
        if(gcd(num1, num2) == 1) cout << "Pair #" << ++cn << ": Love is not all you need!" << endl;
        else cout << "Pair #" << ++cn << ": All you need is love!" << endl;
    }
 
#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}