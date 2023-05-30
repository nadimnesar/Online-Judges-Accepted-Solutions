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
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock(); freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string temp;
        vector < string > nums;
        for(ll i = 0; i < n; i++){
            cin >> temp;
            nums.pb(temp);
        }
        sort(full(nums));
        bool ans = true;
        for(ll i = 0; i < n-1; i++){
            bool found = true;
            for(ll j = 0; j < nums[i].size(); j++){
                if(nums[i][j] != nums[i+1][j]) found = false;
            }
            if(found){ ans = false; break; }
        }
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}