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

vector < string > subA;
vector < string > subB;

void solve(){
    string a; cin >> a;
    string b; cin >> b;

    subA.clear();
    subB.clear();

    string temp;
    for(int i = 0; a[i]; i++){
        temp.clear();
        for(int j = i; a[j]; j++){
            temp.pb(a[j]);
            subA.pb(temp);
        }
    }

    for(int i = 0; b[i]; i++){
        temp.clear();
        for(int j = i; b[j]; j++){
            temp.pb(b[j]);
            subB.pb(temp);
        }
    }

    int maxLen = 0;

    for(int i = 0; i < subA.size(); i++){
        for(int j = 0; j < subB.size(); j++){
            if(subA[i] == subB[j]){
                maxLen = max(maxLen, (int)subA[i].size());
            }
        }
    }

    // debug(maxLen);

    cout << (a.size()-maxLen) + (b.size() - maxLen) << endl;

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