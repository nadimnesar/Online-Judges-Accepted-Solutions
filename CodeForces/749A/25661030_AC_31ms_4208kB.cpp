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
    ll n, limit;
    cin >> n;
    if(n%2!=0)
    {
        limit=(n/2);
        cout << limit << endl;
        for(int i=1; i<limit; i++)
        {
            cout << "2" << " ";
        }
        cout << "3" << endl;
    }
    else
    {
        limit=(n/2);
        cout << limit << endl;
        for(int i=1; i<=limit; i++)
        {
            if(i==limit)
                cout << "2" << endl;
            else cout << "2" << " ";
        }
    }
}