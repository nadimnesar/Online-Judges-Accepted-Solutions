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
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }

ll SUMofDigit(ll n){
    if(n <= 9) return n;
    ll sum = 0;
    while(n){
        sum += n%10;
        n /= 10;
    }
    return SUMofDigit(sum);
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    string s1, s2;
    while(getline(cin, s1)){
        getline(cin, s2);
        double saima = 0, santo = 0;
        for(ll i = 0; s1[i]; i++){
            if(s1[i] >= 'a' and s1[i] <= 'z'){
                saima += (s1[i]-'a')+1;
            }
            else if(s1[i] >= 'A' and s1[i] <= 'Z'){
                saima += (s1[i]-'A')+1;
            }
            else continue;
        }
        for(ll i = 0; s2[i]; i++){
            if(s2[i] >= 'a' and s2[i] <= 'z'){
                santo += (s2[i]-'a')+1;
            }
            else if(s2[i] >= 'A' and s2[i] <= 'Z'){
                santo += (s2[i]-'A')+1;
            }
            else continue;
        }
        saima = (double)SUMofDigit((ll)saima);
        santo = (double)SUMofDigit((ll)santo);
        cout << dot(2) << (min(saima, santo)/max(saima, santo))*100 << " %" << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}
