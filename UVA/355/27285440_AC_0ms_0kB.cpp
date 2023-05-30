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

vector < char > readynum;

void decimaltoany(llu n, llu newbase){
    llu i = 0;
    while (n > 0){
        if(n%newbase == 10) readynum.pb('A');
        else if(n%newbase == 11) readynum.pb('B');
        else if(n%newbase == 12) readynum.pb('C');
        else if(n%newbase == 13) readynum.pb('D');
        else if(n%newbase == 14) readynum.pb('E');
        else if(n%newbase == 15) readynum.pb('F');
        else readynum.pb((n%newbase)+48);
        n /= newbase;
        i++;
    }
    if(readynum.size() == 0) readynum.pb('0');
    reverse(full(readynum));
    return;
}

bool legal(string num, llu base){
    bool yes = true;
    for(llu i = 0; num[i]; i++){
         if(num[i] == 'A'){
                if(10 >= base){
                    yes = false;
                    break;
                }
            }
            else if(num[i] == 'B'){
                if(11 >= base){
                    yes = false;
                    break;
                }
            }
            else if(num[i] == 'C'){
                if(12 >= base){
                    yes = false;
                    break;
                }
            }
            else if(num[i] == 'D'){
                if(13 >= base){
                    yes = false;
                    break;
                }
            }
            else if(num[i] == 'E'){
                if(14 >= base){
                    yes = false;
                    break;
                }
            }
            else if(num[i] == 'F'){
                if(15 >= base){
                    yes = false;
                    break;
                }
            }
            else{
                if(num[i]-48 >= base){
                    yes = false;
                    break;
                }
            }
    }
    if(yes) return true;
    else return false;
}

int main(){
 
    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    llu base, newbase;
    string num;
    while(cin >> base >> newbase >> num){
        if(!legal(num, base)){
            cout << num << " is an illegal base " << base << " number" << endl;
            continue;
        }
        llu num10base = 0;
        llu size = num.size()-1;
        for(llu i = 0, j = size; num[i] and j >= 0; i++, j--){
            if(num[i] == 'A'){
                num10base += (llu)(10*pow(base, j));
            }
            else if(num[i] == 'B'){
                num10base += (llu)(11*pow(base, j));
            }
            else if(num[i] == 'C'){
                num10base += (llu)(12*pow(base, j));
            }
            else if(num[i] == 'D'){
                num10base += (llu)(13*pow(base, j));
            }
            else if(num[i] == 'E'){
                num10base += (llu)(14*pow(base, j));
            }
            else if(num[i] == 'F'){
                num10base += (llu)(15*pow(base, j));
            }
            else num10base += (llu)((num[i]-48)*pow(base, j));
        }
        decimaltoany(num10base, newbase);
        cout << num << ' ' << "base " << base << " = ";
        for(llu i = 0; i < readynum.size(); i++){
            cout << readynum[i];
        }
        cout << " base " << newbase << endl;
        readynum.clear();
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
