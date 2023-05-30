/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll        long long int
#define llu       long long unsigned int
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

int main() {
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    ll n;
    cin >> n;
    vector < ll > x(n);
    for(ll i = 0; i < n; i++){
        cin >> x[i];
    }
    sort(all(x));
    ll q;
    cin >> q;
    while(q--){
        ll temp;
        cin >> temp;

        auto upper = upper_bound(all(x), temp);
        auto lower = lower_bound(all(x), temp);

        if(lower - x.begin() == 0)  cout << 'X' << ' ';
        else cout << *--lower << ' ';
        
        if(upper - x.begin() == n) cout << 'X' << endl;
        else cout << *upper << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
}