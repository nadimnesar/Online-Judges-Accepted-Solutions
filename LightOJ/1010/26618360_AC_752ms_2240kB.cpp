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

    int t, cn = 0;
    cin >> t;
    while(t--){
        int r, c;
        cin >> r >> c;
        cout << "Case " << ++cn << ": ";
        if(r == 1 or c == 1){
            cout << max(r, c) << endl;
        }
        else if(r == 2 or c == 2){
            int maxi = max(r, c);
            if(maxi%4 == 1 or maxi%4 == 3) maxi++;
            else if(maxi%4 == 2) maxi+=2;
            cout << maxi << endl;
        }
        else if((r*c)&1){
            cout << ceil((r*c)/2.0) << endl;
        }
        else{
            cout << (r*c)/2 << endl;
        }
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}