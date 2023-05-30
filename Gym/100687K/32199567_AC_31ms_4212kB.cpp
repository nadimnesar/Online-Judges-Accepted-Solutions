#include <bits/stdc++.h>
using namespace std;
 
#define llu                 long long unsigned int
#define ll                  long long int
 
#define ff                  first
#define ss                  second
#define pb                  push_back
#define popb                pop_back
#define in                  insert
#define pf                  printf
#define sf                  scanf

#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define dot(x)              fixed<<setprecision(x)

#define EPS                 (double)(1e-7)
#define MAX                 (ll)(1e5+7)
#define MOD                 (ll)(1e9+7)
#define PI                  (double)(acos(-1.0))
#define LOG(b, x)           (double)(log(x)/log(b))
 
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

vector < string > grid;
bool valid(int r, int c){
    if(r < 0 or r >= 16) return false;
    if(c < 0 or c >= 32) return false;
    if(grid[r][c] == '.') return false;
    return true;
}

int tail_x, tail_y;

void tail_finder(int x, int y){
    while(true){
        if(grid[x][y] == ':'){
            if(valid(x, y+1) and grid[x][y+1] == '<') y++;
            else if(valid(x+1, y) and grid[x+1][y] == '^') x++;
            else if(valid(x, y-1) and grid[x][y-1] == '>') y--;
            else if(valid(x-1, y) and grid[x-1][y] == 'v') x--;
            else break;
        }
        if(grid[x][y] == '>'){
            if(valid(x, y+1) and grid[x][y+1] == '<') y++;
            else if(valid(x+1, y) and grid[x+1][y] == '^') x++;
            else if(valid(x, y-1) and grid[x][y-1] == '>') y--;
            else if(valid(x-1, y) and grid[x-1][y] == 'v') x--;
            else break;
        }
        if(valid(x, y) and grid[x][y] == '<'){
            if(valid(x, y+1) and grid[x][y+1] == '<') y++;
            else if(valid(x+1, y) and grid[x+1][y] == '^') x++;
            else if(valid(x, y-1) and grid[x][y-1] == '>') y--;
            else if(valid(x-1, y) and grid[x-1][y] == 'v') x--;
            else break;
        }
        if(valid(x, y) and grid[x][y] == '^'){
            if(valid(x, y+1) and grid[x][y+1] == '<') y++;
            else if(valid(x+1, y) and grid[x+1][y] == '^') x++;
            else if(valid(x, y-1) and grid[x][y-1] == '>') y--;
            else if(valid(x-1, y) and grid[x-1][y] == 'v') x--;
            else break;
        }
        if(valid(x, y) and grid[x][y] == 'v'){
            if(valid(x, y+1) and grid[x][y+1] == '<') y++;
            else if(valid(x+1, y) and grid[x+1][y] == '^') x++;
            else if(valid(x, y-1) and grid[x][y-1] == '>') y--;
            else if(valid(x-1, y) and grid[x-1][y] == 'v') x--;
            else break;
        }
    }

    tail_x = x;
    tail_y = y;
}



void solve(){
    for(int i = 0; i < 16; i++){
        string temp;
        cin >> temp;
        grid.pb(temp);
    }

    int head_x, head_y;
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 32; j++){
            if(grid[i][j] == ':'){
                head_x = i;
                head_y = j;
                break;
            }
        }
    }
    
    tail_finder(head_x, head_y);

    string str;
    cin >> str;

    for(int i = 0; str[i]; i++){
        
        if(str[i] == '<'){
            if(grid[head_x][head_y-1] == 'E'){
                cout << "Yes" << endl;
                return;
            }
            grid[tail_x][tail_y] = '.';
            if(grid[head_x][head_y-1] != '.'){
                cout << "No" << endl;
                return;
            }
            grid[head_x][head_y-1] = ':';
            grid[head_x][head_y] = str[i];
            head_y--;
            tail_finder(head_x, head_y);
        }
        if(str[i] == '>'){
            if(grid[head_x][head_y+1] == 'E'){
                cout << "Yes" << endl;
                return;
            }
            grid[tail_x][tail_y] = '.';
            if(grid[head_x][head_y+1] != '.'){
                cout << "No" << endl;
                return;
            }
            grid[head_x][head_y+1] = ':';
            grid[head_x][head_y] = str[i];

            head_y++;
            tail_finder(head_x, head_y);
        }
        if(str[i] == '^'){
            if(grid[head_x-1][head_y] == 'E'){
                cout << "Yes" << endl;
                return;
            }
            grid[tail_x][tail_y] = '.';
            if(grid[head_x-1][head_y] != '.'){
                cout << "No" << endl;
                return;
            }
            grid[head_x-1][head_y] = ':';
            grid[head_x][head_y] = str[i];

            head_x--;
            tail_finder(head_x, head_y);
        }
        if(str[i] == 'v'){
            if(grid[head_x+1][head_y] == 'E'){
                cout << "Yes" << endl;
                return;
            }
            grid[tail_x][tail_y] = '.';
            if(grid[head_x+1][head_y] != '.'){
                cout << "No" << endl;
                return;
            }

            grid[head_x+1][head_y] = ':';
            grid[head_x][head_y] = str[i];

            head_x++;
            tail_finder(head_x, head_y);
        }
    }

    cout << "No" << endl;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}