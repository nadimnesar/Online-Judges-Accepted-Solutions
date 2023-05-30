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

    ll t, cn = 0;
    cin >> t;
    cin.ignore();
    while(t--){
        cout << "Case " << ++cn << ": ";
        char ch;
        string m1, m2;
        ll d1, d2, y1, y2, ans = 0;
        cin >> m1 >> d1 >> ch >> y1;
        cin >> m2 >> d2 >> ch >> y2;

        if(m1 == "March" or m1 == "April" or m1 == "May" or m1 == "June" or m1 == "July" or m1 == "August" or m1 == "September" or m1 == "October" or m1 == "November" or m1 == "December"){
            y1++;
        }
        if(m2 == "January"){
            y2--;
        }
        if(m2 == "February" and d2 != 29){
            y2--;
        }

        ans =  (y2/4 - (y1-1)/4) - (y2/100 - (y1-1)/100) + (y2/400 - (y1-1)/400);
        cout << ans << endl;
        //cout << y1 << ' ' << y2 << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
}