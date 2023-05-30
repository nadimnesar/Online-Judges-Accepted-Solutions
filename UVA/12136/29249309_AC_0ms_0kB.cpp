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

int main()
{

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    int t, cn = 0;
    cin >> t;
    cin.ignore();
    while(t--){
        string wife, meet;
        getline(cin, wife);
        getline(cin, meet);
        int wifeSH, wifeSM, wifeEH, wifeEM;
        stringstream sw(wife);
        char ch1, ch2;
        sw >> wifeSH >> ch1 >> wifeSM >> wifeEH >> ch2 >> wifeEM;
        int meetSH, meetSM, meetEH, meetEM;
        stringstream sm(meet);
        sm >> meetSH >> ch1 >> meetSM >> meetEH >> ch2 >> meetEM;

        cout << "Case " << ++cn << ": ";
        if(wifeSH > meetEH){
            cout << "Hits Meeting" << endl;
        }
        else if(wifeSH == meetEH){
            if(wifeSM > meetEM){
                cout << "Hits Meeting" << endl;
            }
            else cout << "Mrs Meeting" << endl;
        }
        else if(wifeEH < meetSH){
            cout << "Hits Meeting" << endl;
        }
        else if(wifeEH == meetSH){
            if(wifeEM < meetSM){
                cout << "Hits Meeting" << endl;
            }
            else cout << "Mrs Meeting" << endl;
        }
        else cout << "Mrs Meeting" << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
