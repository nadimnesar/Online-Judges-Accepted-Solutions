/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll        long long int
#define pb        push_back
#define ins       insert
#define all(x)    x.begin(), x.end()
#define dot(x)    fixed << setprecision(x)
#define fastIO    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI        acos(-1.0) //3.1415926535897932
#define Log(b,x)  (log(x)/log(b))
#define eps       (int)(1e-9)
#define MAX       (int)(1e9+7)


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
        int n, m, k;
        cin >> n >> m >> k;

        int matrix[n][k];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                cin >> matrix[i][j];
            }
        }

        int p;
        cin >> p;
        vector < int > x(p);
        for(int i = 0; i < p; i++){
            cin >> x[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < k; j++){
                int temp = matrix[i][j];
                bool found = binary_search(all(x), abs(temp));
                if(temp > 0){
                    if(found) count++;
                }
                else{
                    if(!found) count++;
                }
            }
            if(count >= 1) ans++;
        }
        if(ans >= n) cout << "Case " << ++cn << ": " << "Yes" << endl;
        else cout << "Case " << ++cn << ": " << "No" << endl;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}