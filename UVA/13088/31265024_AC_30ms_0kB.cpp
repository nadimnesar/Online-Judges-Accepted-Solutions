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
#define MOD              (int)(1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

string str;
map < char, int > um;

void solve(){
    cin >> str;
    for(int i = 0; str[i]; i++){
        um[str[i]]++;
    }
    char smallest;
    for(auto it: um){
        smallest = it.first;
        break;
    }
    int cnt = 0;
    for(auto it: um){
        if(it.first == smallest) cnt += it.second;
        else cnt += (it.second - 1);
    }
    while(cnt--) cout << smallest;
    for(auto it: um){
        if(it.first == smallest) continue;
        else cout << it.first;
    }
    cout << endl;
    um.clear();
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    // int cn = 0;
    while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    }

}