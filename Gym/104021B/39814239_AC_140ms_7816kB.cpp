#include "bits/stdc++.h"
using namespace std;

#define ll                  long long
#define llu                 unsigned long long

#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)(10)
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void nadimnesar() {
    ll n;
    cin >> n;

    ll grid[n][n];

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (grid[i][j] != 0 and grid[i][j] != -1) {

                ll x = grid[i][j];

                bool row = true;
                bool column = true;

                for (ll k = 0; k < n; k++) {
                    if (grid[i][k] < x or grid[i][k] == 0 or grid[i][k] == -1) {
                        row = false;
                        break;
                    }
                }

                for (ll k = 0; k < n; k++) {
                    if (grid[k][j] < x or grid[k][j] == 0 or grid[k][j] == -1) {
                        column = false;
                        break;
                    }
                }

                if (row) {
                    for (ll k = 0; k < n; k++) grid[i][k] -= x;
                }
                else if(column) {
                    for (ll k = 0; k < n; k++) grid[k][j] -= x;
                }
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {

            if(grid[i][j] == -1){

                ll row_mn = 1e6+1;
                ll col_mn =  1e6+1;

                for (ll k = 0; k < n; k++) {
                    if (grid[i][k] != -1) {
                        row_mn = min(grid[i][k], row_mn);
                    }
                }

                for (ll k = 0; k < n; k++) {
                    if (grid[k][j] != -1) {
                        col_mn = min(grid[k][j], col_mn);
                    }
                }

                cout << row_mn+col_mn << endl;
                return;
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}