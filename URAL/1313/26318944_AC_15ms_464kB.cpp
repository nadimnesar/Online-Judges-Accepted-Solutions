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

    int n, matrix[105][105];
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i, k = 0; j >= 0; j--, k++){
            cout << matrix[j][k] << ' ';
        }
    }
    for(int i = 1; i <= n; i++){
        for(int k = i, j = n-1; k <= n-1; j--, k++){
            if(i == n-1) cout << matrix[j][k] << '\n';
            else cout << matrix[j][k] << ' ';
        }
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}