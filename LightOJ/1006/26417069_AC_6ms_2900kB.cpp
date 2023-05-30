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
#define MOD       10000007

int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO;

    ll unsigned int caseno = 0, cases;
    cin >> cases;
    while(cases--){
        ll unsigned int a, b, c, d, e, f, n;
        cin >> a >> b >> c >> d >> e >> f >> n;
        ll unsigned int x[100001];
        x[0] = a%MOD;
        x[1] = b%MOD;
        x[2] = c%MOD;
        x[3] = d%MOD;
        x[4] = e%MOD;
        x[5] = f%MOD;
        for(ll unsigned int i = 6; i <= n; i++){
            x[i] = (x[i-1] + x[i-2] + x[i-3] + x[i-4] + x[i-5] + x[i-6])%MOD;
        }

        cout << "Case " << ++caseno << ": " << x[n] << endl;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}