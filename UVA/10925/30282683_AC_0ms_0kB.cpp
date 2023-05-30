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

#define bug              cout << "!!!!" << endl
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define debug3(x, y, z)  cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

#define EPS              (1e-7)
#define MAX              (107)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

ll Digit(ll n){
    ll i = 0;
    for(; n > 0; i++) n /= 10;
    return i;
}

string add(string a, string b){
    string result;
    reverse(full(a)); reverse(full(b));
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

string division(string a, ll b){
    string c;
    ll Len = a.length(), mod = 0, d = Digit(b), V = 0, i = 0;
    while(i < d || V < b){
        V = (V * 10) + (a[i]-48);
        i++;
    }
    while(i < Len+1){
        c.push_back((V/b)+48);
        mod = V % b;
        V = (mod*10) + (a[i]-48);
        if(b > V){
            i++;
            V = (V*10) + (a[i]-48);
            if(i!=Len+1) c.push_back('0');
        }
        i++;
    }
    if(c.empty()) c = "0";
    return c;
}

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock(); freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    bool br = false;
    ll cn = 0, n, d;
    while(cin >> n >> d and n and d){
        string temp, res = "0";
        for(ll i = 0; i < n; i++){
            cin >> temp;
            res = add(res, temp);
        }
        string ans = division(res, d);
        cout << "Bill #" << ++cn << " costs ";
        cout << res << ": each friend should pay " << ans << endl << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}