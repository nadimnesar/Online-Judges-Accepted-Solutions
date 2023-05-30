/*BISMILLAHIR RAHMANIR RAHIM*/
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

void HexToBin(string &str){
    ll i = 0;
    string hexa;
    while(str[i]){
        switch (str[i]){
        case '0':
            hexa += "0000";
            break;
        case '1':
            hexa += "0001";
            break;
        case '2':
            hexa += "0010";
            break;
        case '3':
            hexa += "0011";
            break;
        case '4':
            hexa += "0100";
            break;
        case '5':
            hexa += "0101";
            break;
        case '6':
            hexa += "0110";
            break;
        case '7':
            hexa += "0111";
            break;
        case '8':
            hexa += "1000";
            break;
        case '9':
            hexa += "1001";
            break;
        case 'A':
        case 'a':
            hexa += "1010";
            break;
        case 'B':
        case 'b':
            hexa += "1011";
            break;
        case 'C':
        case 'c':
            hexa += "1100";
            break;
        case 'D':
        case 'd':
            hexa += "1101";
            break;
        case 'E':
        case 'e':
            hexa += "1110";
            break;
        case 'F':
        case 'f':
            hexa += "1111";
            break; 
        }
        i++;
    }
    str = hexa;
}

ll setbits(string str){
    ll ones = 0;
    for(ll i = 0; str[i]; i++){
        if(str[i] == '1'){
            ones++;
        }
    }
    return ones;
}

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    ll t, cn = 0;
    cin >> t;
    cin.ignore();
    while(t--){
        string before, after;
        cin >> before >> after;
        HexToBin(before);
        HexToBin(after);
        reverse(full(after));
        reverse(full(before));
        while(before.size() != 32){
            before += '0';
        }
        while(after.size() != 32){
            after += '0';
        }
        reverse(full(after));
        reverse(full(before));
        cout << "Case #" << ++cn << ": ";
        if(setbits(after) != setbits(before)){
            cout << "Not possible" << endl;
            continue;
        }
        else if(before == after){
            cout << "0 Any" << endl;
            continue;
        }
        bool find = false;
        ll left = 0, right = 0;
        string temp = before;
        for(ll i = 1; i <= 32; i++){
            temp += temp[0];
            iremove(temp, 0);
            if(temp == after){
                left++;
                find = true;
                break;
            }
            left++;
        }
        temp = before;
        for(ll i = 1; i <= 32; i++){
            char ch = temp[31];
            reverse(full(temp));
            temp += ch;
            reverse(full(temp));
            iremove(temp, 32);
            if(temp == after){
                right++;
                find = true;
                break;
            }
            right++;
        }
        if(left == right and find){
            cout << left << ' ' << "Any" << endl;
        }
        else if(left > right and find){
            cout << right << ' ' << "Right" << endl;
        }
        else if(left < right and find) cout << left << ' ' << "Left" << endl;
        else cout << "Not possible" << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
