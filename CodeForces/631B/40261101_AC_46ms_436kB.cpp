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

typedef struct node
{
    int value;
    int rank = -1;
} node;

void nadimnesar() {
    int n, m, k;
    cin >> n >> m >> k;

    int grid[n][m] = { };

    node row[n];
    node col[m];

    for(int i = 0; i < k; i++){
        int c, x, y;
        cin >> c >> x >> y;

        node z;
        z.value = y;
        z.rank = i;

        if(c == 1) row[x-1] = z;
        else col[x-1] = z;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(row[i].rank == -1 and col[j].rank ==  -1) cout << 0 << ' ';
            else if(row[i].rank == -1) cout << col[j].value << ' ';
            else if(col[j].rank == -1) cout << row[i].value << ' ';
            else if(row[i].rank > col[j].rank) cout << row[i].value << ' ';
            else cout << col[j].value << ' ';

        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}