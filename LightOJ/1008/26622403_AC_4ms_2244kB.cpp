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

    ll t, cn = 0;
    cin >> t;
    while(t--){
        cout << "Case " << ++cn << ": ";
        ll s;
        cin >> s;
        ll sq = sqrt(s);
        ll sqfloor = floor((double)sqrt(s));
        ll sqceil = ceil((double)sqrt(s));
        ll sqnumber = (((sqfloor+1)*(sqfloor+1))+(sqfloor*sqfloor)+1)/2;
        if((double)sqrt(s) == (ll)sqrt(s)){
            if(s&1){
                cout << 1 << ' ' << (ll)sq << endl;
            }
            else cout << (ll)sq << ' ' << 1 << endl;
        }
        else if(sqnumber == s){
            cout << (ll)sqceil << ' ' << (ll)sqceil << endl;
        }
        else if((ll)s > (ll)sqnumber and (ll)s < (ll)(sqceil*sqceil)){
            ll temp = (ll)sqceil*sqceil;
            if(temp&1){
                cout << (ll)(temp-s)+1 << ' ' << (ll)sqrt(temp) << endl;
            }
            else cout << (ll)sqrt(temp) << ' ' << (ll)(temp-s)+1 << endl;
        }
        else{
            ll temp = (ll)(sqfloor*sqfloor);
            if(temp&1){
                cout << (ll)s-temp << ' ' << (ll)sqrt(temp)+1 << endl;
            }
            else cout << (ll)sqrt(temp)+1 << ' ' << (ll)s-temp << endl;
        }
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}