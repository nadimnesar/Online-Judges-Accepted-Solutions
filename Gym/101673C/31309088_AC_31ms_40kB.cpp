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
    string str;
    cin >> str;
    int n = str.size();
    string x, y;

    int xsum = 0, ysum = 0;
    for(int i = 0; i < n/2; i++){
        x += str[i];
        xsum += str[i] - 'A';
    }

    for(int i = n/2; i < n; i++){
        y += str[i];
        ysum += str[i] - 'A';
    }

    xsum = xsum%26;
    ysum = ysum%26;

    for(int i = 0; i < n/2; i++){
        int k = x[i] - 'A';
        k += xsum;
        if(k >= 26) k -= 26;
        x[i] = k + 'A';
    }

    for(int i = 0; i < n/2; i++){
        int k = y[i] - 'A';
        k += ysum;
        if(k >= 26) k -= 26;
        y[i] = k + 'A';
    }

    for(int i = 0; i < n/2; i++){
        int p = x[i] - 'A';
        int q = y[i] - 'A';
        p += q;
        if(p >= 26) p -= 26;
        x[i] = p + 'A';
    }
    cout << x << endl;
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