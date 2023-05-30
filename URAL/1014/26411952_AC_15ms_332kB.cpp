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

    int n;
    cin >> n;
    vector < int > x;

    if(n == 1){
        cout << "1" << endl;
        return 0;
    }
    else if(n == 0){
        cout << "10" << endl;
        return 0;
    }

    for(int i = 9; i >= 2; i--){
        while(n%i == 0){
            n /= i;
            x.pb(i);
        }
    }
    if(n == 1){
        int len = x.size();
        for(int i = len-1; i >= 0; i--){
            cout << x[i];
        }
        cout << endl;
    }
    else cout << "-1" << endl;

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}