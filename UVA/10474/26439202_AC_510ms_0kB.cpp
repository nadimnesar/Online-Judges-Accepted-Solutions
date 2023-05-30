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

int binarysearch(vector < int > x, int q){
    int right = x.size()-1;
    int left = 0;
    int index = -1;
    while(right >= left){
        int mid = left + (right-left)/2;
        if (x[mid] == q){
            index = mid;
            right = mid -1;
        }
        else if(x[mid] > q) right = mid-1;
        else left = mid+1;
    }
    return index;
}

int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO;

    int cn = 0;

    while(1){
        int n, q;
        cin >> n >> q;
        if(n == 0 and q == 0) break;

        vector < int > x;
        for(int i = 0; i < n; i++){
            int p;
            cin >> p;
            x.pb(p);
        }
        sort(all(x));
        cout << "CASE# " << ++cn << ":" << endl;
        while(q--){
            int temp;
            cin >> temp;
            int lower = binarysearch(x, temp);
            if(lower == -1) cout << temp << " not found" << endl;
            else cout << temp << " found at " << lower+1 << endl;
        }
        x.clear();
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}