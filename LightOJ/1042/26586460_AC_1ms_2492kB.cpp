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

llu binarytodecimal(vector < llu > nn){
    llu ans = 0;
    llu nnlen = nn.size();
    llu j = nnlen-1;
    for(llu i = 0; i < nnlen; i++){
        ans += nn[i]*pow(2, j);
        j--;
    }
    return ans;
}

int main() {
    
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    llu t, cn = 0;
    cin >> t;
    while(t--){
        cout << "Case " << ++cn << ": ";
        llu n, m, ans;
        cin >> n;
        m = n;
        vector < llu > x, y;
        while(m > 0){
            x.pb(m%2);
            m /= 2;
        }
        reverse(all(x));
        y = x;
        while(y[y.size()-1] == 0){
            iremove(y, y.size()-1);
        }
        llu ybit = 0;
        llu ylen = y.size();
        llu xlen = x.size();
        for(int i = 0; i < ylen; i++){
            if(y[i] == 1) ybit++;
        }
        if(ybit == ylen){
            vector < llu > z;
            z.pb(1);
            llu zero = (xlen - ybit)+1;
            while(zero--){
                z.pb(0);
            }
            while(z.size() != (xlen+1)){
                z.pb(1);
            }
            ans = binarytodecimal(z);
            cout << ans << endl;
            continue;
        }
        next_permutation(all(x));
        ans = binarytodecimal(x);
        cout << ans << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}