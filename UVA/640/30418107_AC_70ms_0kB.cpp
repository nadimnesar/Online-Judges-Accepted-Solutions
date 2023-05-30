#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back

#define bug              cout << "!***!" << endl
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl

#define full(x)          x.begin(), x.end()
#define dot(x)           fixed << setprecision(x)
#define iremove(x, y)    x.erase(x.begin() + y)
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y))) //for sorted array
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define EPS              (1e-7)
#define MAX              (1000001)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

bool selfnumbers[MAX];

void solve(){
    for(int i = 1; i < MAX; i++){
        int j = i;
        int sum = i;
        while(j){
            sum += j%10;
            j /= 10;
        }
        selfnumbers[sum] = true;
    }
    for(int i = 1; i < MAX; i++){
        if(!selfnumbers[i]){
            cout << i << endl;
        }
    }
}

int main(){
    solve();
}