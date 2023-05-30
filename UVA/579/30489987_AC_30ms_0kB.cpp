#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair

#define bug              cout<<"***!!!***"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y))) //for sorted array
#define FastIO           ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#define EPS              (1e-3)
#define MAX              (10000007)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

void solve(){
    string str;
    while(cin >> str){
        if(str == "0:00") break;
        string temp1, temp2;
        bool active = false;
        for(int i = 0; str[i]; i++){
            if(str[i] == ':'){
                active = true;
                continue;
            }
            if(active){
                temp1 += str[i];
            }
            else temp2 += str[i];
        }

        double h1 = stoi(temp2)*5;
        double h2 = stoi(temp1);
        if(h1 == 60 and h2 == 0){
            cout << dot(3) << 0.000 << endl;
            continue;
        }

        h1 += h2*(5.00/60.00);

        double x = abs(h1-h2)*6.00;
        double res = min(x, 360.00-x);

        cout << dot(3) << double(res) << endl;
    }
}

int main(){

    FastIO;
    /*int t, cn = 0;
    cin >> t;
    while(t--){*/
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    //}
    
}