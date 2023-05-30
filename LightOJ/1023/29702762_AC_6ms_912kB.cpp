//new
#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
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
 
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < string > ans;
void BT(string str, ll start){
    if(ans.size() == 30) return;
    if(start == str.size()){
        ans.pb(str);
        return;
    }
    for(ll i = start; str[i]; i++){
        swap(str[i], str[start]);
        BT(str, start+1);
        swap(str[i], str[start]);
    }
}


int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll t, casenum = 0;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        string str;
        for(ll i = 1; i <= n; i++) str += (char)(i+64);
        cout << "Case " << ++casenum << ":" << endl;
        BT(str, 0);
        sort(full(ans));
        if(n == 1){
            k = min((ll)1, k);
            for(ll i = 0; i < k; i++) cout << ans[i] << endl;
        }
        else if(n == 2){
            k = min((ll)2, k);
            for(ll i = 0; i < k; i++) cout << ans[i] << endl;
        }
        else if(n == 3){
            k = min((ll)6, k);
            for(ll i = 0; i < k; i++) cout << ans[i] << endl;
        }
        else if(n == 4){
            k = min((ll)24, k);
            for(ll i = 0; i < k; i++) cout << ans[i] << endl;
        }
        else{
            for(ll i = 0; i < k; i++) cout << ans[i] << endl;
        }
        ans.clear();
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}
