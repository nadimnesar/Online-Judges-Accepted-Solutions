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
#define MAX              (1e5+7)
#define MOD              (int)(1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

void solve(){
    int n, k;
    cin >> n >> k; cin.ignore();
    string str; getline(cin, str);
    vector < string > tempo;
    string temp;
    for(int i = 0; str[i]; i++){
        if(str[i] == ' '){
            tempo.pb(temp);
            temp.clear();
        }
        else temp += str[i];
    }
    tempo.pb(temp);

    vector < int > quary;
    for(int i = 0; i < tempo.size(); ){
        if(tempo[i] == "undo"){
            int cmd = 0;
            for(int j = 0; j < tempo[i+1].size(); j++){
                cmd = (cmd*10) + (tempo[i+1][j]-48);
            }
            while(cmd--) quary.pop();
            i += 2;
        }
        else{
            bool neg = false;
            int cmd = 0;
            for(int j = 0; j < tempo[i].size(); j++){
                if(tempo[i][j] >= '0' and tempo[i][j] <= '9'){
                    cmd = (cmd*10) + (tempo[i][j]-48);
                }
                else{
                    neg = true;
                }
            }
            if(neg) cmd *= -1;
            quary.pb(cmd);
            i++;
        }
    }
    int have = 0;
    for(int i = 0; i < quary.size(); i++){
        int cmd = quary[i];
        if(cmd < 0){
            cmd = abs(cmd);
            cmd = cmd%n;
            cmd = n-cmd;
            have += cmd;
            if(have >= n) have -= n;
        }
        else if(cmd > 0){
            cmd = cmd%n;
            have += cmd;
            if(have >=n) have -= n;
        }
    }
    cout << have << endl;
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }
 
}