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

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    BIG_INT Int;
    ll n, m;
    while(cin >> n >> m){
        if(n == 0 and m == 0) break;
        string res = "1";
        for(ll i = 0; i < m; i++){
            res = Int.multiplication(res, n);
        }
        cout << res << endl;
    }
 
#ifndef ONLINE_JUDGE
    Runtime;
#endif

}