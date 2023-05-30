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
 
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

int main(){

    fastIO;
 
    ll n;
    cin >> n;
    vector < ll > heights(n);
    for(ll i = 0; i < n; i++) cin >> heights[i];
    sort(full(heights));
    ll q;
    cin >> q;
    for(ll i = 0; i < q; i++){
        ll luchu;
        cin >> luchu;
        auto up = upper_bound(full(heights), luchu);
        auto low = lower_bound(full(heights), luchu);
        if((low - heights.begin()) == 0)  cout << 'X' << ' ';
        else{
            low--;
            cout << *low << ' ';
        }
        if((up - heights.begin()) == n) cout << 'X' << endl;
        else cout << *up << endl;
    }
 
}