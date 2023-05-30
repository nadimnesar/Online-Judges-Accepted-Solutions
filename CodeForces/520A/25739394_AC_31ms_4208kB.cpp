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
#define EPS             1e-9
#define INF             (1<<30)
#define MOD             10007
#define SIZ             1005
 
int main()
{
    ll n, c=0;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    for(int i=0; i<n; i++)
    {
        s[i]=tolower(s[i]);
    }
    for(int j=97; j<=122; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(s[i]==j)
            {
                c++;
                break;
            }
            else continue;
        }
    }
    if(c==26)
        YES;
    else NO;
}