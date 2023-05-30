#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define ull             long long unsigned int
#define vll             vector< ll >
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define point(x)        fixed << setprecision(x)
#define PI              acos(-1.0) //3.1415926535897932
#define EPS             1e-9
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FastIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

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
    FastIO;
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
