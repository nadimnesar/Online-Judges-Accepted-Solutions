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
#define MAX              (100000007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }

int main(){
 
    FastIO;

    ll t; cin >> t; 
    while(t--){
        ll n; cin >> n;
        vector < string > left;
        vector < string > right;
        for(ll i = 0; i < n; i++){
            string temp; cin >> temp;
            left.pb(temp);
        }
        for(ll i = 0; i < n; i++){
            string temp; cin >> temp;
            right.pb(temp);
        }
        vector < ll > ans;
        ll res = 0;
        set < string > s1, s2;
        for(ll i = 0; i < n; i++){
            res++;
            s1.insert(left[i]);
            s2.insert(right[i]);
            if(s1 == s2){
                ans.pb(res);
                res = 0;
                s1.clear(); s2.clear();
            }
        }
        for(ll i = 0; i < ans.size(); i++){
            if(i+1 == ans.size()) cout << ans[i] << endl;
            else cout << ans[i] << ' ';
        }
    }




}