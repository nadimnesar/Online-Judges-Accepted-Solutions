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

int main() {
    
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    int n, total = 0, pile1, pile2, diff;
    cin >> n;
    vector < int > x;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        total += temp;
        x.pb(temp);
    }
    int result = total;
    for(int mask = 0; mask < (1 << n); mask++){
        pile1 = 0;
        for(int i = 0; i < n; i++){
            if(mask&(1 << i)){
                pile1 += x[i];
            }
        }
        pile2 = total - pile1;
        diff = abs(pile1 - pile2);
        result = min(result, diff);
    }

    cout << result << endl;


    
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}