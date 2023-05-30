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

    llu n;
    cin >> n;
    while(n--){
        char matrix[3][3];
        llu xx = 0, oo = 0, dot = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cin >> matrix[i][j];
                if(matrix[i][j] == 'X'){
                    xx++;
                }
                else if(matrix[i][j] == 'O') oo++;
                else dot++;
            }
        }

        llu xwin = 0, owin = 0;

        //row_1
        if(matrix[0][0] == matrix[0][1] and matrix[0][1] == matrix[0][2] and matrix[0][2] == 'X') xwin++;
        else if(matrix[0][0] == matrix[0][1] and matrix[0][1] == matrix[0][2] and matrix[0][2] == 'O') owin++;
        //row_2
        if(matrix[1][0] == matrix[1][1] and matrix[1][1] == matrix[1][2] and matrix[1][2] == 'X') xwin++;
        else if(matrix[1][0] == matrix[1][1] and matrix[1][1] == matrix[1][2] and matrix[1][2] == 'O') owin++;
        //row_3
        if(matrix[2][0] == matrix[2][1] and matrix[2][1] == matrix[2][2] and matrix[2][2] == 'X') xwin++;
        else if(matrix[2][0] == matrix[2][1] and matrix[2][1] == matrix[2][2] and matrix[2][2] == 'O') owin++;
        //column_1
        if(matrix[0][0] == matrix[1][0] and matrix[1][0] == matrix[2][0] and matrix[2][0] == 'X') xwin++;
        else if(matrix[0][0] == matrix[1][0] and matrix[1][0] == matrix[2][0] and matrix[2][0] == 'O') owin++;
        //column_2
        if(matrix[0][1] == matrix[1][1] and matrix[1][1] == matrix[2][1] and matrix[2][1] == 'X') xwin++;
        else if(matrix[0][1] == matrix[1][1] and matrix[1][1] == matrix[2][1] and matrix[2][1] == 'O') owin++;
        //column_3
        if(matrix[0][2] == matrix[1][2] and matrix[1][2] == matrix[2][2] and matrix[2][2] == 'X') xwin++;
        else if(matrix[0][2] == matrix[1][2] and matrix[1][2] == matrix[2][2] and matrix[2][2] == 'O') owin++;
        //left_diagonal
        if(matrix[0][0] == matrix[1][1] and matrix[1][1] == matrix[2][2] and matrix[2][2] == 'X') xwin++;
        else if(matrix[0][0] == matrix[1][1] and matrix[1][1] == matrix[2][2] and matrix[2][2] == 'O') owin++;
        //right_diagonal
        if(matrix[0][2] == matrix[1][1] and matrix[1][1] == matrix[2][0] and matrix[2][0] == 'X') xwin++;
        else if(matrix[0][2] == matrix[1][1] and matrix[1][1] == matrix[2][0] and matrix[2][0] == 'O') owin++;

        
        if(owin > 1) cout << "no" << endl;
        else if(owin == 1){
            if(xx == oo and xwin == 0) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else if(xwin > 2) cout << "no" << endl;
        else if(xwin == 2){
            if(xx == 5 and oo == 4 and dot == 0 and owin == 0) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else if(xwin == 1){
            if(oo == xx-1 and owin == 0) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else if(xx == oo or oo == xx-1) cout << "yes" << endl;
        else cout << "no" << endl;

    }


#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}