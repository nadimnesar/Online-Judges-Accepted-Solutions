#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
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

int remainder(char *year, int mod){
    int base = 0;
    int r = 0;
    int i = 0;
    int len = strlen(year);
    while(base < mod){
        base = (base*10) + (year[i]-48);
        i++;
    }
    while(i < len+1){
        r = base%mod;
        base = (r*10) + (year[i]-48);
        if(mod > base and i < len-2){
            i++;
            base = (base*10) + (year[i]-48);
        }
        i++;
    }
    return r;
}

bool leap(char *year){
    if (remainder(year, 400) == 0) return true;
    if (remainder(year, 100) == 0) return false;
    if (remainder(year, 4) == 0) return true;
    return false;
}

bool huluculu(char *year){
    if(remainder(year, 15) == 0) return true;
    return false;
}

bool bulukulu(char *year){
    if(remainder(year, 55) == 0) return true;
    else return false;
}

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    char year[1000001];
    int bre = 0;
    while(scanf("%s", &year) != EOF){
        if(bre) printf("\n");
        else bre = 1;
        int any = 0;
        int leapdone = 0;
        if(leap(year)) { printf("This is leap year.\n"); any = 1; leapdone = 1; }
        if(huluculu(year)) { printf("This is huluculu festival year.\n"); any = 1; }
        if(bulukulu(year) and leapdone) { printf("This is bulukulu festival year.\n"); any = 1; }
        if(!any) printf("This is an ordinary year.\n");
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
