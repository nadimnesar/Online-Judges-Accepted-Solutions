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
#define Clock            clock_t tStart = clock()
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(distance(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)
 
#define EPS              (1e-7)
#define MAX              (100000007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }

 map < char, ll > feq;

int main(){
 
    FastIO;
/*#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif*/

    ll t; cin >> t;
    while(t--){
        ll i;
        string str; cin >> str;
        char op = ' ';
        string a, b, c;
        for(i = 0; str[i]; i++){
            if(str[i] == '+' or str[i] == '-' or str[i] == '*'){
                if(i != 0){
                    op = str[i];
                    break;
                }
            }
            a += str[i];
            feq[str[i]]++;
        }
        for(i++; str[i]; i++){
            if(str[i] == '=') break;
            b += str[i];
            feq[str[i]]++;
        }
        for(i++; str[i]; i++){
            c += str[i];
            feq[str[i]]++;
        }
        bool paisi = false;
        for(ll j = 0; j <= 9; j++){
            if(feq[j+48]) continue;
            if(a.size() > 1 and j == 0){
                if(a[0] == '?') continue;
                if(a[0] == '-' and a[1] == '?') continue;
            }
            if(b.size() > 1 and j == 0){
                if(b[0] == '?') continue;
                if(b[0] == '-' and b[1] == '?') continue;
            }
            if(c.size() > 1 and j == 0){
                if(c[0] == '?') continue;
                if(c[0] == '-' and c[1] == '?') continue;
            }
            string tempA = a, tempB = b, tempC = c;
            for(ll k = 0; tempA[k]; k++){ if(tempA[k] == '\?') tempA[k] = j+48; }
            for(ll k = 0; tempB[k]; k++){ if(tempB[k] == '\?') tempB[k] = j+48; }
            for(ll k = 0; tempC[k]; k++){ if(tempC[k] == '\?') tempC[k] = j+48; }

            ll num1 = stoi(tempA);
            ll num2 = stoi(tempB);
            ll num3 = stoi(tempC);

            if(op == '+'){
                if(num1+num2 == num3){
                    paisi = true;
                    cout << j << endl;
                    break;
                }
            }
            else if(op == '-'){
                if(num1-num2 == num3){
                    paisi = true;
                    cout << j << endl;
                    break;
                }
            }
            else{
                if(num1*num2 == num3){
                    paisi = true;
                    cout << j << endl;
                    break;
                }
            }
        }
        if(!paisi) cout << "-1" << endl;
        feq.clear();
    }

/*#ifndef ONLINE_JUDGE
    Runtime;
#endif*/

}