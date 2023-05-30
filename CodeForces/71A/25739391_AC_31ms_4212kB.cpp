#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define vi              vector< int >
#define vll             vector< ll >
#define vc              vector< char >
#define vs              vector< string >
#define pb              push_back
#define all(v)          v.begin(), v.end()
#define PI              acos(-1.0)  // 3.1415926535897932
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
 
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        ll len=a.length();
        if(len > 10)
        {
            cout << a[0];
            cout << len-2;
            cout << a[len-1];
            cout << endl;
        }
        else cout << a << endl;
    }
}