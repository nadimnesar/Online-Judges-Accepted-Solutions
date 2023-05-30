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

vector < ll > y;
vector < ll > x;

ll binarysearchX(ll q){
    ll right = x.size()-1;
    ll left = 0;
    ll index = -1;
    while(right >= left){
        ll mid = left + (right-left)/2;
        if (x[mid] == q){
            index = mid;
            right = mid -1;
        }
        else if(x[mid] > q) right = mid-1;
        else left = mid+1;
    }
    return index;
}

ll binarysearchY(ll q){
    ll right = y.size()-1;
    ll left = 0;
    ll index = -1;
    while(right >= left){
        ll mid = left + (right-left)/2;
        if (y[mid] == q){
            index = mid;
            right = mid -1;
        }
        else if(y[mid] > q) right = mid-1;
        else left = mid+1;
    }
    return index;
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    ll t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        ll res = 0;
        for(ll i = ((n/k)+1); i <= n; i++){ y.pb(i); res++; }
        for(ll i = 1; i < ((n/k)+1); i++){
            if(binarysearchX(i) == -1){
                if(binarysearchY(i*k) == -1){
                    x.pb(i*k);
                    res++;
                }
            }
        }
        cout << res << endl;
        x.clear();
        y.clear();
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}
