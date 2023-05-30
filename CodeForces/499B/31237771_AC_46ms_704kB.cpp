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

unordered_map < string, string > um;

void solve(){
    int n, m;
    cin >> n >> m;
    string temp1, temp2;
    for(int i = 0; i < m; i++){
        cin >> temp1 >> temp2;
        um[temp1] = temp2;
        um[temp2] = temp1;
    }
    for(int i = 0; i < n; i++){
        cin >> temp1;
        temp2 = um[temp1];
        int s1 = temp1.size(), s2 = temp2.size();
        if(s1 == s2){
            if(i+1 == n) cout << temp1 << endl;
            else cout << temp1 << ' ';
        }
        else if(s1 > s2){
            if(i+1 == n) cout << temp2 << endl;
            else cout << temp2 << ' ';
        }
        else{
            if(i+1 == n) cout << temp1 << endl;
            else cout << temp1 << ' ';
        }
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
