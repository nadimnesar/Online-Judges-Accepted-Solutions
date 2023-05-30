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

class BIG_INT{
private:
    string result;
public:
    string add(string a, string b){
        result.clear();
        reverse(full(a));
        reverse(full(b));
        if(a.size() < b.size()) swap(a, b);
        while(b.size() < a.size()) b.pb('0');
        llu i = 0, carry = 0;
        while(a[i]){
            carry = carry + a[i]-48 + b[i]-48;
            result.pb((carry %10) + 48);
            carry = carry / 10;
            i++;
        }
        while(carry > 9){
            result.pb((carry % 10) + 48);
            carry = carry / 10;
        }
        if(carry != 0) result.pb(carry + 48);
        reverse(full(result));
        return result;
    }
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

#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    BIG_INT Int;
    ll n, a;
    while(cin >> n >> a){
        string result = "0";
        for(ll i = 1; i <= n; i++){
            string temp = to_string(a);
            for(ll j = 1; j < i; j++) temp = Int.multiplication(temp, a);
            result = Int.add(result, Int.multiplication(temp, i));
        }
        cout << result << endl;
    }
    
#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}
