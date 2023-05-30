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
        char matrix[64][64];
        int x, y;
        cin >> x >> y;
        cin.ignore();
        for(int i = 0; i < 64; i++){
            for(int j = 0; j < 64; j++){
                if(i == y and j == x){
                    matrix[i][j] = 'x';
                }
                else matrix[i][j] = '.';
            }
        }
        int n = 0;
        string str;
        cin >> str;
        int len = str.size();
        int direction = 1; //1 = up, 2 = right, 3 = down, 4 = left

        set < pair < int, int > > pos;

        for(int i = 0; i < len; i++){
            if(str[i] == 'F'){
                if(direction == 1){
                    y++;
                    if(matrix[y][x] == 'x'){
                        pos.inst(make_pair(x, y));
                    }
                    else matrix[y][x] = 'x';
                }
                else if(direction == 2){
                    x++;
                    if(matrix[y][x] == 'x'){
                        pos.inst(make_pair(x, y));
                    }
                    else matrix[y][x] = 'x';
                }
                else if(direction == 3){
                    y--;
                    if(matrix[y][x] == 'x'){
                        pos.inst(make_pair(x, y));
                    }
                    else matrix[y][x] = 'x';
                }
                else{
                    x--;
                    if(matrix[y][x] == 'x'){
                        pos.inst(make_pair(x, y));
                    }
                    else matrix[y][x] = 'x';
                }
            }
            else if(str[i] == 'R'){
                direction++;
                if(direction == 5){
                    direction = 1;
                }
                if(direction == 0){
                    direction = 4;
                }
            }
            else{
                direction--;
                if(direction == 5){
                    direction = 1;
                }
                if(direction == 0){
                    direction = 4;
                }
            }
        }
        cout << "Case #" << ++cn << ": ";
        cout << x << ' ' << y << ' ' << pos.size() << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}
