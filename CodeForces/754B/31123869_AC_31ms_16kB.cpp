#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y)))    

#define EPS              (1e-7)
#define MAX              (1e5+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

char arkoto[5][5];

bool valid(int r, int c){
    if(r < 0 or r >= 4) return false;
    if(c < 0 or c >= 4) return false;
    if(arkoto[r][c] == 'o') return false;
    return true;
}

bool sojasuji(int r, int c){
    int x;
    int dot;

    if(valid(r, c) and valid(r+1, c) and valid(r+2, c)){
        x = 0;
        dot = 0;

        if(arkoto[r][c] == 'x') x++;
        else dot++;

        if(arkoto[r+1][c] == 'x') x++;
        else dot++;

        if(arkoto[r+2][c] == 'x') x++;
        else dot++;

        if(x == 2 and dot == 1) return true;

    }

    if(valid(r-1, c) and valid(r, c) and valid(r+1, c)){
        x = 0;
        dot = 0;

        if(arkoto[r-1][c] == 'x') x++;
        else dot++;

        if(arkoto[r][c] == 'x') x++;
        else dot++;

        if(arkoto[r+1][c] == 'x') x++;
        else dot++;

        if(x == 2 and dot == 1) return true;
    }

    if(valid(r-2, c) and valid(r-1, c) and valid(r, c)){
        x = 0;
        dot = 0;

        if(arkoto[r-2][c] == 'x') x++;
        else dot++;

        if(arkoto[r-1][c] == 'x') x++;
        else dot++;

        if(arkoto[r][c] == 'x') x++;
        else dot++;

        if(x == 2 and dot == 1) return true;
    }

    return false;
}

bool bakabaki(int r, int c){
    int x;
    int dot;

    if(valid(r, c) and valid(r, c+1) and valid(r, c+2)){
        x = 0;
        dot = 0;

        if(arkoto[r][c] == 'x') x++;
        else dot++;

        if(arkoto[r][c+1] == 'x') x++;
        else dot++;

        if(arkoto[r][c+2] == 'x') x++;
        else dot++;

        if(x == 2 and dot == 1) return true;

    }

    if(valid(r, c-1) and valid(r, c) and valid(r, c+1)){
        x = 0;
        dot = 0;

        if(arkoto[r][c-1] == 'x') x++;
        else dot++;

        if(arkoto[r][c] == 'x') x++;
        else dot++;

        if(arkoto[r][c+1] == 'x') x++;
        else dot++;

        if(x == 2 and dot == 1) return true;
    }

    if(valid(r, c-2) and valid(r, c-1) and valid(r, c)){
        x = 0;
        dot = 0;

        if(arkoto[r][c-2] == 'x') x++;
        else dot++;

        if(arkoto[r][c-1] == 'x') x++;
        else dot++;

        if(arkoto[r][c] == 'x') x++;
        else dot++;

        if(x == 2 and dot == 1) return true;
    }

    return false;
}

bool teratri_right(int r, int c){
    int x;
    int dot;

    if(valid(r, c) and valid(r+1, c-1) and valid(r+2, c-2)){
        x = 0;
        dot = 0;

        if(arkoto[r][c] == 'x') x++;
        else dot++;

        if(arkoto[r+1][c-1] == 'x') x++;
        else dot++;

        if(arkoto[r+2][c-2] == 'x') x++;
        else dot++;

        if(x == 2 and dot == 1) return true;

    }

    if(valid(r-1, c+1) and valid(r, c) and valid(r+1, c-1)){
        x = 0;
        dot = 0;

        if(arkoto[r-1][c+1] == 'x') x++;
        else dot++;

        if(arkoto[r][c] == 'x') x++;
        else dot++;

        if(arkoto[r+1][c-1] == 'x') x++;
        else dot++;

        if(x == 2 and dot == 1) return true;
    }

    if(valid(r, c) and valid(r-1, c+1) and valid(r-2, c+2)){
        x = 0;
        dot = 0;

        if(arkoto[r][c] == 'x') x++;
        else dot++;

        if(arkoto[r-1][c+1] == 'x') x++;
        else dot++;

        if(arkoto[r-2][c+2] == 'x') x++;
        else dot++;

        if(x == 2 and dot == 1) return true;
    }

    return false;
}

bool teratri_left(int r, int c){
    int x;
    int dot;

    if(valid(r, c) and valid(r+1, c+1) and valid(r+2, c+2)){
        x = 0;
        dot = 0;

        if(arkoto[r][c] == 'x') x++;
        else dot++;

        if(arkoto[r+1][c+1] == 'x') x++;
        else dot++;

        if(arkoto[r+2][c+2] == 'x') x++;
        else dot++;

        if(x == 2 and dot == 1) return true;

    }

    if(valid(r-1, c-1) and valid(r, c) and valid(r+1, c+1)){
        x = 0;
        dot = 0;

        if(arkoto[r-1][c-1] == 'x') x++;
        else dot++;

        if(arkoto[r][c] == 'x') x++;
        else dot++;

        if(arkoto[r+1][c+1] == 'x') x++;
        else dot++;

        if(x == 2 and dot == 1) return true;
    }

    if(valid(r, c) and valid(r-1, c-1) and valid(r-2, c-2)){
        x = 0;
        dot = 0;

        if(arkoto[r][c] == 'x') x++;
        else dot++;

        if(arkoto[r-1][c-1] == 'x') x++;
        else dot++;

        if(arkoto[r-2][c-2] == 'x') x++;
        else dot++;

        if(x == 2 and dot == 1) return true;
    }

    return false;
}

void solve(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> arkoto[i][j];
        }
    }
    bool ok = false;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(arkoto[i][j] == 'o') continue;
            if(sojasuji(i, j)){
                ok = true;
                break;
            }
            if(bakabaki(i, j)){
                ok = true;
                break;
            }
            if(teratri_left(i, j)){
                ok = true;
                break;
            }
            if(teratri_right(i, j)){
                ok = true;
                break;
            }
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }

}
