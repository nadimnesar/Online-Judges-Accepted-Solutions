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

int volume(int X1, int Y1, int Z1, int X2, int Y2, int Z2){
    if(X2 > X1 and Y2 > Y1 and Z2 > Z1){
        return (X2-X1)*(Y2-Y1)*(Z2-Z1);
    }
    else return 0;
}


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
        cout << "Case " << ++cn << ": ";
        int n;
        cin >> n;

        int mX1 = 1;
        int mY1 = 1;
        int mZ1 = 1;

        int mX2 = 1000;
        int mY2 = 1000;
        int mZ2 = 1000;

        while(n--){
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

            mX1 = max(mX1, x1);
            mY1 = max(mY1, y1);
            mZ1 = max(mZ1, z1);

            mX2 = min(mX2, x2);
            mY2 = min(mY2, y2);
            mZ2 = min(mZ2, z2);
        }

        cout << volume(mX1, mY1, mZ1, mX2, mY2, mZ2) << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}