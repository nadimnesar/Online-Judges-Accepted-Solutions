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
#define Log(b, x)        (log(x)/log(b))

void A(int n){
    for(int i = 1; i <= n; i++){
        if(i&1){
            if(i != n) cout << "sin(" << i << '-';
            else cout << "sin(" << i;
        }
        else{
            if(i != n) cout << "sin(" << i << '+';
            else cout << "sin(" << i;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ')';
    }
}


int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    int n;
    cin >> n;

    for(int i = 1; i < n; i++){
        cout << '(';
    }
    int j = n;
    for(int i = 1; i < n; i++){
        A(i);
        cout << '+' << j << ')';
        j--;
    }
    A(n);
    cout << "+1" << endl;

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}