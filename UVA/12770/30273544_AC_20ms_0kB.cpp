#include <bits/stdc++.h>
using namespace std;
 
#define llu              long long unsigned int
#define ll               long long int
#define pop              pop_back
#define pb               push_back
#define mp               make_pair

#define full(x)          x.begin(), x.end()
#define iremove(x, y)    x.erase(x.begin() + y)
#define dot(x)           fixed << setprecision(x)

#define bug              cout << "!!!!" << endl
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define debug3(x, y, z)  cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

#define EPS              (1e-7)
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

map < char, ll > feq;

int main(){
 
    FastIO;

    string str;
    while(cin >> str){
        if(str == "#") break;
        for(ll i = 0; str[i]; i++) feq[str[i]]++;
        string res;
        ll odds = 0;
        for(auto it = feq.begin(); it != feq.end(); it++){
            if((it -> second)&1){
                odds++;
            }
        }
        for(auto it = feq.begin(); it != feq.end(); it++){
            if((it -> second)&1){
                if(odds != 1){
                    res += it -> first;
                    odds--;
                }
                else break;
            }
        }
        cout << res << endl;
        feq.clear();
    }

}