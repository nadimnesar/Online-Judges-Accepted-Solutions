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
    string str; cin >> str;
    string copy = str;
    reverse(full(copy));
    if(str == copy){
        bool ok = true;
        for(ll i = 0; str[i]; i++){
            if(str[i] == 'A') continue;
            if(str[i] == 'H') continue;
            if(str[i] == 'I') continue;
            if(str[i] == 'M') continue;
            if(str[i] == 'O') continue;
            if(str[i] == 'T') continue;
            if(str[i] == 'U') continue;
            if(str[i] == 'V') continue;
            if(str[i] == 'W') continue;
            if(str[i] == 'X') continue;
            if(str[i] == 'Y') continue;
            ok = false;
            break;
        }
        if(ok) cout << "yes" << endl;
        else  cout << "no" << endl;
    }
    else cout << "no" << endl;
}

int main(){

    FastIO;
    // ll c_n = 0;
    ll t; cin >> t;
    while(t--){
    //     cout << "Case " << ++c_n << ": ";
        //cout << "Case " << ++c_n << ":" << endl;
        solve();
    }
}