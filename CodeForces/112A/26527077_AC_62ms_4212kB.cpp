/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll            long long int
#define llu           long long unsigned int
#define pb            push_back
#define inst          insert
#define all(x)        x.begin(), x.end()
#define dot(x)        fixed << setprecision(x)
#define fastIO        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define remove(x, y)  x.erase(remove(x.begin(), x.end(), b), x.end())
#define iremove(x, y) x.erase(x.begin() + y);
#define PI            acos(-1.0) //3.1415926535897932
#define Log(b, x)     (log(x)/log(b))
#define eps           (int)(1e-9)
#define MAX           (int)(1e9+1)
#define MOD           (int)(1e7+1)

int main() {
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    string s1;
    string s2;

    getline(cin, s1);
    getline(cin, s2);

    for (int i=0; i<s1.size(); i++)
        s1[i]=tolower(s1[i]);
    for (int i=0; i<s2.size(); i++)
        s2[i]=tolower(s2[i]);

    if(s1==s2)
        cout << "0" << endl;
    else if(s1<s2)
        cout << "-1" << endl;
    else if(s2<s1)
        cout << "1" << endl;
    
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
}