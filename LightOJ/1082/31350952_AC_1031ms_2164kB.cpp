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
#define MAX              (int)(1e5+7)
#define MOD              (int)(1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

int arr[MAX];
int segTree[MAX*4];

void build_segTree(int index, int left, int right){
    if(left == right){
        segTree[index] = arr[left];
        return;
    }
    int mid = (left+right) >> 1;
    build_segTree((index << 1), left, mid);
    build_segTree((index << 1)+1, mid+1, right);

    segTree[index] = min(segTree[(index << 1)], segTree[(index << 1)+1]);
}

int range_quary(int index, int left, int right, int s, int e){
    if(right < s or left > e) return INT_MAX;
    if(left >= s and right <= e) return segTree[index];

    int mid = (left+right) >> 1;
    int left_min = range_quary((index << 1), left, mid, s, e);
    int right_min = range_quary((index << 1)+1, mid+1, right, s, e);

    return min(left_min, right_min);
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    build_segTree(1, 1, n);
    for(int i = 1; i <= q; i++){
        int s, e;
        cin >> s >> e;
        cout << range_quary(1, 1, n, s, e) << endl;
    }
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    int cn = 0;
    while(t--){
        // cout << "Case " << ++cn << ": ";
        cout << "Case " << ++cn << ':' << endl;
        solve();
    }
 
}
