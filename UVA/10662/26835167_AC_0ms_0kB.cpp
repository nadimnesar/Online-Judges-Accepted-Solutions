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

    int T, R, H;
    while(cin >> T >> R >> H){

        int travel[20][20], restaurants[20][20], hotel[20][20];
        int Tmoney[20], Rmoney[20], Hmoney[20];

        for(int i = 0; i < T; i++){
            cin >> Tmoney[i];
            for(int j = 0; j < R; j++){
                cin >> travel[i][j];
            }
        }

        for(int i = 0; i < R; i++){
            cin >> Rmoney[i];
            for(int j = 0; j < H; j++){
                cin >> restaurants[i][j];
            }
        }

        for(int i = 0; i < H; i++){
            cin >> Hmoney[i];
            for(int j = 0; j < T; j++){
                cin >> hotel[i][j];
            }
        }
        bool found = false;
        int t, r, h, sum = INT_MAX;
        for(int i = 0; i < T; i++){
            for(int j = 0; j < R; j++){
                for(int k = 0; k < H; k++){
                    if(!travel[i][j] and !restaurants[j][k] and !hotel[k][i]){
                        found = true;
                        int money = Tmoney[i]+Hmoney[k]+Rmoney[j];
                        if(money < sum){
                            sum = min(sum, money);
                            t = i;
                            r = j;
                            h = k;
                        }
                    }
                }
            }
        }

        if(found) cout << t << ' ' << r << ' ' << h << ':' << sum << endl;
        else cout << "Don't get married!" << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}
