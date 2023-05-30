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

map < string, int > feq;

void solve(){
    int tag, list;
    cin >> tag >> list;
    vector < int > v;
    for(int i = 0; i < tag; i++){
        int temp;
        cin >> temp;
        v.pb(temp);
    }
    sort(full(v));
    for(int i = 0; i < list; i++){
        string str;
        cin >> str;
        feq[str]++;
    }
    vector < int > copyfeq;
    for(auto it: feq){
        copyfeq.pb(it.second);
    }
    sort(full(copyfeq), greater < int > ());
    int minres = 0;
    int maxres = 0;

    int i = 0;
    int j = tag-1;
    for(int k = 0; k < copyfeq.size(); k++){
        minres += copyfeq[k]*v[i++];
        maxres += copyfeq[k]*v[j--];
    }
    cout << minres << ' ' << maxres << endl;
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
