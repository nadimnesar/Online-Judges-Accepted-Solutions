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
 
int main() {
    
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;
 
    int low = 0, up = 0;
    string str;
    cin >> str;
    int len = str.size();
    for(int i = 0; i < len; i++){
        if(str[i] >= 'A' and str[i] <= 'Z'){
            up++;
        }
        else low++;
    }
    if(low >= up){
        for(int i = 0; i < len; i++){
            str[i] = tolower(str[i]);
        }
    }
    else{
        for(int i = 0; i < len; i++){
            str[i] = toupper(str[i]);
        }
    }
    cout << str << endl;

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}