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
#define Clock            clock_t tStart = clock()
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)

#define MAX              (10000001)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

int grid[1025][1025];

bool compare(pair < int , pair < int, int > > a, pair < int , pair < int, int > > b){
    if(a.first > b.first) return true;
    else if(a.first < b.first) return false;
    else if(a.second.first < b.second.first) return true;
    else if(a.second.first > b.second.first) return false;
    else if(a.second.second <= b.second.second) return true;
    else return false;
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> d >> n;
        int maxr = 0, minr = 1025, maxc = 0, minc = 1025;
        for(int i = 0; i < n; i++){
            int x, y, size;
            cin >> x >> y >> size;
            for(int r = max(x-d, 0); r <= min(x+d, 1024); r++){
                for(int c = max(y-d, 0); c <= min(y+d, 1024); c++){
                    grid[r][c] += size;
                }
            }
        }
        int ans = 0, row, column;
        for(int i = 0; i < 1025; i++){
            for(int j = 0; j < 1025; j++){
                if(grid[i][j] > ans){
                    ans = grid[i][j];
                    row = i;
                    column = j;
                }
            }
        }
        cout << row << ' ' << column << ' ' << ans << endl;
        memset(grid, 0,  sizeof(grid));
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}
