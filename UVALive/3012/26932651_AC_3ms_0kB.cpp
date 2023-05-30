/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;

#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
 
#define all(x)           x.begin(), x.end()
#define dot(x)           fixed << setprecision(x)
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
 
#define PI               acos(-1.0) //3.1415926535897932
#define LOG(b, x)        (log(x)/log(b))
#define EPS              (1e-7)

int digits(double n){
    return ceil(double(log10(abs(n)+EPS)));
}

int GCD(int a, int b){
    if (b == 0) return a;
    return GCD(b, a % b);
}

void AVG_1(int sum, int n){
    int z = abs(sum)/abs(n);
    int y = abs(n);
    int x = abs(sum) - (z*y);
    int gcd = GCD(x, y);
    x /= gcd;
    y /= gcd;
    int space = 0;
    if(sum < 0 or n < 0) space += 2;
    space += digits(z);
    space += (digits(abs(y)) - digits(abs(x)));
    while(space--){
        cout << ' ';
    }
    cout << x << endl;
    if(sum < 0 or n < 0){
        cout << "- ";
    }
    cout << z;
    int digit = digits(y);
    while(digit--){
        cout << '-';
    }
    cout << endl;
    space = 0;
    if(sum < 0 or n < 0) space += 2;
    space += digits(z);
    while(space--){
        cout << ' ';
    }
    cout << y << endl;
    return;
}

void AVG_2(int sum, int n){
    int gcd = GCD(sum, n), space = 0;
    sum /= gcd;
    n /= gcd;
    if(sum < 0 or n < 0) space += 2;
    space += (digits(abs(n)) - digits(abs(sum)));
    while(space--){
        cout << ' ';
    }
    cout << abs(sum) << endl;
    space = 0;
    if(sum < 0 or n < 0){
        space += 2;
        cout << "- ";
    }
    int digit = digits(abs(n));
    while(digit--){
        cout << '-';
    }
    cout << endl;
    while(space--){
        cout << ' ';
    }
    cout << abs(n) << endl;
    return;
}

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    int n, cn = 0;
    while(cin >> n and n){
        cout << "Case " << ++cn << ":" << endl;
        double sum = 0;
        for(int i = 0; i < n; i++){
            int value;
            cin >> value;
            sum += value;
        }
        if(abs(sum/n) > 1 and int(sum/n) != double(sum/n)) AVG_1(sum, n);
        else if(abs(sum/n) < 1 and int(sum/n) != double(sum/n)) AVG_2(sum, n);
        else{
            if((sum/n) < 0) cout << "- " << abs(sum/n) << endl;
            else cout << sum/n << endl;
        }
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}