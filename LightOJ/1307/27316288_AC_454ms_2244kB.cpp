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

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    int t, cn = 0;
    cin >> t;
    while(t--){
        int n, a, b, c, low, high, triangles = 0, mid, res;
        cin >> n;
        vector < int > data;
        for(int i = 0; i < n; i++){
            int value;
            cin >> value;
            data.pb(value);
        }
        sort(full(data));
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                a = data[i]; b = data[j];
                low = j+1;
                high = n-1;
                res = -1;
                while(low <= high){
                    mid = low+(high-low)/2;
                    c = data[mid];
                    if(c < a+b){
                        res = mid;
                        low = mid + 1;
                    }
                    else high = mid - 1;
                }
                if(res != -1) triangles += res-j;
            }
        }
        cout << "Case " << ++cn << ": " << triangles << endl;
    }
 
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}