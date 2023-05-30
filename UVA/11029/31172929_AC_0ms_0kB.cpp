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

#define For(x,y)         for(ll i = (int)x; i < (int)y; i++)
#define rFor(x,y)        for(ll i = (int)x; i => (int)y; i--)

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y))) //for sorted array

#define EPS              (1e-7)
#define MAX              (5e5+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

llu BIGMOD(llu B, llu P, llu M){
    if(P==0) return 1;
    if(P%2==0){
        llu p1=(BIGMOD(B,P/2,M))%M;
        return (p1*p1)%M;
    }
    else{
        llu p1=B%M;
        llu p2=(BIGMOD(B,P-1,M))%M;
        return (p1*p2)%M;
    }
}

void solve(){
    double n, k;
    cin >> n >> k;
    double z = k*LOG(10, n);
    int temp = z;
    z -= temp;
    double res = pow(10, z);
    res *= 100;
    string str = to_string(BIGMOD(n, k, 1000));
    reverse(full(str));
    while(str.size() < 3) str += '0';
    reverse(full(str));
    cout << (int)res << "..." << str << endl;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
       solve();
    }

}