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

int main(){

    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    int cn  = 0;
    for(int i = 1; i <=d; i++){
        if(i%k == 0 || i%l== 0 || i%m == 0 || i%n == 0 ){
                cn++;
        }
    }
    cout << cn << endl;


    /*#ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif*/

}
