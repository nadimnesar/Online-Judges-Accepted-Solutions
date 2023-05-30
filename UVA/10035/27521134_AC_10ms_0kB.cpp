#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define ist              insert
#define mp               make_pair
#define pop              pop_back
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

ll carryoparations;

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    string a, b;
    while(cin >> a >> b){
        if(a == "0" and b == "0") break;
        reverse(full(a));
        reverse(full(b));
        if(a.size() < b.size()) swap(a, b);
        while(b.size() < a.size()) b.pb('0');
        llu i = 0, carry = 0;
        while(a[i]){
            if(carry > 0) carryoparations++;
            carry = carry + a[i]-48 + b[i]-48;
            carry = carry / 10;
            i++;
        }
        while(carry > 9){
            if(carry > 0) carryoparations++;
            carry = carry / 10;
        }
        if(carry > 0) carryoparations++;

        if(carryoparations == 0) cout << "No carry operation." << endl;
        else if(carryoparations == 1) cout << "1 carry operation." << endl;
        else cout << carryoparations << " carry operations." << endl;
        carryoparations = 0;
    }
    
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
