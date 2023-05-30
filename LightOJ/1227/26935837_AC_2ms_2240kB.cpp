/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;

#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
 
#define all(x)           x.begin(), x.end()
#define dot(x)           fixed << setprecision(x)
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
 
#define PI               acos(-1.0) //3.1415926535897932
#define LOG(b, x)        (log(x)/log(b))
#define EPS              (1e-7)

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    int t, cn = 0;
    cin >> t;
    while(t--){
        int n, p, q;
        cin >> n >> p >> q;
        vector < int > x(n);
        for(int i = 0; i < n; i++){
            cin >> x[i];
        }

        int weight = 0, ans = 0;
        for(int i = 0; i < n; i++){
            if(((weight+x[i]) <= q) and ((ans+1) <= p)){
                weight += x[i];
                ans++;
            }
        }
        cout << "Case " << ++cn << ": ";
        cout << ans << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}