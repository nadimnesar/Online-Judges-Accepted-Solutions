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
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define EPS              (1e-7)
#define MAX              (5e2+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

map < char, int > feq;

void solve(){
    string str;
    getline(cin, str);
    for(int i = 0; str[i]; i++){
        if(str[i] >= 'A' and str[i] <= 'Z') feq[str[i]]++;
        else if(str[i] >= 'a' and str[i] <= 'z') feq[toupper(str[i])]++;
        else continue;
    }
}

bool cmp(pair < int, char > x, pair < int, char > y){
    if(x.first > y.first) return true;
    else if(x.first < y.first) return false;
    else{
        if(x.second < y.second) return true;
        else if(x.second > y.second) return false;
        else return false;
    }
}

int main(){
    
    FastIO;

    int t; cin >> t; cin.ignore();
    // int cn = 0;
    while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    }
    vector < pair < int, char > > ans;
    for(auto it: feq){
        ans.pb(mp(it.second, it.first));
        // cout << it.first << ' ' << it.second << endl;
    }
    sort(full(ans), cmp);
    for(auto it: ans){
        cout << it.second << ' ' << it.first << endl;
    }

}