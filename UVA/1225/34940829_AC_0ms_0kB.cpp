#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(2e7+7)                           
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

vector < unordered_map < int, int > > arr(10007);
unordered_map < int, int > temp;

void solve(){
    for(int i = 1; i<= 10000; i++){
        string str = to_string(i);
        for(int j = 0; str[j]; j++){
            temp[str[j]-'0']++;
        }
        arr[i] = temp;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i <= 9; i++){
            if(i == 9) cout << arr[n][i] << endl;
            else cout << arr[n][i] << ' ';
        }
    }
}

int main(){
 
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
    
    return 0;
}