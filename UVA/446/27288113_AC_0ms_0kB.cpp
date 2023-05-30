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

ll hexadecimalToDecimal(string hexVal){
    ll len = hexVal.size();
    ll base = 1;
    ll dec_val = 0;
    for (ll i = len-1; i >= 0; i--){
        if (hexVal[i]>='0' && hexVal[i]<='9') 
        {
            dec_val += (hexVal[i] - 48)*base;
            base = base * 16; 
        }
        else if (hexVal[i]>='A' && hexVal[i]<='F') 
        {
            dec_val += (hexVal[i] - 55)*base; 
            base = base*16; 
        }
    }
    return dec_val;
}

string HexToBin(string hexdec){
    ll i = 0;
    string bin;
    while (hexdec[i]){
        switch (hexdec[i]){
        case '0': 
            bin += "0000"; 
            break; 
        case '1': 
            bin += "0001"; 
            break; 
        case '2': 
            bin += "0010"; 
            break; 
        case '3': 
            bin += "0011"; 
            break; 
        case '4': 
            bin += "0100"; 
            break; 
        case '5': 
            bin += "0101"; 
            break; 
        case '6': 
            bin += "0110"; 
            break; 
        case '7': 
            bin += "0111"; 
            break; 
        case '8': 
            bin += "1000"; 
            break; 
        case '9': 
            bin += "1001"; 
            break; 
        case 'A': 
            bin += "1010"; 
            break; 
        case 'B': 
            bin += "1011"; 
            break; 
        case 'C': 
            bin += "1100"; 
            break; 
        case 'D': 
            bin += "1101"; 
            break; 
        case 'E': 
            bin += "1110"; 
            break; 
        case 'F': 
            bin += "1111"; 
            break;
        }
        i++;
    }
    reverse(full(bin));
    while(bin.size() < 13) bin += '0';
    reverse(full(bin));
    return bin;
}

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
 
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        char op;
        string num1, num2;
        cin >> num1 >> op >> num2;
        ll n1 = hexadecimalToDecimal(num1);
        ll n2 = hexadecimalToDecimal(num2);
        num1 = HexToBin(num1);
        num2 = HexToBin(num2);
        if(op == '+') cout << num1 << ' ' << op << ' ' << num2 << " = " << (n1+n2) << endl;
        else cout << num1 << ' ' << op << ' ' << num2 << " = " << (n1-n2) << endl;
    }
 
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}