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
 
bool prime(llu n){
    if(n == 1) return false;
    else if(n == 2) return true;
    else if(n&1){
        for(llu i = 3; i*i <= n; i+=2){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    else return false;
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
    cin.ignore();
    string str, makedbyme;
    getline(cin, str);
    int op;
    cin >> op;
    cin.ignore();
 
    bool caplock = false;
    while(op--){
        string temp;
        getline(cin, temp);
        int len = temp.size();
        if(temp == "CapsLock"){
            caplock = !caplock;
        }
        else if(temp == "Backspace"){
            if(makedbyme.size() >= 1){
                makedbyme.pop_back();
            }
        }
        else if(temp == "Space"){
            makedbyme += ' ';
        }
        else{
            if(caplock){
                makedbyme += toupper(temp[0]);
            }
            else makedbyme += temp[0];
        }
    }
    if(makedbyme == str){
        cout << "Correct" << endl;
    }
    else cout << "Incorrect" << endl;
 
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}