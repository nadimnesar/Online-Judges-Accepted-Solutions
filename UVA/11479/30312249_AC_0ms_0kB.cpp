#include <bits/stdc++.h>
using namespace std;
 
#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back

#define bug              cout << "!***!" << endl
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z)  cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

#define full(x)          x.begin(), x.end()
#define dot(x)           fixed << setprecision(x)
#define iremove(x, y)    x.erase(x.begin() + y)
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define EPS              (1e-7)
#define MAX              (107)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

void solve(){
    double a, b, c; cin >> a >> b >> c;

    if((a+b) <= c or (a+c) <= b or (b+c) <= a){
        cout << "Invalid" << endl;
        return;
    }
    if(a == b and a == c and b == c){
        cout << "Equilateral" << endl;
        return;
    }
    if(a == b or a == c or b == c){
        cout << "Isosceles" << endl;
        return;
    }
    cout << "Scalene" << endl;
    return;
}

int main(){
    FastIO;
    ll case_number = 0;
    ll t; cin >> t;
    while(t--){
        cout << "Case " << ++case_number << ": ";
        solve();
    }
}