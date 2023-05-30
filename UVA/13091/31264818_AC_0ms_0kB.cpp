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

char str[5][5];

void solve(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> str[i][j];
        }
    }
    bool noball = false;
    int line = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(str[i][j] == '|'){
                line = j;
                break;
            }
            if(str[i][j] == '<'){
                noball = true;
                break;
            }
        }
    }
    if(noball){
        cout << "No Ball" << endl;
        return;
    }
    for(int i = 0; i < 5; i++){
        for(int j = line+1; j < 5; j++){
            if(str[i][j] == '>'){
                noball = true;
                break;
            }
        }
    }

    if(noball) cout << "No Ball" << endl;
    else cout << "Thik Ball" << endl;
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    int cn = 0;
    while(t--){
        cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    }

}