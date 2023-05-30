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

#define EPS              (1e-7)
#define MAX              (10000007)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

void solve(){
    int n;
    while(cin >> n){
        vector < int > x;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            x.pb(temp);
        }
        vector < bool > y(n, false);
        for(int i = 1; i < n; i++){
            int z = abs(x[i]-x[i-1]);
            y[z] = true; 
        }
        int ok = true;
        for(int i = 1; i < n; i++){
            if(y[i] == false){
                ok = false;
            }
        }
        if(ok) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
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