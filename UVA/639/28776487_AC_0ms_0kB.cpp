#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair

#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MAX              (10000001)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

int n;
char board[5][5];
int answer;

bool check(int x, int y){
    if(board[x][y] == '.'){
        for(int i = y; i < n; i++){
            if(board[x][i] == 'X') break;
            else if(board[x][i] == 'R') return false;
            else continue;
        }
        for(int i = y; i >= 0; i--){
            if(board[x][i] == 'X') break;
            else if(board[x][i] == 'R') return false;
            else continue;
        }
        for(int i = x; i >= 0; i--){
            if(board[i][y] == 'X') break;
            else if(board[i][y] == 'R') return false;
            else continue;
        }
        for(int i = x; i < n; i++){
            if(board[i][y] == 'X') break;
            else if(board[i][y] == 'R') return false;
            else continue;
        }
        return true;
    }
    else return false;
}

void BT(int x, int y, int ans){
    if(y == n){ ++x; y = 0; }
    if(x == n){
        answer = max(answer, ans);
        return;
    }
    if(check(x, y)){
        board[x][y] = 'R';
        BT(x, y+1, ans+1);
        board[x][y] = '.';
    }
    BT(x, y+1, ans);
}

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    while(cin >> n and n){
        cin.ignore();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
            }
        }
        answer = 0;
        BT(0, 0, answer);
        cout << answer << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}