#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define ist              insert
#define mp               make_pair
#define pop              pop_back
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    string str;
    while(getline(cin, str)){
        if(str[0] >= '0' and str[0] <= '9'){
            reverse(full(str));
            string temp;
            for(ll i = 0; str[i]; i++){
                ll len = temp.size();
                if(len == 0){
                    temp += str[i];
                }
                else if(len == 1){
                    temp += str[i];
                    stringstream ss(temp);
                    ll value;
                    ss >> value;
                    if((value >= 65 and value <= 90) or (value >= 97 and value <= 122)){
                        cout << char(value);
                        temp.clear();
                        continue;
                    }
                    else if(value == 32 or value == 33 or value == 44 or value == 46 or value == 58 or value == 59 or value == 63){
                        cout << char(value);
                        temp.clear();
                        continue;
                    }
                    else continue;
                }
                else if(len == 2){
                    temp += str[i];
                    stringstream ss(temp);
                    ll value;
                    ss >> value;
                    if((value >= 65 and value <= 90) or (value >= 97 and value <= 122)){
                        cout << char(value);
                        temp.clear();
                        continue;
                    }
                }
            }
            cout << endl;
        }
        else{
            vector < string > final;
            for(ll i = 0; str[i]; i++){
                string temp;
                temp += to_string((int)str[i]);
                reverse(full(temp));
                final.pb(temp);
            }
            reverse(full(final));
            ll len = final.size();
            for(int i = 0; i < len; i++){
                cout << final[i];
            }
            cout << endl;
        }
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
