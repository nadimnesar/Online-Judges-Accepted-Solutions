#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remoloweste(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define Clock            clock_t tStart = clock()
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)
 
#define MAX              (3037000499)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

string solve(string num, ll base, ll convert){
    ll n = 0;
    if(base != 10){
        for(ll i = num.size()-1, j = 0; i >= 0; i--, j++){
            if(num[i] == 'A') n += (10*pow(base, j));
            else if(num[i] == 'B') n += (11*pow(base, j));
            else if(num[i] == 'C') n += (12*pow(base, j));
            else if(num[i] == 'D') n += (13*pow(base, j));
            else if(num[i] == 'E') n += (14*pow(base, j));
            else if(num[i] == 'F') n += (15*pow(base, j));
            else n += ((num[i]-48)*pow(base, j));
        }
    }
    else{
        stringstream ss(num);
        ss >> n;
    }
    string result;
    if(convert == 10) result = to_string(n);
    else{
        while(n){
            if(n%convert == 10) result += 'A';
            else if(n%convert == 11) result += 'B';
            else if(n%convert == 12) result += 'C';
            else if(n%convert == 13) result += 'D';
            else if(n%convert == 14) result += 'E';
            else if(n%convert == 15) result += 'F';
            else result += (n%convert)+48;
            n /= convert; 
        }
        reverse(full(result));
    }
    if(result.size() > 7) return "  ERROR";
    else{
        if(result.size() == 0) result += '0';
        ll space = 7 - result.size();
        reverse(full(result));
        while(space--) result += ' ';
        reverse(full(result));
        return result;
    }
}

int main(){

#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll base, convert; 
    string num;
    while(cin >> num >> base >> convert){
        while(num[0] == '0') iremove(num, 0);
        cout << solve(num, base, convert) << endl;
    }
    
#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}
