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

double distance(double x1, double y1, double x2, double y2){
    double x = x2-x1;
    double y = y2-y1;
    return sqrt(x*x + y*y);
}


int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO;

    int n;
    double r;
    cin >> n >> r;
    double ans = 0, matrix[n][2];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < n-1; i++){
        ans += distance(matrix[i][0], matrix[i][1], matrix[i+1][0], matrix[i+1][1]);
    }
    ans += distance(matrix[n-1][0], matrix[n-1][1], matrix[0][0], matrix[0][1]);
    ans += 2.0*PI*r;

    cout << dot(2) << ans << endl;

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}