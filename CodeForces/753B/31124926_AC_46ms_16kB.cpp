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

void solve(){
    string res;
    int x, y;
    cout << "0000" << endl;
    cin >> x >> y;
    if(x == 1) res += '0';
    cout << "1111" << endl;
    cin >> x >> y;
    if(x == 1) res += '1';
    cout << "2222" << endl;
    cin >> x >> y;
    if(x == 1) res += '2';
    cout << "3333" << endl;
    cin >> x >> y;
    if(x == 1) res += '3';
    cout << "4444" << endl;
    cin >> x >> y;
    if(x == 1) res += '4';
    cout << "5555" << endl;
    cin >> x >> y;
    if(x == 1) res += '5';
    cout << "6666" << endl;
    cin >> x >> y;
    if(x == 1) res += '6';
    cout << "7777" << endl;
    cin >> x >> y;
    if(x == 1) res += '7';
    cout << "8888" << endl;
    cin >> x >> y;
    if(x == 1) res += '8';
    cout << "9999" << endl;
    cin >> x >> y;
    if(x == 1) res += '9';

    sort(full(res));
    do{
        cout << res << endl;
        cin >> x >> y;
        if(x == 4) return;
    }
    while(next_permutation(full(res)));
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
