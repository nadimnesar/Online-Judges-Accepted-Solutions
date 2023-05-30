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
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }

ll fact[] = {1, 1, 2, 6, 24};

ll n, k;
vector < string > permutations;
string str;

void allpermutationss(ll start){
    if(permutations.size() == 30) return;
    if(start == n){
        permutations.pb(str);
        return;
    }
    for(ll i = start; i < n; i++){
        swap(str[i], str[start]);
        allpermutationss(start+1);
        swap(str[i], str[start]);
    }
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    ll t, cn = 0; cin >> t;
    while(t--){
        cin >> n >> k;
        for(ll i = 1; i <= n; i++) str += (char)(i+64);
        allpermutationss(0);
        sort(full(permutations));
        cout << "Case " << ++cn << ":" << endl;
        if(n < 5) k = min(fact[n], k);
        for(ll i = 0; i < k; i++) cout << permutations[i] << endl;
        permutations.clear();
        str.clear();
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}