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

    int q;
    cin >> q;
    while(q--){
        ll unsigned int n, cn = 0;
        cin >> n;
        while(1){
            if(n == 1) break;
            else if(n%2 == 0){
                n /= 2;
                cn++;
            }
            else if(n%3 == 0){
                n *= 2;
                n /= 3;
                cn++;
            }
            else if(n%5 == 0){
                n *= 4;
                n /= 5;
                cn++;
            }
            else break;
        }
        if(n == 1) cout << cn << endl;
        else cout << "-1" << endl;
    }


    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}