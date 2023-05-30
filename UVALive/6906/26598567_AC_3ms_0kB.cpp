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
#define Log(b, x)        (log(x)/log(b))

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    llu t, cn = 0;
    cin >> t;
    while(t--){
        cout << "Case #" << ++cn << ": ";
        llu n, k, ans = 0;
        cin >> n >> k;
        vector < int > x(n);
        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
        sort(all(x));
        while(1){
            if(x.size() == 0) break;
            int temp = x[0];
            for(int i = 0; i < x.size(); i++){
                if((x[i] - temp) <= k){
                    temp = x[i];
                    x[i] = -1;
                }
            }
            remove(x, -1);
            ans++;
        }
        cout << ans << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}