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

    llu W, H, N;
    while(cin >> W >> H >> N and W and H){
        llu matrix[H][W];
        for(llu i = 0; i < H; i++){
            for(llu j = 0; j < W; j++){
                matrix[i][j] = 0;
            }
        }

        while(N--){
            llu x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);

            for(llu i = y1-1; i < y2; i++){
                for(llu j = x1-1; j < x2; j++){
                    matrix[i][j] = 1;
                }
            }
        }

        llu free = 0;
        for(llu i = 0; i < H; i++){
            for(llu j = 0; j < W; j++){
                if(matrix[i][j] == 0){
                    free++;
                }
            }
        }
        if(free ==  0) cout << "There is no empty spots." << endl;
        else if(free == 1) cout << "There is one empty spot." << endl;
        else cout << "There are " << free << " empty spots." << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}