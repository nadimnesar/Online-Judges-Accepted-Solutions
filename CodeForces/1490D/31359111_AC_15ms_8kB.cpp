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
#define alluniq(x, y)    x.resize(distance(x.begin(),unique(x.begin(),x.begin()+y)))
 
#define EPS              (1e-7)
#define MAX              (1e6+7)
#define MOD              (int)(1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

int res[107];
int arr[107];

void BT(int depth, int left, int right){
    if(left > right) return;
    if(left == right){
        res[arr[left]] = depth;
        return;
    }

    int index = -1;
    int maxi = -1;
    for(int i = left; i <= right; i++){
        if(arr[i] > maxi){
            index = i;
            maxi = arr[i];
        }
    }
    res[arr[index]] = depth;

    BT(depth+1, left, index-1);
    BT(depth+1, index+1, right);
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    BT(0, 0, n-1);
    for(int i = 0; i < n; i++){
        if(i+1 == n) cout << res[arr[i]] << endl;
        else cout << res[arr[i]] << ' ';
    }
}

int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    // int cn = 0;
    while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    }
 
}