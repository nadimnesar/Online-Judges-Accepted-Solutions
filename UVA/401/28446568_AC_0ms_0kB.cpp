#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back

#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MAX              (10000007)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

bool mirror(string str){
    string copy;
    bool checker = true;
    for(ll i = 0; str[i]; i++){
        if(str[i] == 'A' or str[i] == '3' or str[i] == 'H'){
            if(str[i] == 'A') copy += 'A';
            if(str[i] == '3') copy += 'E';
            if(str[i] == 'H') copy += 'H';
        }
        else if(str[i] == 'I' or str[i] == 'L' or str[i] == 'J'){
            if(str[i] == 'I') copy += 'I';
            if(str[i] == 'L') copy += 'J';
            if(str[i] == 'J') copy += 'L';
        }
        else if(str[i] == 'M' or str[i] == 'O' or str[i] == '2'){
            if(str[i] == 'M') copy += 'M';
            if(str[i] == 'O') copy += 'O';
            if(str[i] == '2') copy += 'S';
        }
        else if(str[i] == 'T' or str[i] == 'U' or str[i] == 'V'){
            if(str[i] == 'T') copy += 'T';
            if(str[i] == 'U') copy += 'U';
            if(str[i] == 'V') copy += 'V';
        }
        else if(str[i] == 'W' or str[i] == 'X' or str[i] == 'Y'){
            if(str[i] == 'W') copy += 'W';
            if(str[i] == 'X') copy += 'X';
            if(str[i] == 'Y') copy += 'Y';
        }
        else if(str[i] == '5' or str[i] == '1' or str[i] == 'S'){
            if(str[i] == '5') copy += 'Z';
            if(str[i] == '1') copy += '1';
            if(str[i] == 'S') copy += '2';
        }
        else if(str[i] == 'E' or str[i] == 'Z' or str[i] == '8'){
            if(str[i] == 'E') copy += '3';
            if(str[i] == 'Z') copy += '5';
            if(str[i] == '8') copy += '8';
        }
        else{
            checker = false;
            break;
        }
    }
    reverse(full(copy));
    if(copy != str) checker = false;
    return checker;
}

bool palindrome(string str){
    string copy = str;
    reverse(full(copy));
    if(str == copy) return true;
    else return false;
}

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    string str;
    while(cin >> str){
        bool p = false, m = false;
        if(palindrome(str)) p = true;
        if(mirror(str)) m = true;
        if(p and m) cout << str << " -- is a mirrored palindrome." << endl << endl;
        else if(p and !m) cout << str << " -- is a regular palindrome." << endl << endl;
        else if(!p and m) cout << str << " -- is a mirrored string." << endl << endl;
        else cout << str << " -- is not a palindrome." << endl << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}