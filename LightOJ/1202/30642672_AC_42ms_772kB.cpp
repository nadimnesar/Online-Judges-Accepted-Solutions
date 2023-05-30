/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll        long long
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define dot(x)    fixed << setprecision(x)
#define eps       1e-9
#define MAX       100000
#define PI        acos(-1.0) //3.1415926535897932
#define fastIO    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO;

    ll int t, cn = 0;
    cin >> t;
    while(t--){
        ll int r1, c1, r2, c2, a, b;
        cin >> r1 >> c1 >> r2 >> c2;

        a = abs(r1-r2);
        b = abs(c1-c2);

        cout << "Case " << ++cn << ": ";
        if(a == b) cout << "1" << endl;
        else if((a%2 == 0) && (b%2 == 0)) cout << "2" << endl;
        else if((a%2 != 0) && (b%2 != 0)) cout << "2" << endl;
        else cout << "impossible" << endl;

    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}