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
#define debug3(x, y, z)  cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

#define full(x)          x.begin(), x.end()
#define dot(x)           fixed << setprecision(x)
#define iremove(x, y)    x.erase(x.begin() + y)
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y))) //for sorted arry
#define Clock            clock_t tStart = clock()
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)

#define EPS              (1e-7)
#define MAX              (107)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

map < char , bool > dic;
bool checker(){
}

void solve(){
    string str; cin >> str;
    int maxi = 0;
    for(int i = 0; str[i]; i++){
        for(int j = i; str[j]; j++){

            int left = i; int right = j;
            bool mirror = true;
            while(left <= right){
                if(!dic[str[left]]){
                    mirror = false;
                    break;
                }
                if(!dic[str[right]]){
                    mirror = false;
                    break;
                }
                if(str[left] != str[right]){
                    mirror = false;
                    break;
                }
                left++;
                right--;
            }
            if(mirror) maxi = max(maxi, (abs(i-j)+1));
        }
    }
    cout << maxi << endl;
}

int main(){
    FastIO;
    dic['A'] = true;
    dic['H'] = true;
    dic['I'] = true;
    dic['M'] = true;
    dic['O'] = true;
    dic['T'] = true;
    dic['U'] = true;
    dic['V'] = true;
    dic['W'] = true;
    dic['X'] = true;
    dic['Y'] = true;
    ll t; cin >> t;
    while(t--){
        solve();
    }
}
