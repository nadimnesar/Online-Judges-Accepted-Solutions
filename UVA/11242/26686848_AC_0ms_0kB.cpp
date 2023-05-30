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


int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    while(1){
        int front, rear;
        cin >> front;
        if(front == 0) break;
        cin >> rear;
        vector < double > x(front);
        vector < double > y(rear);
        for(int i = 0; i < front; i++){
            cin >> x[i];
        }
        for(int i = 0; i < rear; i++){
            cin >> y[i];
        }
        vector < double > z;
        for(int i = 0; i < front; i++){
            for(int j = 0; j < rear; j++){
                z.pb(double(y[j]/x[i]));
            }
        }
        sort(z.begin(), z.end());
        double maxi = 0;
        for(int i = 0; i < (rear*front)-1; i++){
            maxi = max(maxi, double(z[i+1]/z[i]));
        }
        cout << dot(2) << maxi << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
