#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define ist              insert
#define mp               make_pair
 
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

class Product
{
private:
    string c;
public:
 
    string Add(string a,string b)
    {
        c.clear();
        reverse(full(a));
        reverse(full(b));
        if(a.size() < b.size()) swap(a,b);
        while(b.size() < a.size()) b.pb('0');
        llu i = 0, carry = 0;
        while(a[i])
        {
            carry = carry + a[i]-48 + b[i]-48;
            c.pb((carry %10) + 48);
            carry = carry / 10;
            i++;
        }
        while(carry > 9)
        {
            c.pb((carry % 10) + 48);
            carry = carry / 10;
        }
        if(carry != 0) c.pb(carry + 48);
        reverse(full(c));
        return c;
    }
 
    string multiplication(string a, string b)
    {
        if(b.size() > a.size()){
            swap(a, b);
        }
        reverse(full(a));
        reverse(full(b));
        while(a.size() > b.size()){
            b.pb('0');
        }
        vector < string > x;
        for(llu i = 0; b[i]; i++)
        {
            llu carry = 0;
            string str;
            for(llu j = 0; a[j]; j++){
                str += ((((b[i]-48)*(a[j]-48))+carry)%10)+48;
                carry = (((b[i]-48)*(a[j]-48))+carry)/10;
            }
            if(carry > 0) str += carry + 48;
            reverse(full(str));
            long long unsigned int zero = i;
            while(zero--){
                str += '0';
            }
            x.pb(str);
        }
        llu len = x.size();
        if(len == 1) c = x[0];
        else{
            for(llu i = 0; i < len-1; i++){
                Product Int;
                x[i+1] = Int.Add(x[i], x[i+1]);
            }
        }
        c = x[len-1];
        return c;
    }
};
 
int main(){
 
    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
 
 
    Product Int;
    string a, str = "0";
    while(cin >> a){
        if(a == "0") break;
        str = Int.Add(str, a);
    }
    cout << str << endl;
 
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}