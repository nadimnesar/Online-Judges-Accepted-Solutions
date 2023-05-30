/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll        long long
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

int div(int n){
    int sq = sqrt(n);
    vector < int > y;
    for(int i = 1; i <= sq; i++){
        if(n%i == 0){
            y.pb(i);
            if(i*i != n) y.pb(n/i);
        }
    }
    return y.size();
}


bool compare(int a, int b){
    int x = div(a);
    int y = div(b);
    if(x < y) return true;
    else if(x == y and a > b) return true;
    else return false;
}


int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO;

    vector < int > x(1000);
    int it = 1;
    for(int i = 0; i < 1000; i++){
        x[i] = it;
        it++;
    }
    
    sort(all(x), compare);

    int t, cn = 0;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << "Case " << ++cn << ": ";
        cout << x[n-1] << endl;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}