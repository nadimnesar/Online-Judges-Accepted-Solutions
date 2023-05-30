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

ll sum = 0, ans;

void allsubsets(vector < ll > set, vector < ll > sub, int n, int index){
    if(sub.size() == n){
        ll pile1 = 0;
        for(ll i = 0; i < n; i++){
            if(sub[i] == -1) continue;
            pile1 += sub[i];
        }
        ll pile2 = sum - pile1;
        ans = min(ans, abs(pile1 - pile2));
        return;
    }
    sub.pb(set[index]);
    allsubsets(set, sub, n, index+1);
    sub.pop();
    sub.pb(-1);
    allsubsets(set, sub, n, index+1);
}

int main(){
 
    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    ll n;
    cin >> n;
    vector < ll > set;
    for(ll i = 0; i < n; i++){
        ll value;
        cin >> value;
        set.pb(value);
        sum += value;
    }
    ans = sum;
    vector < ll > sub;
    allsubsets(set, sub, n, 0);
    cout << ans << endl;

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
