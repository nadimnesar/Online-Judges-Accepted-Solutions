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

    int t, cn = 0;
    cin >> t;
    while(t--){
        int r;
        cin >> r;
        map < int, int > mp;
        while(r--){
            int time, position;
            cin >> time >> position;
            mp.inst({time, position});
        }
        double maxi = 0;
        for(auto it = mp.begin(); it != --mp.end(); it++){
            double t = abs(((++it)->first) - ((--it)->first));
            double s = abs(((++it)->second) - ((--it)->second));
            maxi = max(maxi, double(s/t));
        }
        cout << "Case #" << ++cn << ": ";
        cout << dot(2) << maxi << endl;
        mp.clear();
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
