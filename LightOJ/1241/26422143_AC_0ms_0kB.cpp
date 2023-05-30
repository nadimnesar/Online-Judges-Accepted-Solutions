/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll        long long
#define pb        push_back
#define ins       insert
#define all(x)    x.begin(), x.end()
#define dot(x)    fixed << setprecision(x)
#define fastIO    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI        acos(-1.0) //3.1415926535897932
#define Log(b,x)  (log(x)/log(b))
#define eps       (int)(1e-9)
#define MAX       (int)(1e9+1)
#define MOD       (int)(1e7+1)

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
        int n, ans = 0;
        cin >> n;
        vector < int > x(n);
        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
        cout << "Case " << ++cn << ": ";
        for(int i = 1; i < n; i++){
            int dis = x[i]-x[i-1];
            if(dis == 0) continue;
again:
            if(dis >= 1 && dis <= 5){
                ans++;
            }
            else{
                dis -= 5;
                ans++;
                goto again;
            }
        }
        if(x[0] != 2){
            int dis = x[0] - 2;
last:
            if(dis >= 1 && dis <= 5){
                ans++;
            }
            else{
                dis -= 5;
                ans++;
                goto last;
            }
        }
        cout << ans << endl;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}