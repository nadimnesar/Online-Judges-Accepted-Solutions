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
    ios_base::sync_with_stdio(0); cin.tie(0);
 
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
}