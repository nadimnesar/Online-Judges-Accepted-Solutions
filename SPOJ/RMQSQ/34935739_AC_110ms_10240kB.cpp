#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e5+7)                           
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

int n;
int leftt, rightt;
int arr[maxx];
int sTable[17][maxx];

void build_sTable(){
    int limit = log(10, n)/log(10, 2);
    for(int i = 0; i <= limit; i++){
        int l = 1 << i;
        for(int j = 0; j+l <= n; j++){
            if(l == 1) sTable[i][j] = arr[j];
            else sTable[i][j] = min(sTable[i-1][j], sTable[i-1][j+ l/2]);
        }
    }
}

int serarch_MIN(){
    int x = (rightt - leftt)+1;
    int limit = log(10, x)/log(10, 2);
    int l = 1 << limit;
    return min(sTable[limit][leftt], sTable[limit][(rightt-l)+1]);
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build_sTable();

    int q;
    cin >> q;
    while(q--){
        cin >> leftt >> rightt;
        cout << serarch_MIN() << endl;
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}