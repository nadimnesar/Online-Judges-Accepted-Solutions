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

int algo(int x)
{
    long long unsigned int d=0;
again:
    d++;
    if(x==1) return d;
    else if(x%2!=0)
        x=((3*x)+1);
    else x=x/2;
    goto again;
}
int main()
{
    long long unsigned int n, m;
    while(cin >> n >> m)
    {
        if(n==m)
        {
            cout << n << " " << m << " " << algo(n) << endl;
        }
        else if(n<m)
        {
            long long unsigned int maxi=1;
            for(int i=n; i<=m; i++)
            {
                if(algo(i)>maxi)
                    maxi=algo(i);
            }
            cout << n << " " << m << " " << maxi << endl;
        }
        else
        {
            long long unsigned int maxi=1;
            for(int i=n; i>=m; i--)
            {
                if(algo(i)>maxi)
                    maxi=algo(i);
            }
            cout << n << " " << m << " " << maxi << endl;
        }
    }
}