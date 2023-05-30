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

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    int n, cn = 0;
    cin >> n;
    cin.ignore();
    while(n--){
        string org, newpass;
        cin >> org >> newpass;
        string caps, num, capsANDnum;
        int len = org.size();
        for(int i = 0; i < len; i++){
            if(org[i] >= 'a' and org[i] <= 'z'){
                caps += org[i]-32;
            }
            else if(org[i] >= 'A' and org[i] <= 'Z'){
                caps += org[i]+32;
            }
            else caps += org[i];
        }
        for(int i = 0; i < len; i++){
            if(org[i] >= 'a' and org[i] <= 'z'){
                num += org[i];
            }
            else if(org[i] >= 'A' and org[i] <= 'Z'){
                num += org[i];
            }
        }
        for(int i = 0; i < num.size(); i++){
            if(num[i] >= 'a' and num[i] <= 'z'){
                capsANDnum += num[i]-32;
            }
            else if(num[i] >= 'A' and num[i] <= 'Z'){
                capsANDnum += num[i]+32;
            }
        }
        cout << "Case " << ++cn << ": ";
        if(org == newpass) cout << "Login successful." << endl;
        else if(newpass == caps) cout << "Wrong password. Please, check your caps lock key." << endl;
        else if(newpass == num) cout << "Wrong password. Please, check your num lock key." << endl;
        else if(newpass == capsANDnum) cout << "Wrong password. Please, check your caps lock and num lock keys." << endl;
        else cout << "Wrong password." << endl;
    }
    

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
