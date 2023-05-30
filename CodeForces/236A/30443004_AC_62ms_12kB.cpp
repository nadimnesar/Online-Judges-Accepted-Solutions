#include <bits/stdc++.h>
using namespace std;

#define ull              long long unsigned int
#define ll               long long int

#define bug              cout << "!!!!!!" << endl
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl

#define full(x)          x.begin(), x.end()
#define dot(x)           fixed << setprecision(x)
#define iremove(x, y)    x.erase(x.begin() + y)
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y))) //for sorted array

#define EPS              (1e-7)
#define MAX              (107)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

map < char, int > feq;

void solve(){
    string str;
    cin >> str;
    for(ll i = 0; str[i]; i++){
        feq[str[i]]++;
    }
    if((feq.size())&1){
        cout << "IGNORE HIM!" << endl;
    }
    else{
        cout << "CHAT WITH HER!" << endl;
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    solve();

    
}