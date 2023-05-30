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

map < string, int > x;

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    llu n;
    cin >> n;
    cin.ignore();
    while(n--){
        string str;
        getline(cin, str);
        bool remove = false;
        int strlen = str.size(); 
        for(int i = 0; i < strlen; i++){
            if(remove){
                str[i] = ' ';
            }
            if(str[i] == ' ' and !remove){
                str[i] = ' ';
                remove = true;
            }
        }
        while(str[str.size() - 1] == ' '){
            iremove(str, str.size() - 1);
        }
        x[str]++;
    }
    for (auto it = x.begin(); it != x.end(); ++it){
            cout << it->first << ' ' << it->second << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}