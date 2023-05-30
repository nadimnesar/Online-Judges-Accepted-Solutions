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
 
int n, cow;
vector < int > x;
 
bool process(int z){
    int counter = 1;
    int p = 0;
    for(int i = 1; i < n; i++){
        if(abs(x[i]-x[p]) >= z){
            p = i;
            counter++;
        }
    }
    if(counter >= cow) return true;
    else return false;
}
 
 
int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO;
 
    int t;
    cin >> t;
    while(t--){
        cin >> n >> cow;
        x.clear();
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            x.pb(temp);
        }
        sort(all(x));
        
        int low = 1, high = 1e9, maxi = 0;
        while(high >= low){
            int mid = low + (high-low)/2;
            if(process(mid)){
                low = mid + 1;
                maxi = max(maxi, mid);
            }
            else high = mid - 1;
        }
        cout << maxi << endl;
    }
 
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
} 