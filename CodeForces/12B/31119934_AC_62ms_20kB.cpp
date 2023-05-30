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

map < char, int > feq;

void solve(){
    string alice, bob;
    cin >> alice >> bob;
    if(alice == "0"){
        if(bob == "0"){
            cout << "OK" << endl;
        }
        else cout << "WRONG_ANSWER" << endl;
        return;
    }
    for(int i = 0; alice[i]; i++){
        feq[alice[i]]++;
    }
    int zeros = 0;
    string right;
    bool flag = 0;
    for(auto it: feq){
        if(it.first == '0'){
            zeros += it.second;
            continue;
        }
        if(!flag and zeros){
            right += it.first;
            it.second--;
            while(zeros){
                right += '0';
                zeros--;
            }
            int temp = it.second;
            while(temp){
                right += it.first;
                temp--;
            }
            flag = true;
            continue;
        }
        int temp = it.second;
        while(temp){
            right += it.first;
            temp--;
        }
    }
    // cout << right << endl;
    if(right == bob) cout << "OK" << endl;
    else cout << "WRONG_ANSWER" << endl;
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
