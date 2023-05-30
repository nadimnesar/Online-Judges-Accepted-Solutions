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
#define MAX              (1e5+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

int matrix[101][101];
int n;

int kodaneSalgo(vector < int > &subarray){
    int maxi = 0;
    int premexi = 0;
    for(int i = 0; i < n; i++){
        if(subarray[i] > (premexi+subarray[i])) premexi = subarray[i];
        else premexi = (premexi+subarray[i]);
        maxi = max(premexi, maxi);
    }
    return maxi;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    int maxi = 0;
    for(int s = 0; s < n; s++){
        vector < int > subarray(n, 0);
        for(int c = s; c < n; c++){
            for(int r = 0; r < n; r++){
                subarray[r] += matrix[r][c];
            }
            maxi = max(maxi, kodaneSalgo(subarray));
        }
    }
    cout << maxi << endl;
}

int main(){
    
    FastIO;
    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }
}