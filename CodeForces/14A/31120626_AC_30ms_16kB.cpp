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

char matrix[55][55];

void solve(){
    int r, c;
    cin >> r >> c;
    int mincol = 55;
    int maxcol = 0;
    int minrow = 55;
    int maxrow = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == '*'){
                mincol = min(mincol, j);
                maxcol = max(maxcol, j);
                minrow = min(minrow, i);
                maxrow = max(maxrow, i);
            }
        }
    }
    int start = max(minrow, mincol);
    int end = max(maxrow, maxcol);

    for(int i = minrow; i <= maxrow; i++){
        for(int j = mincol; j <= maxcol; j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }

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
