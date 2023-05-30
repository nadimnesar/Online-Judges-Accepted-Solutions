#include <bits/stdc++.h>
using namespace std;
 
#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
// #define pop              pop_back
 
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

map < int , int > mymap;

void solve(){
    int temp, n; cin >> n;
    mymap.clear();
    for(int i = 0; i < n; i++){
        cin >> temp;
        mymap[temp]++;
    }
    priority_queue < int > q;
    for(auto it: mymap) q.push(it.second);
    int res = n;
    while(q.size() > 1){
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        x--;
        y--;
        res -= 2;
        if(x) q.push(x);
        if(y) q.push(y);
    }
    cout << res << endl;
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